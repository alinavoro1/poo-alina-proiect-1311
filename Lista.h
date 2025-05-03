//
// Created by avoro on 4/23/2025.
//

#ifndef LISTA_H
#define LISTA_H
#include <algorithm>
#include <vector>

#include "Item.h"
class Lista {
protected:
    std::vector<Item> items;

public:
    Lista() = default;

    explicit Lista(const std::vector<Item>& items_) : items(items_) {}

    Lista(const Lista& other): items(other.items) {}


    ~Lista() = default;

    void calculTotal() {};

    const std::vector<Item>& getItems() const {
        return items;
    }

    Lista& operator=(const Lista& other) {
        if (this != &other) {
            items = other.items;
        }
        return *this;
    }

};

#endif //LISTA_H
