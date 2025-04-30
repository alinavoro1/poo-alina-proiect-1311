//
// Created by avoro on 4/23/2025.
//

#ifndef JOC_H
#define JOC_H
#include <atomic>
#include <iostream>
#include <tabulate.hpp>
#include <unordered_set>

#include "cosCumparaturi.h"
#include "listaCumparaturi.h"
#include "Magazin.h"
#include "Stopwatch.h"
#include <indicators.hpp>

#include "Discount.h"
#include "PowerUp.h"
#include "SortItems.h"

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
    Joc() {
        initializePowerUps();
    }

    explicit Joc(const std::string &playerName_): playerName{playerName_}, timp(0) {
        initializePowerUps();
    }

    Joc(const std::string &playerName_, const listaCumparaturi &lista_)
    : playerName{playerName_}, lista{lista_}, timp(0) {
        initializePowerUps();
    }

    const listaCumparaturi & getLista() const { return this->lista; }

    Joc & operator=(const Joc &other) {
        if (this == &other) return *this;
        lista = other.lista;
        timp = other.timp;
        varianta = other.varianta;
        playerName = other.playerName;
        currentStreak = other.currentStreak;

        powerUps.clear();
        for (const auto& up : other.powerUps) {
            powerUps.push_back(std::shared_ptr<PowerUp>(up)); // Copie shallow
        }
        return *this;
    }

    ~Joc() = default;

    friend std::ostream & operator<<(std::ostream &os, const Joc &joc) {
        os
                << "playerName: " << joc.playerName<< "\n"
                << " lista: " << joc.lista
                << " timp: " << joc.timp<< "\n";
        return os;
    }

    void initializePowerUps() {
        powerUps.push_back(std::make_shared<Discount>(10));
        powerUps.push_back(std::make_shared<SortItems>());
    }

    int verificarePret() const {
        int ok =0;
        for (const auto& item : lista.getItems()) {
            if (item.getPret() == 0){
                ok++;}
        }
        if(ok == 0){
            std::cout << "this version is available right now.\n";
            return 1;
        }
        else{
            std::cout << "this version is not availble right now.\n";
            return 0;}
    }

    static void inregistreazaWin(std::vector<std::shared_ptr<PowerUp>>& powerUps) {
        currentStreak++;
        for (auto& power : powerUps) {
            if (power->canBeUsed(currentStreak)) {
                power->showInfo();
            }
        }
    }

    void aplicaPowerUp(const std::string& keyPress, Raion raion) {
        for (auto& power : powerUps) {
            if (power->canBeUsed(currentStreak)) {
                power->verifyKey(keyPress);
                if (power->canBeUsed(currentStreak)) {
                    power->activateAislePower(raion);
                    reseteazaStreak();
                    std::cout<<"powerup applied";
                    break;
                }
            }
        }
    }

    static void reseteazaStreak() {
        currentStreak = 0;
    }

    static void initStatic() {
        winRate = 0;
        lossRate = 0;
    }

    static void actualizeazaWin() {
        winRate++;
    }

    static void actualizeazaLoss() {
        lossRate++;
        reseteazaStreak();
    }

    static void calculProcent(int wins, int losses) {
        using namespace indicators;
        int totalJocuri = wins + losses;
        if (totalJocuri == 0) {
            std::cout<< "No games played yet ;P \n";

        }
        else {
            double procentWin, procentLoss;
            procentWin = (wins * 100)/ totalJocuri;
            procentLoss = (losses * 100)/ totalJocuri;
            ProgressBar bar1{
                option::BarWidth{50},
                option::Start{"["},
                option::Fill{"■"},
                option::Lead{"|"},
                option::Remainder{"="},
                option::End{" ]"},
                option::ForegroundColor{Color::yellow},
                option::PrefixText{"Win rate =>  "},
                option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}
            };
            std::cout<< "       " << procentWin << "% win "<< procentLoss << "% loss\n";
            bar1.set_progress(procentWin);
            std::cout<<std::endl;
        }
    }

    Joc(const Magazin &magazin, const std::string &nume): magazin(magazin), playerName(nume), timp(0) {}

    void listaGoala(const cosCumparaturi &cos, const listaCumparaturi& listaVerif) {
        // std::cout<<"lista initiala a fost : " << lista;
        if (cos.getLista().getItems().empty()) {
            std::unordered_set<std::string> produse;
            for (const auto& item : listaVerif.getItems()) {
                produse.insert(item.getName());
            }
            for (const auto& item : cos.getItems()) {
                if (produse.find(item.getName()) == produse.end()) {
                    std::cout << "❌The shopping cart does not contain the correct items.\n ";
                    return;
                }
            }
            if (varianta == 3) {
                if (cos.getTotalPlata() <= listaVerif.getBuget()) {
                    std::cout << "Congrats! You won!💎💎💎💎👑👑👑\n";
                    actualizeazaWin();
                    inregistreazaWin(powerUps);
                } else {
                    std::cout << "You lost!❌❌\n";
                    actualizeazaLoss();
                }
            } else {
                std::cout << "Congrats! You won!💎💎💎💎👑👑👑\n";
                actualizeazaWin();
                inregistreazaWin(powerUps);
            }
        } else {
            std::cout << "You lost!❌❌\n";
            actualizeazaLoss();
        }
    }

    void run() {
        std::string replay;
        do {
            int versiune = selecteazaVersiune();
            int limitaTimp;
            if (versiune ==1) {
                limitaTimp = 90;
            }
            else if (versiune ==2 || versiune ==3) {
                limitaTimp = 60;
            }
            else {
                limitaTimp = 0;
                std::cout<<"Version unavailable. Enter a valid version\n";
            }

            listaCumparaturi listaGenerata = magazin.genereazaListaCumparaturi();

            afiseazaLista(listaGenerata, versiune);

            listaCumparaturi lista2;
            lista2 = listaGenerata;
            cosCumparaturi cos{lista2, {}};
            Joc joc{playerName, listaGenerata};


            if (joc.verificarePret() == 1) {
                std::string raspuns;
                std::cout << "Do you want to start the game? (y/n)\n";
                std::cin >> raspuns;

                if (raspuns == "y" || raspuns == "Y") {
                    if (startJoc( cos, limitaTimp)) {
                        std::cout << "You finished on time!\n";
                    }
                    std::cout << cos;
                }
            }
            listaGoala(cos, listaGenerata);
            std::cout <<"Your win rate is: \n";
            calculProcent(winRate, lossRate);

            std::cout << "Do you want to play again? Please...(y/n)\n";
            std::cin >> replay;
        } while (replay == "y");
    }



    int selecteazaVersiune() {
        int versiune;
        std::cout << "Select a game version:\n - [1] 1min 30s no budget\n - [2] 1min no budget\n - [3] 1min with budget\n";
        std::cin >> versiune;
        if (versiune < 1 || versiune > 3) {
            std::cout << "Invalid version\n";
            exit(1);
        }
        varianta = versiune;
        return versiune;
    }


    void afiseazaLista( listaCumparaturi listaC, int versiune) {
        tabulate::Table listaInit;
        std::vector<std::string> display_items;
        for (const auto& item: listaC.getItems()) {
            display_items.push_back(item.getName());
        }
        std::string display_combined;
        for (size_t i = 0; i < display_items.size(); ++i) {
            display_combined += display_items[i];
            if (i < display_items.size() - 1) display_combined += ", ";
        }

        listaInit.add_row({display_combined});
        listaInit[0][0].format()
                .font_style({tabulate::FontStyle::italic})
                .font_color(tabulate::Color::red);

        std::cout << "Your list contains:\n" << listaInit << "\n";
        if (versiune == 3) {
            listaC.calculTotal();
            std::cout << "Your budget is: " << listaC.getBuget() << "\n\n";
        }
    }

    bool startJoc(cosCumparaturi &cos, int limitaTimp) {
        Stopwatch timer;
        timer.start();
        bool timpExpirat = false;

        for (auto& raion : magazin.getRaioane()) {
            if (timer.elapsed() >= limitaTimp) {
                std::cout << "\n⏰ Time has expired! You lost!\n";
                timpExpirat = true;
                break;
            }

            std::cout << raion << "\n\n";
            tabulate::Table listaDisplay;
            std::vector<std::string> item_names;
            for (const auto& item: cos.getLista().getItems()) {
                item_names.push_back(item.getName());
            }

            std::string items_combined;
            for (size_t i = 0; i < item_names.size(); i++) {
                items_combined += item_names[i];
                if (i < item_names.size() - 1)
                    items_combined += ", ";
            }

            listaDisplay.add_row({"Your list", items_combined});
            listaDisplay[0][0].format()
                    .font_style({tabulate::FontStyle::italic})
                    .font_color(tabulate::Color::magenta);
            std::cout << listaDisplay << "\n\n";

            std::cout << "Pick a number to add the item to the cart, -1 to skip, 99 to exit game\n";
            if (currentStreak >= 2) {
                std::string inputKey;
                std::cout << "Press key for available power-up (e.g., D or S): ";
                std::cin >> inputKey;
                aplicaPowerUp(inputKey, raion);
            }

            int index;
            while (std::cin >> index) {
                if (index == -1) break;
                else if (index == 99) return false;
                else if (index >= 0 && index < int(raion.getItems().size())) {
                    cos.adaugaInCos(raion.getItems()[index]);
                    cos.calculTotal();
                } else {
                    std::cout << "Invalid number\n";
                }
            }
        }

        if (!timpExpirat) {
            double timpFinal = timer.elapsed();
            std::cout << "You finished in " << timpFinal << " seconds!\n";
        }

        return !timpExpirat;
    }
};

#endif //JOC_H
