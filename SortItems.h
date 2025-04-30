//
// Created by avoro on 4/30/2025.
//

#ifndef SORTITEMS_H
#define SORTITEMS_H
#include "PowerUp.h"


class SortItems: public PowerUp {
public:
    SortItems():
    PowerUp(2, "You can press the key s while playing\n and the items on the aisle will be sorted in ascending order \nto help you get the cheapest products!\n", "s")
    {}

    ~SortItems() = default;

    SortItems(const SortItems& other): PowerUp(other) {}

    SortItems& operator=(const SortItems& other) {
        PowerUp::operator=(other);
        return *this;
    }

    void showInfo() override {
        std::cout<< description << "\n";
    }

    void activateAislePower(Raion& raionCrt) override {
        raionCrt.sorteazaProduse();
        std::cout<< raionCrt;
    }


};



#endif //SORTITEMS_H
