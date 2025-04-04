//
// Created by avoro on 4/4/2025.
//

#include "Raion.h"

Raion::Raion(const std::string &name_, const std::vector<Item> &Item_): name{name_}, items{Item_} {}

Raion::Raion(const Raion &other): name{other.name}, items{other.items} {}

const std::string & Raion::getName() const { return name;}

Raion & Raion::operator=(const Raion &other) {
    name = other.name;
    items = other.items;
    return *this;
}

Raion::~Raion() = default;

const std::vector<Item> & Raion::getItems() const { return items;}

std::ostream & operator<<(std::ostream &os, const Raion &obj) {
    os<< "name: " << obj.name<< "\n";
    size_t n = obj.items.size();
    for (size_t i = 0; i < n; i++) {
        os <<"["<< i << "] --> "<< obj.items[i]<< std::right << std::setw(20) ; //
        if (i + 1 < n) {
            os << " | "<<"["<< i+1 << "] --> " << obj.items[i + 1] << std::right << std::setw(20);
            i++;
        }
        os << "\n";
    }
    return os;
}
