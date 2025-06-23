//
// Created by avoro on 4/23/2025.
//

#ifndef MAGAZIN_H
#define MAGAZIN_H
#include <set>
#include <vector>
#include <random>
#include "../core/Singleton.h"

#include "../utils/AppExceptions.h"
#include "listaCumparaturi.h"
#include "Raion.h"

class Magazin: public Singleton<Magazin> {
    std::vector <Raion> raioane;

    explicit Magazin(const std::vector<Raion> &raioane_);

    Magazin();

    ~Magazin();

    friend std::ostream& operator<<(std::ostream& os, const Magazin& magazin);


    static void build() ;

    template<class T>
    friend class Singleton;

public:

    listaCumparaturi genereazaListaCumparaturi() const;

    const std::vector<Raion> & getRaioane() const;

};

#endif //MAGAZIN_H
