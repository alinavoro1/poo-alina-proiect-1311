//
// Created by avoro on 5/7/2025.
//

#ifndef FREEZETIME_H
#define FREEZETIME_H
#include <thread>

#include "PowerUp.h"


class FreezeTime: public PowerUp {
public:
    explicit FreezeTime();

    ~FreezeTime() override;

    FreezeTime (const FreezeTime& other);

    PowerUp* clone() const override;

    FreezeTime & operator= (const FreezeTime &other);

    void activateTimePower(int& t, Stopwatch& sw) override;

    void showInfo(const std::string &reply) override;

    std::string Name() const override;
};



#endif //FREEZETIME_H
