//
// Created by avoro on 4/30/2025.
//

#ifndef POWERUP_H
#define POWERUP_H
#include <string>

// #include "Joc.h"
#include "Raion.h"


class PowerUp {
protected:
    int winStreakRequired;
    bool isActive;
    std::string description;
    std::string key;
public:
    PowerUp(int winStreak_,const std::string& description_, const std::string& key_) : winStreakRequired(winStreak_), isActive(false), description(description_), key(key_) {}
    virtual ~PowerUp() = default;

    PowerUp(const PowerUp &other)
        : winStreakRequired(other.winStreakRequired), isActive(other.isActive), description(other.description), key(other.key) {
    }

    PowerUp & operator=(const PowerUp &other) {
        if (this == &other)
            return *this;
        winStreakRequired = other.winStreakRequired;
        isActive = other.isActive;
        description = other.description;
        key = other.key;
        return *this;
    }

    virtual bool canBeUsed(int currentStreak ) const {
        if (currentStreak>=winStreakRequired) {
            return true;
        }
        return false;
    }

    virtual void verifyKey(const std::string& inp) {
        if (key == inp) {
            isActive = true;
        }
        isActive = false;
    };

    virtual void activateAislePower(Raion& raionCrt) {
        std::cout << "No powerup activated";
        std::cout<<raionCrt;
    };

    virtual void activateTimePower (int& t) {
        std::cout << "no powerup activated";
        std::cout<< t;
    }

    friend std::ostream& operator<<(std::ostream& os, const PowerUp& obj) {
        return obj.afis(os);
    }

    virtual std::ostream& afis(std::ostream& os) const {
        os<< description;
        os<< "activation key: " <<key<< "; (win streak required: "<<winStreakRequired<<")\n";
        return os;
    }

    // friend std::ostream& operator<<(std::ostream& os, const PowerUp& obj) {
    //     os<< obj.description;
    //     os<< "activation key: " <<obj.key<< "(win streak required: "<<obj.winStreakRequired<<")";
    //     return os;
    // }

    virtual void showInfo(const std::string& reply) = 0;
    virtual std::string Name() const = 0;
};

#endif //POWERUP_H
