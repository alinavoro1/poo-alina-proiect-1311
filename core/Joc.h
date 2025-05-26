//
// Created by avoro on 4/23/2025.
//

#ifndef JOC_H
#define JOC_H
#include <atomic>
#include <iostream>
#include <../ext/include/tabulate.hpp>
#include <unordered_set>
#include <../ext/include/termcolor.hpp>

#include "cosCumparaturi.h"
#include "listaCumparaturi.h"
#include "Magazin.h"
#include "../utils/Stopwatch.h"
#include <../ext/include/indicators.hpp>
#include <../ext/include/rlutil.h>

#include "../powerups/PowerUp.h"
#include "../powerups/FabricaPowerUps.h"

class Joc {
    Magazin magazin;
    std::string playerName;
    int varianta=0;
    listaCumparaturi lista;
    int timp;
    std::atomic<bool> running = false;
    static int winRate;
    static int lossRate;
    static int currentStreak;
    std::vector<std::shared_ptr<PowerUp>> powerUps;
public:
    Joc();

    explicit Joc(const std::string &playerName_);

    Joc(const std::string &playerName_, const listaCumparaturi &lista_);

    Joc(const Magazin &magazin, const std::string &nume);

    Joc(const Joc &other);

    ~Joc();

    // const listaCumparaturi & getLista() const { return this->lista; }

    // Joc & operator=(const Joc &other) {
    //     if (this == &other) return *this;
    //     lista = other.lista;
    //     timp = other.timp;
    //     varianta = other.varianta;
    //     playerName = other.playerName;
    //     currentStreak = other.currentStreak;
    //
    //     powerUps.clear();
    //     for (const auto& up: other.powerUps) {
    //         powerUps.push_back(std::shared_ptr<PowerUp>(up->clone()));
    //     }
    //     return *this;
    // }

    friend std::ostream & operator<<(std::ostream &os, const Joc &joc);

    friend void swap(Joc &lhs, Joc &rhs) noexcept;

    Joc& operator=(Joc other);

    void verificarePret() const;

    static void inregistreazaWin(std::vector<std::shared_ptr<PowerUp>>& powerUps);

    void aplicaPowerUp(const std::string& keyPress, Raion& raion, int& limit, Stopwatch& sw);

    static void reseteazaStreak();

    static void initStatic();

    static void actualizeazaWin();

    static void actualizeazaLoss();

    static void calculProcent(int wins, int losses);

    void listaGoala(const cosCumparaturi &cos, const listaCumparaturi& listaVerif);

    void run();

    int selecteazaVersiune();

    void afiseazaLista( listaCumparaturi listaC, int versiune);

    bool startJoc(cosCumparaturi &cos, int limitaTimp);
};

#endif //JOC_H
