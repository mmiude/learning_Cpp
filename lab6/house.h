//
// Created by Mmiud on 9/9/2025.
//
#pragma once
#include <memory>
#include <string>

#ifndef HOUSE_H
#define HOUSE_H



class House {
    friend std::ostream &operator<<(std::ostream &out, const House &hs);
public:
    House(const std::string &newAddress, double newSize, double newPrice);
    void setAddress(const std::string &newAddress);
    std::string getAddress() const;
    void setArea(double newArea);
    void setPrice(double newPrice);
    bool operator<(const House &hs) const;

private:
    std::string address;
    double size;
    double price;
};

class Apartment {
public:
    Apartment( const House& newApartment, int number, double size, double apRent);
    bool operator<(const Apartment &ap) const;
    void printInfo() const;

private:
    std::shared_ptr<House> rentalHouse;
    int apartmentNr;
    double apartmentSize;
    double rent;
};


#endif //HOUSE_H
