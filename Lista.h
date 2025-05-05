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
    Lista();

    explicit Lista(const std::vector<Item>& items_);

    Lista(const Lista& other);


    ~Lista();

    const std::vector<Item>& getItems() const;

    Lista& operator=(const Lista& other);
};

#endif //LISTA_H
