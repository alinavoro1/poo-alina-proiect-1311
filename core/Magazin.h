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

    explicit Magazin(const std::vector<Raion> &raioane_);

    Magazin();

    ~Magazin();

    friend std::ostream& operator<<(std::ostream& os, const Magazin& magazin);


    static void build() ;
public:

    Magazin(const Magazin &other) = delete;

    Magazin & operator=(const Magazin &other) = delete;

    static Magazin& getInstance() {
        static Magazin magazin;
        return magazin;
    };

    listaCumparaturi genereazaListaCumparaturi() const;

    const std::vector<Raion> & getRaioane() const;

};

#endif //MAGAZIN_H
