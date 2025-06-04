//
// Created by avoro on 4/23/2025.
//

#ifndef RAION_H
#define RAION_H
#include <string>
#include <../ext/include/tabulate.hpp>
#include <vector>

#include "../utils/AppExceptions.h"
#include "Item.h"
#include "Lista.h"

class Raion{
    std::vector<Item> items;
    std::string name;
public:
    Raion(const std::string& name_,const std::vector <Item>& items_);

    Raion(const Raion&  other);

    const std::string& getName() const;

    Raion& operator=(const Raion& other);

    ~Raion();

    friend std::ostream & operator<<(std::ostream &os, const Raion& raion);

    void aplicaReducere(double discount);

    void sorteazaProduse();

    std::vector<Item> getItems() const;
};
#endif //RAION_H
