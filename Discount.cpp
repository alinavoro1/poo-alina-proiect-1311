//
// Created by avoro on 4/30/2025.
//

#include "Discount.h"

Discount::Discount(int percentage_):
    PowerUp(3, "You can press the key d while playing and the discount will be applied to all the items on the aisle\n", "d"),
    percentage(percentage_) {}

Discount::~Discount() = default;

Discount::Discount(const Discount &other): PowerUp(other), percentage(other.percentage) {}

PowerUp * Discount::clone() const {
    return new Discount(*this);
}

Discount & Discount::operator=(const Discount &other) {

    PowerUp::operator=(other);
    percentage = other.percentage;
    return *this;
}

void Discount::calculatePercentage(int currentStreak) {
    percentage = (currentStreak - winStreakRequired+1)* 10;
}

void Discount::activateAislePower(Raion &raionCrt, int strk) {
    calculatePercentage(strk);
    raionCrt.aplicaReducere(percentage);
    std::cout << raionCrt;
}

void Discount::showInfo(const std::string &reply) {
    if (reply == "y" or reply == "Y") {
        afis(std::cout);
    }
    else if (reply == "n" or reply == "N") {
        std::cout << "ook.. \n";
    }
}

std::string Discount::Name() const {
    return "Discount Power-Up. ";
}
