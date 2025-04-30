//
// Created by avoro on 4/30/2025.
//

#ifndef DISCOUNT_H
#define DISCOUNT_H
#include <iostream>

#include "PowerUp.h"



class Discount: public PowerUp {
    int percentage;
public:
    explicit Discount (int percentage_):
    PowerUp(3, "You can press the key d while playing\n and the discount will be applied to all the items on the aisle\n", "d"),
    percentage(percentage_) {}

    ~Discount() = default;

    Discount(const Discount &other): PowerUp(other), percentage(other.percentage) {}

    Discount & operator=(const Discount &other) {
        PowerUp::operator=(other);
        percentage = other.percentage;
        return *this;
    }

    void calculatePercentage(int currentStreak) {
        percentage = (currentStreak - winStreakRequired)* 10;
    }

    void activateAislePower(Raion& raionCrt) override {
        raionCrt.aplicaReducere(percentage);
        std::cout << raionCrt;
    };


    void showInfo() override {
        std::cout<< description << "\n";
    }

};



#endif //DISCOUNT_H
