//
// Created by avoro on 4/23/2025.
//

#ifndef MAGAZIN_H
#define MAGAZIN_H
#include <set>
#include <vector>
#include <random>

#include "AppExceptions.h"
#include "listaCumparaturi.h"
#include "Raion.h"

class Magazin {
    std::vector <Raion> raioane;
public:
    explicit Magazin(const std::vector<Raion> &raioane_): raioane(raioane_) {
    }

    Magazin() {}

    ~Magazin() = default;

    Magazin(const Magazin &other): raioane(other.raioane) {
    }

    Magazin & operator=(const Magazin &other) {
        if (this == &other)
            return *this;
        raioane = other.raioane;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Magazin& magazin) {
        os << "raioane: ";
        for (const auto& items : magazin.raioane) {
            os << items << ", ";
        }
        os << "\n";
        return os;
    }

    const std::vector<Raion> & getRaioane() const  { return this->raioane;}

    listaCumparaturi genereazaListaCumparaturi() const {
        std::set<std::string> produse;
        std::vector<Item> listaMea;

        for (const Raion& r : raioane) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::vector<Item> produseleRndm = r.getItems();
            //exceptie in cazul in care un raion este gol
            if (produseleRndm.empty()) {
                throw RaionGol("Raionul " + r.getName() + " este gol.");
            }

            std::shuffle(produseleRndm.begin(), produseleRndm.end(), gen);

            std::uniform_int_distribution<int> dist(0, 3);
            int numItems = std::min(dist(gen), (int)produseleRndm.size());

            for (int i = 0; i < numItems; ++i) {
                if (produseleRndm[i].getPret() < 0) {
                    std::string msg;
                    msg = " is the invalid price for the " + produseleRndm[i].getName();
                    throw PretInvalid(produseleRndm[i].getPret(), msg);
                }
                if (produse.insert(produseleRndm[i].getName()).second) {
                    listaMea.push_back(produseleRndm[i]);
                }
            }
        }

        return listaCumparaturi(listaMea);
    }
};

#endif //MAGAZIN_H
