//
// Created by avoro on 4/4/2025.
//

#ifndef COSCUMPARATURI_H
#define COSCUMPARATURI_H
#include "listaCumparaturi.h"


class cosCumparaturi {
    listaCumparaturi lista;
    std::vector <Item> items;
    double totalPlata;
public:
    cosCumparaturi(const listaCumparaturi &lista_, const std::vector<Item> &items_, double totalPlata_ = 0.0);

    cosCumparaturi(const cosCumparaturi &other);

    explicit cosCumparaturi( double totalPlata_ );

    cosCumparaturi& operator=(const cosCumparaturi &other);

    double getTotalPlata() const;

    const listaCumparaturi& getLista() const;

    const std::vector<Item>& getItems() const;

    ~cosCumparaturi();

    friend std::ostream& operator<<(std::ostream& os, const cosCumparaturi& cos);

    void sumadinCos();

    void adaugaInCos(const Item &item);
};


#endif //COSCUMPARATURI_H
