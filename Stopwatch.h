//
// Created by avoro on 4/23/2025.
//

#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <chrono>


class Stopwatch {
    std::chrono::high_resolution_clock::time_point start_time;
    bool running = false;
public:
    void start();

    double elapsed() const;
};



#endif //STOPWATCH_H
