//
// Created by avoro on 4/4/2025.
//

#ifndef MAGAZIN_H
#define MAGAZIN_H
#include <set>
#include <vector>
#include <random>

#include "listaCumparaturi.h"
#include "Raion.h"


class Magazin {
    std::vector<Raion> raioane;
public:
    explicit Magazin(const std::vector<Raion> &raioane_);

    Magazin();

    ~Magazin();

    Magazin(const Magazin &other);

    Magazin & operator=(const Magazin &other);

    friend std::ostream& operator<<(std::ostream& os, const Magazin& magazin);

    const std::vector <Raion>& getRaioane() const;
};
listaCumparaturi listGenerator(const Magazin& magazin);

#endif //MAGAZIN_H
