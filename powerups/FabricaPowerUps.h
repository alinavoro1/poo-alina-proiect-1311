//
// Created by avoro on 5/5/2025.
//

#ifndef FABRICAPOWERUPS_H
#define FABRICAPOWERUPS_H
#include "BonusTime.h"
#include "Discount.h"
#include "PowerUp.h"
#include "SortItems.h"
#include "FreezeTime.h"



class FabricaPowerUps {
public:
    static std::vector<std::shared_ptr<PowerUp>> createDefaultPowerUps();
};



#endif //FABRICAPOWERUPS_H
