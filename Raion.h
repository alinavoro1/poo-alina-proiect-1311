//
// Created by avoro on 4/4/2025.
//

#ifndef RAION_H
#define RAION_H
#include <iomanip>
#include <string>
#include <vector>

#include "Item.h"


class Raion {
private:
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
