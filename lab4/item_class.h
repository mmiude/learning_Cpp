
#ifndef ITEM_CLASS_H
#define ITEM_CLASS_H


class Item {
  friend std::istream &operator>>(std::istream &in, Item &it);
  friend std::ostream &operator<<(std::ostream &out, Item &it);

  public:
    explicit Item(std::string itemName = "", int itemWeight = 0, double itemPrice = 0.0, int itemAvailable = 0);
    bool operator<(const Item &lhs) const;
    int getCount() const;
    void setCount(int newCount);
    double getPrice() const;
    void setPrice(double newPrice);

  private:
    std::string name;
    int weight;
    double price;
    int available;
};

#endif //ITEM_CLASS_H
