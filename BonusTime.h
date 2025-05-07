//
// Created by avoro on 4/30/2025.
//

#ifndef BONUSTIME_H
#define BONUSTIME_H
#include "PowerUp.h"

//SA NU UIT SA SCHIMB STREAKUL LA 5. L-AM SCHIMBAT CA SA VERIFIC FUNCTIONALITATEA CORECTA
class BonusTime: public PowerUp {
    int bonus; //se adauga 30s la timp
public:
    explicit BonusTime(int bonus_);

    ~BonusTime() override;

    BonusTime(const BonusTime& other);

    PowerUp* clone() const override;

    BonusTime& operator=(const BonusTime& other);


    void showInfo(const std::string& reply) override;

    void activateTimePower (int& t, Stopwatch& sw) override;

    std::string Name() const override;
};

#endif //BONUSTIME_H
