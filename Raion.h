//
// Created by avoro on 4/23/2025.
//

#ifndef RAION_H
#define RAION_H
#include <string>
#include <tabulate.hpp>
#include <vector>

#include "Item.h"


class Raion {
    std::string name;
    std::vector<Item> items;
public:
    Raion(const std::string& name_,const std::vector <Item>& Item_);

    Raion(const Raion&  other);

    const std::string& getName() const;

    Raion& operator=(const Raion& other);

    ~Raion();

    friend std::ostream & operator<<(std::ostream &os, const Raion &obj);


    const std::vector <Item>& getItems() const;
};



#endif //RAION_H
