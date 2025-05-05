//
// Created by avoro on 4/23/2025.
//

#ifndef RAION_H
#define RAION_H
#include <string>
#include <tabulate.hpp>
#include <vector>

#include "AppExceptions.h"
#include "Item.h"
#include "Lista.h"

class Raion: public Lista {
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
};
#endif //RAION_H
