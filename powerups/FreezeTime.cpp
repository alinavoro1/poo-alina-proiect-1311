//
// Created by avoro on 5/7/2025.
//

#include "FreezeTime.h"

FreezeTime::FreezeTime(): PowerUp(4,"You can press the key p while playing and the timer will freeze for 10 seconds. \n", "p") {}

FreezeTime::~FreezeTime() = default;

FreezeTime::FreezeTime(const FreezeTime &other): PowerUp(other) {}

// PowerUp * FreezeTime::clone() const {
//     return new FreezeTime(*this);
// }

FreezeTime & FreezeTime::operator=(const FreezeTime &other) {
    PowerUp::operator=(other);
    return *this;
}

void FreezeTime::activateTimePower(int &t, Stopwatch &sw) {
    std::cout << "Timer of: " << t-sw.elapsed()<< " seconds is frozen for 10 seconds! \n";
    std::thread freeze_thread([&sw]() {
        sw.pause();
        std::this_thread::sleep_for(std::chrono::seconds(10));
        sw.resume();
    });

    freeze_thread.detach();
}

void FreezeTime::showInfo(const std::string &reply) {
    if (reply == "y" or reply == "Y") {
        afis(std::cout);
    }
    else if (reply == "n" or reply == "N") {
        std::cout << "ook.. \n";
    }
}

std::string FreezeTime::Name() const {
    return "Freeze Time Power-Up. ";
}
