//
// Created by avoro on 4/30/2025.
//

#include "BonusTime.h"

BonusTime::BonusTime(int bonus_): PowerUp(4, "You can press the key t while playing\n and you will get 30s bonus on your timer\n", "t"),bonus(bonus_) {}

BonusTime::~BonusTime() = default;

BonusTime::BonusTime(const BonusTime &other): PowerUp(other) {}

PowerUp * BonusTime::clone() const {
    return new BonusTime(*this);
}

BonusTime & BonusTime::operator=(const BonusTime &other) {
    PowerUp::operator=(other);
    bonus = other.bonus;
    return *this;
}

void BonusTime::showInfo(const std::string &reply) {
    if (reply == "y" or reply == "Y") {
        afis(std::cout);
    }
    else if (reply == "n" or reply == "N") {
        std::cout << "ook.. \n";
    }
}

void BonusTime::activateTimePower(int &t) {
    t = t + bonus;
    std::cout << "time remaining: " << t << "\n";
}

std::string BonusTime::Name() const {
    return "Bonus Time Power-Up. ";
}
