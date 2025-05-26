//
// Created by avoro on 5/5/2025.
//

#include "FabricaPowerUps.h"

std::vector<std::shared_ptr<PowerUp>> FabricaPowerUps::createDefaultPowerUps() {
    std::vector<std::shared_ptr<PowerUp>> powerUps;
    powerUps.push_back(std::make_shared<Discount>(10));
    powerUps.push_back(std::make_shared<SortItems>());
    powerUps.push_back(std::make_shared<BonusTime>(30));
    powerUps.push_back(std::make_shared<FreezeTime>());
    return powerUps;
}
