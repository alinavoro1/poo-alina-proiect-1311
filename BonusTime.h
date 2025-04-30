//
// Created by avoro on 4/30/2025.
//

#ifndef BONUSTIME_H
#define BONUSTIME_H
#include "PowerUp.h"


class BonusTime: public PowerUp {
    int bonus = 30; //se adauga 30s la timp
public:
    BonusTime():PowerUp(4, "You can press the key t while playing\n and you will get 30s bonus on your timer\n", "t"){}
    ~BonusTime() = default;
    BonusTime(const BonusTime& other): PowerUp(other) {}

    BonusTime& operator=(const BonusTime& other) {
        PowerUp::operator=(other);
        return *this;
    }



    void showInfo() override {
        std::cout<< description << "\n";
    }

    void activateTimePower(int& t) {
        t = t+ 30;
        std::cout << "time remaining: " << t << "\n";
    }
};



#endif //BONUSTIME_H
