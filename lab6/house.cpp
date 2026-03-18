//
// Created by Mmiud on 9/9/2025.
//

#include "house.h"
#include <iostream>


std::ostream &operator<<(std::ostream &out, const House &hs) {
    out << "Address: " << hs.address << " size: " << hs.size << " price: " << hs.price;
    return out;
}

House::House(const std::string &newAddress, const double newSize, const double newPrice) : address(newAddress), size(newSize), price(newPrice) {
}

void House::setAddress(const std::string &newAddress) {
    address = newAddress;
}

std::string House::getAddress() const{
    return address;
}

void House::setArea(const double newArea) {
    size = newArea;
}

void House::setPrice(const double newPrice) {
    price = newPrice;
}

bool House::operator<(const House &hs) const {
    return (price / size) < (hs.price / hs.size);
}

// Apartment
Apartment::Apartment(const House& newApartment, const int number, const double size, const double apRent) :
    rentalHouse(std::make_shared<House>(newApartment)), apartmentNr(number), apartmentSize(size), rent(apRent) {

}

bool Apartment::operator<(const Apartment &ap) const {
    return rent < ap.rent;
}

void Apartment::printInfo() const {
    std::cout << "Address: " << rentalHouse->getAddress();
    std::cout << ", apartment number: " << apartmentNr;
    std::cout << ", size: " << apartmentSize << "m2";
    std::cout << ", rent: " << rent << " euros/month";
 }
