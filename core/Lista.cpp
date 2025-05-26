//
// Created by avoro on 4/23/2025.
//

#include "Lista.h"

Lista::Lista() = default;

Lista::Lista(const std::vector<Item> &items_): items(items_) {}

Lista::Lista(const Lista &other): items(other.items) {}

Lista::~Lista() = default;

const std::vector<Item> & Lista::getItems() const {
    return items;
}

Lista & Lista::operator=(const Lista &other) {
    if (this != &other) {
        items = other.items;
    }
    return *this;
}
