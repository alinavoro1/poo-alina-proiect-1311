//
// Created by avoro on 4/23/2025.
//

#ifndef LISTACUMPARATURI_H
#define LISTACUMPARATURI_H
#include <algorithm>
#include <cmath>
#include <vector>

#include "Item.h"
#include "Lista.h"

class listaCumparaturi {
    std::vector<Item> items;
    int buget;
public:
    listaCumparaturi();

    explicit listaCumparaturi(const std::vector<Item>& items_, int buget_ = 0);

    explicit listaCumparaturi(int buget_);

    listaCumparaturi(const listaCumparaturi& other);

    listaCumparaturi& operator=(const listaCumparaturi& other);

    int getBuget() const;

    ~listaCumparaturi();

    friend std::ostream& operator<<(std::ostream& os, const listaCumparaturi& lista);

    void stergeProdus(const Item& item);

    void calculTotal();

    const std::vector<Item>& getItems() const;
};

#endif //LISTACUMPARATURI_H
