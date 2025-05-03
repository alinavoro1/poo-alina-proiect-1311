//
// Created by avoro on 4/30/2025.
//

#ifndef SORTITEMS_H
#define SORTITEMS_H
#include "PowerUp.h"

//SA NU UIT SA SCHIMB STREAKUL LA 2. L-AM SCHIMBAT CA SA VERIFIC FUNCTIONALITATEA CORECTA

class SortItems: public PowerUp {
public:
    SortItems():
    PowerUp(2, "You can press the key s while playing and the items on the aisle will be sorted in ascending order to help you get the cheapest products!\n", "s")
    {}

    ~SortItems()override = default;

    SortItems(const SortItems& other): PowerUp(other) {}

    PowerUp* clone() const override {
        return new SortItems(*this);
    }

    SortItems& operator=(const SortItems& other) {
        PowerUp::operator=(other);
        return *this;
    }

    void showInfo(const std::string& reply) override {
        if (reply == "y" or reply == "Y") {
            afis(std::cout);
        }
        else if (reply == "n" or reply == "N") {
            std::cout << "ook.. \n";
        }
    }

    void activateAislePower(Raion& raionCrt,int strk) override {
        raionCrt.sorteazaProduse();
        std::cout<<"old streak " <<strk;
        std::cout<< raionCrt;
    }

    std::string Name() const override {
        return " Sort Items PowerUp. ";
    }

};



#endif //SORTITEMS_H
