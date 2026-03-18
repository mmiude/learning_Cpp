#include <iostream>
#include <sstream>
#include "item_class.h"

Item::Item(std::string itemName, int itemWeight, double itemPrice, int itemAvailable) :
           name(itemName), weight(itemWeight), price(itemPrice), available(itemAvailable){

}

std::istream &operator>>(std::istream &in, Item &it){
    std::string line;

    in >> std::ws;
    if (in.get() != '{') {
        in.setstate(std::ios::failbit);
        return in;
    }
    //check key "Name" and save the value
    getline(in >> std::ws, line, ':');
    if (line != R"("Name")") in.setstate(std::ios::failbit);
    in.get(); // gets "
    getline(in, it.name, '"');
    //check key "Weight" and save the value
    in.get();
    getline(in >> std::ws, line, ':');
    if (line != R"("Weight")") in.setstate(std::ios::failbit);
    in >> it.weight;
    //check key "Price" and save the value
    in.get();
    getline(in >> std::ws, line, ':');
    if (line != R"("Price")") in.setstate(std::ios::failbit);
    in >> it.price;
    //check key "Count" and save the value
    in.get();
    getline(in >> std::ws, line, ':');
    if (line != R"("Count")") in.setstate(std::ios::failbit);
    in >> it.available;
    //check end of stream and last character is }
    in >> std::ws;
    if ((in.eof()) || in.get() != '}') in.setstate(std::ios::failbit);

    return in;
}

std::ostream &operator<<(std::ostream &out, Item &it){
  out << R"({ "Name":")" << it.name << R"(", "Weight":)" << it.weight << R"(, "Price":)" << it.price << R"(, "Count":)" << it.available << " }";
  return out;
}

bool Item::operator<(const Item &lhs) const {
    return ((price / weight * 1000) < (lhs.price / lhs.weight * 1000));
}

int Item::getCount() const {
    return available;
}

void Item::setCount(int newCount) {
    available = newCount;
}

double Item::getPrice() const {
    return price;
}
void Item::setPrice(double newPrice) {
    price = newPrice;
}
