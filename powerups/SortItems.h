//
// Created by avoro on 4/30/2025.
//

#ifndef SORTITEMS_H
#define SORTITEMS_H
#include "../utils/AppExceptions.h"
#include "PowerUp.h"

//SA NU UIT SA SCHIMB STREAKUL LA 2. L-AM SCHIMBAT CA SA VERIFIC FUNCTIONALITATEA CORECTA

class SortItems: public PowerUp {
public:
    SortItems();

    ~SortItems()override;

    SortItems(const SortItems& other);

    PowerUp* clone() const override;

    SortItems& operator=(const SortItems& other);

    void showInfo(const std::string& reply) override;

    void activateAislePower(Raion& raionCrt,int strk) override;

    std::string Name() const override;
};



#endif //SORTITEMS_H
