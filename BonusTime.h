//
// Created by avoro on 4/30/2025.
//

#ifndef BONUSTIME_H
#define BONUSTIME_H
#include "PowerUp.h"

//SA NU UIT SA SCHIMB STREAKUL LA 4. L-AM SCHIMBAT CA SA VERIFIC FUNCTIONALITATEA CORECTA
class BonusTime: public PowerUp {
    int bonus = 30; //se adauga 30s la timp
public:
    explicit BonusTime(int bonus_): PowerUp(1, "You can press the key t while playing\n and you will get 30s bonus on your timer\n", "t"),bonus(bonus_){}
    ~BonusTime() override = default;
    BonusTime(const BonusTime& other): PowerUp(other) {}

    BonusTime& operator=(const BonusTime& other) {
        PowerUp::operator=(other);
        bonus = other.bonus;
        return *this;
    }


    void showInfo(const std::string& reply) override {
        if (reply == "y" or reply == "Y") {
            afis(std::cout);
        }
    }

    void activateTimePower (int& t) override{
        t = t + bonus;
        std::cout << "time remaining: " << t << "\n";
    }

    std::string Name() const override {
        return " Bonus Time PowerUp. ";
    }
};

#endif //BONUSTIME_H
