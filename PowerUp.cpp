//
// Created by avoro on 4/30/2025.
//

#include "PowerUp.h"

PowerUp::PowerUp(int winStreak_, const std::string &description_, const std::string &key_): winStreakRequired(winStreak_), description(description_), key(key_) {}

PowerUp::~PowerUp() = default;

PowerUp::PowerUp(const PowerUp &other): winStreakRequired(other.winStreakRequired),  description(other.description), key(other.key) {
}

PowerUp & PowerUp::operator=(const PowerUp &other) {
    if (this == &other)
        return *this;
    winStreakRequired = other.winStreakRequired;
    description = other.description;
    key = other.key;
    return *this;
}

bool PowerUp::canBeUsed(int currentStreak) const {
    if (currentStreak>=winStreakRequired) {
        return true;
    }
    return false;
}

bool PowerUp::verifyKey(const std::string &inp) {
    if (key == inp) {
        return true;
    }
    return false;
}

void PowerUp::activateAislePower(Raion &raionCrt, int strk) {
    std::cout << "No powerup activated";
    std::cout<<raionCrt<< strk;
}

void PowerUp::activateTimePower(int &t, Stopwatch& sw) {
    std::cout << "no powerup activated";
    std::cout << "Time remaining: "<< t-sw.elapsed() << "\n";
}

std::ostream & PowerUp::afis(std::ostream &os) const {
    os<< description;
    os<< "activation key: " <<key<< "; (win streak required: "<<winStreakRequired<<")\n";
    return os;
}

std::ostream & operator<<(std::ostream &os, const PowerUp &obj) {
    return obj.afis(os);
}
