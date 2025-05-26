//
// Created by avoro on 4/23/2025.
//

#ifndef MAGAZIN_H
#define MAGAZIN_H
#include <set>
#include <vector>
#include <random>

#include "../utils/AppExceptions.h"
#include "listaCumparaturi.h"
#include "Raion.h"

class Magazin {
    std::vector <Raion> raioane;
public:
    explicit Magazin(const std::vector<Raion> &raioane_);

    Magazin();

    ~Magazin();

    Magazin(const Magazin &other);

    Magazin & operator=(const Magazin &other);

    friend std::ostream& operator<<(std::ostream& os, const Magazin& magazin);

    const std::vector<Raion> & getRaioane() const;

    listaCumparaturi genereazaListaCumparaturi() const;
};

#endif //MAGAZIN_H
