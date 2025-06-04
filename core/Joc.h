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
    Magazin& magazin = Magazin::getInstance();
    std::string playerName;
    int varianta=0;
    listaCumparaturi lista;
    int timp;
    std::atomic<bool> running = false;
    static int winRate;
    static int lossRate;
    static int currentStreak;
    std::vector<std::shared_ptr<PowerUp>> powerUps;

    Joc();

    explicit Joc(const std::string &playerName_);

    Joc(const std::string &playerName_, const listaCumparaturi &lista_);

    Joc(const Magazin &magazin, const std::string &nume);

    ~Joc();

    friend std::ostream & operator<<(std::ostream &os, const Joc &joc);

    friend void swap(Joc &lhs, Joc &rhs) noexcept;

    void verificarePret() const;

    static void inregistreazaWin(std::vector<std::shared_ptr<PowerUp>>& powerUps);

    void aplicaPowerUp(const std::string& keyPress, Raion& raion, int& limit, Stopwatch& sw);

    static void reseteazaStreak();

    static void actualizeazaWin();

    static void actualizeazaLoss();

    static void calculProcent(int wins, int losses);

    void listaGoala(const cosCumparaturi &cos, const listaCumparaturi& listaVerif);


    bool startJoc(cosCumparaturi &cos, int limitaTimp);

    int selecteazaVersiune();

    void afiseazaLista( listaCumparaturi listaC, int versiune);
public:
    Joc(const Joc &other) = delete;

    Joc& operator=(Joc& other) = delete;

    static Joc& getInstance() {
        static Joc joc;
        return joc;
    }
    void run();

    static void initStatic();
};

#endif //JOC_H
