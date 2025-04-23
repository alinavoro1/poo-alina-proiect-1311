//
// Created by avoro on 4/23/2025.
//

#ifndef LISTACUMPARATURI_H
#define LISTACUMPARATURI_H
#include <algorithm>
#include <cmath>
#include <vector>

#include "Item.h"


class listaCumparaturi {
    std::vector <Item> items;
    int buget;
public:
    listaCumparaturi();
    explicit listaCumparaturi(const std::vector <Item>& items_, int buget_ = 0);
    listaCumparaturi(const listaCumparaturi& other);

    //operator =
    listaCumparaturi& operator=(const listaCumparaturi& other);

    const std::vector<Item>& getItems() const;

    int getBuget() const;

    ~listaCumparaturi();

    friend std::ostream& operator<<(std::ostream& os, const listaCumparaturi& lista);

    void calculeazaBuget(listaCumparaturi& lista);

    void stergeProdus(const Item& item);
};


#endif //LISTACUMPARATURI_H
