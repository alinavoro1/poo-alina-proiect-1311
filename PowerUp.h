//
// Created by avoro on 4/30/2025.
//

#ifndef POWERUP_H
#define POWERUP_H
#include <string>

#include "Raion.h"
#include "Stopwatch.h"


class PowerUp {
protected:
    int winStreakRequired;
    std::string description;
    std::string key;
public:
    PowerUp(int winStreak_,const std::string& description_, const std::string& key_);

    virtual ~PowerUp();

    PowerUp(const PowerUp &other);

    virtual PowerUp* clone() const = 0;

    PowerUp & operator=(const PowerUp &other);

    virtual bool canBeUsed(int currentStreak ) const;

    virtual bool verifyKey(const std::string& inp);

    virtual void activateAislePower(Raion& raionCrt, int strk);

    virtual void activateTimePower (int& t, Stopwatch& sw);

    friend std::ostream& operator<<(std::ostream& os, const PowerUp& obj);

    virtual std::ostream& afis(std::ostream& os) const;

    // friend std::ostream& operator<<(std::ostream& os, const PowerUp& obj) {
    //     os<< obj.description;
    //     os<< "activation key: " <<obj.key<< "(win streak required: "<<obj.winStreakRequired<<")";
    //     return os;
    // }

    virtual void showInfo(const std::string& reply) = 0;
    virtual std::string Name() const = 0;
};

#endif //POWERUP_H
