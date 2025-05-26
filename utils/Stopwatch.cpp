//
// Created by avoro on 4/23/2025.
//

#include "Stopwatch.h"

void Stopwatch::start() {
    start_time = std::chrono::high_resolution_clock::now();
    paused_duration = std::chrono::seconds(0);
    running = true;
    paused = false;
}

double Stopwatch::elapsed() const {
    if (!running) return 0.0;
    auto now = paused ? pause_start : std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = now - start_time - paused_duration;
    return elapsed.count();
}

void Stopwatch::pause() {
    if (running && !paused) {
        pause_start = std::chrono::high_resolution_clock::now();
        paused = true;
    }
}

void Stopwatch::resume() {
    if (running && paused) {
        auto now = std::chrono::high_resolution_clock::now();
        paused_duration += now - pause_start;
        paused = false;
    }
}
