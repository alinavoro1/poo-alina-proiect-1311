//
// Created by avoro on 4/4/2025.
//

#include "Item.h"

Item::Item(): pret(0.0) {}

Item::Item(const std::string &name_, const std::string &brand_): name(name_), pret{0.0}, brand{brand_} {}

Item::Item(const std::string &name_, double pret_, const std::string &brand_): name{name_}, pret{pret_}, brand{brand_} {}

Item::Item(const Item &other): name{other.name}, pret{other.pret}, brand{other.brand} {}

const std::string & Item::getName() const { return this->name;}

double Item::getPret() const { return this->pret;}

Item & Item::operator=(const Item &other) {
    this->name = other.name;
    this->pret = other.pret;
    this->brand = other.brand;
    // std::cout <<"op=\n";
    return *this;
}

Item::~Item() = default;

bool Item::operator==(const Item &other) const {
    return name == other.name && pret == other.pret && brand == other.brand;
}

std::ostream & operator<<(std::ostream &os, const Item &item) {
    os<< item.name << "~" << item.brand << " ($" << item.pret << ")";
    return os;
}
