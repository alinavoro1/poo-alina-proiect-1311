//
// Created by avoro on 4/30/2025.
//

#include "SortItems.h"

SortItems::SortItems():
    PowerUp(2, "You can press the key s while playing and the items on the aisle will be sorted in ascending order to help you get the cheapest products!\n", "s") {}

SortItems::~SortItems() = default;

SortItems::SortItems(const SortItems &other): PowerUp(other) {}

PowerUp * SortItems::clone() const {
    return new SortItems(*this);
}

SortItems & SortItems::operator=(const SortItems &other) {
    PowerUp::operator=(other);
    return *this;
}

void SortItems::showInfo(const std::string &reply) {
    if (reply == "y" or reply == "Y") {
        afis(std::cout);
    }
    else if (reply == "n" or reply == "N") {
        std::cout << "ook.. \n";
    }
}

void SortItems::activateAislePower(Raion &raionCrt, int strk) {
    if (raionCrt.getItems().empty()) {
        throw RaionGol("Can not sort Items in the Aisle");
    }
    if (!canBeUsed(strk)) {
        throw EroarePowerUp("The win streak is too low to apply this Power-Up");
    }
    raionCrt.sorteazaProduse();
    std::cout<< raionCrt;
}

std::string SortItems::Name() const {
    return "Sort Items Power-Up. ";
}
