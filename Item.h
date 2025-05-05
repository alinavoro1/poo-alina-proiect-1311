//
// Created by avoro on 4/23/2025.
//

#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>


class Item {
    std::string name;
    double pret;
    std::string brand;
public:
    Item();
    Item(const std::string& name_,const std::string& brand_);
    Item(const std::string& name_,double pret_,const std::string& brand_);
    Item(const Item& other);

    const std::string& getName() const;
    double getPret() const;

    //operator =
    Item& operator=(const Item& other);

    ~Item();

    friend std::ostream& operator<<(std::ostream& os, const Item& item);

    bool operator==(const Item& other) const;

    void aplicaDiscount(double procent);
};



#endif //ITEM_H
