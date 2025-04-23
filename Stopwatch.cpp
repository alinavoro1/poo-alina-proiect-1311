//
// Created by avoro on 4/23/2025.
//

#include "Stopwatch.h"

void Stopwatch::start() {
    start_time = std::chrono::high_resolution_clock::now();
    running = true;
}

double Stopwatch::elapsed() const {
    if (!running) return 0.0;
    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = now - start_time;
    return elapsed.count();
}
