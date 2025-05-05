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
    explicit Discount (int percentage_);

    ~Discount() override;

    Discount(const Discount &other);

    PowerUp* clone()const override;

    Discount & operator=(const Discount &other);

    void calculatePercentage(int currentStreak);

    void activateAislePower(Raion& raionCrt, int strk) override;


    void showInfo(const std::string& reply) override;

    std::string Name()  const override;
};



#endif //DISCOUNT_H
