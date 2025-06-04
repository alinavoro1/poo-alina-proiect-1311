//
// Created by avoro on 4/23/2025.
//

#ifndef COSCUMPARATURI_H
#define COSCUMPARATURI_H
#include "../utils/AppExceptions.h"
#include "Item.h"
#include "listaCumparaturi.h"

class cosCumparaturi{
    std::vector<Item> items;
    listaCumparaturi lista;
    double totalPlata;
public:
    cosCumparaturi(const listaCumparaturi &lista_, const std::vector<Item> &items_, double totalPlata_ = 0.0);

    cosCumparaturi(const cosCumparaturi &other);

    explicit cosCumparaturi( double totalPlata_ = 0.0 );

    cosCumparaturi& operator=(const cosCumparaturi &other);

    double getTotalPlata() const;

    const listaCumparaturi& getLista() const;

    ~cosCumparaturi();

    friend std::ostream& operator<<(std::ostream& os, const cosCumparaturi& cos);

    void calculTotal();

    void adaugaInCos(const Item &item);

    std::vector<Item> getItems() const;
};

#endif //COSCUMPARATURI_H
