//
// Created by avoro on 4/23/2025.
//

#include "Magazin.h"

Magazin::Magazin(const std::vector<Raion> &raioane_): raioane(raioane_) {
}

Magazin::Magazin() {}

Magazin::~Magazin() = default;

Magazin::Magazin(const Magazin &other): raioane(other.raioane) {
}

Magazin & Magazin::operator=(const Magazin &other) {
    if (this == &other)
        return *this;
    raioane = other.raioane;
    return *this;
}

const std::vector<Raion> & Magazin::getRaioane() const { return this->raioane;}

std::ostream & operator<<(std::ostream &os, const Magazin &magazin) {
    os << "raioane: ";
    for (const auto& items : magazin.raioane) {
        os << items << ", ";
    }
    os << "\n";
    return os;
}
