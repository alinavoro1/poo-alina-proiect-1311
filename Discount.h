//
// Created by avoro on 4/30/2025.
//

#ifndef DISCOUNT_H
#define DISCOUNT_H
#include <iostream>

#include "PowerUp.h"


//SA NU UIT SA SCHIMB STREAKUL LA 3. L-AM SCHIMBAT CA SA VERIFIC FUNCTIONALITATEA CORECTA

class Discount: public PowerUp {
    int percentage;
public:
    explicit Discount (int percentage_):
    PowerUp(3, "You can press the key d while playing and the discount will be applied to all the items on the aisle\n", "d"),
    percentage(percentage_) {}

    ~Discount() override = default;

    Discount(const Discount &other): PowerUp(other), percentage(other.percentage) {}
    PowerUp* clone()const override {
        return new Discount(*this);
    }
    Discount & operator=(const Discount &other) {

        PowerUp::operator=(other);
        percentage = other.percentage;
        return *this;
    }

    void calculatePercentage(int currentStreak) {
        percentage = (currentStreak - winStreakRequired+1)* 10;
    }

    void activateAislePower(Raion& raionCrt, int strk) override {
        calculatePercentage(strk);
        raionCrt.aplicaReducere(percentage);
        std::cout << raionCrt;
    };


    void showInfo(const std::string& reply) override {
        if (reply == "y" or reply == "Y") {
            afis(std::cout);
        }
        else if (reply == "n" or reply == "N") {
            std::cout << "ook.. \n";
        }
    }

    std::string Name()  const override {
        return " Discount PowerUp. ";
    }
};



#endif //DISCOUNT_H
