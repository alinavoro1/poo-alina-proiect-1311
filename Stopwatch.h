//
// Created by avoro on 4/23/2025.
//

#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <chrono>


class Stopwatch {
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::duration<double> paused_duration{};
    bool running = false;
    bool paused = false;
    std::chrono::high_resolution_clock::time_point pause_start;

public:
    void start();

    double elapsed() const;

    void pause();

    void resume();
};



#endif //STOPWATCH_H
