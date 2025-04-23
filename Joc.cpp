//
// Created by avoro on 4/23/2025.
//

#include "Joc.h"

Joc::Joc() {}

Joc::Joc(const std::string &playerName_): playerName{playerName_}, timp(0) {}

Joc::Joc(const std::string &playerName_, const listaCumparaturi &lista_): playerName{playerName_}, lista{lista_}, timp(0) {}


const listaCumparaturi & Joc::getLista() const { return this->lista; }


Joc & Joc::operator=(const Joc &other) {
    lista = other.lista;
    timp = other.timp;
    varianta = other.varianta;
    playerName = other.playerName;
    return *this;
}

Joc::~Joc() = default;

int Joc::verificarePret() const {
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

Joc::Joc(const Magazin &magazin, const std::string &nume): magazin(magazin), playerName(nume), timp(0) {}

void Joc::listaGoala(const cosCumparaturi &cos) {
    if (lista.getItems().empty()) {
        std::cout << "The shopping list is empty. \nThe game cannot start.\n";
    } else if (cos.getLista().getItems().empty()) {
        std::unordered_set<std::string> produse;
        for (const auto& item : lista.getItems()) {
            produse.insert(item.getName());
        }
        for (const auto& item : cos.getItems()) {
            if (produse.find(item.getName()) == produse.end()) {
                std::cout << "The shopping cart does not contain the correct items.";
                return;
            }
        }
        if (varianta == 3) {
            if (cos.getTotalPlata() <= lista.getBuget()) {
                std::cout << "Congrats! You won!";
            } else {
                std::cout << "You lost!";
            }
        } else {
            std::cout << "Congrats! You won!";
        }
    } else {
        std::cout << "You lost!";
    }
}

void Joc::run() {
    std::string replay;
    do {
        int versiune = selecteazaVersiune();
        int limitaTimp = (versiune == 1) ? 90 : 60;

        auto listaGenerata = magazin.genereazaListaCumparaturi();
        listaGenerata.calculeazaBuget(listaGenerata);

        afiseazaLista(listaGenerata, versiune);

        listaCumparaturi lista2 = listaGenerata;
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
        listaGoala(cos);
        std::cout << "Do you want to play again? Please...(y/n)\n";
        std::cin >> replay;
    } while (replay == "y");
}

int Joc::selecteazaVersiune() {
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

void Joc::afiseazaLista(const listaCumparaturi& listaC, int versiune) {
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
        std::cout << "Your budget is: " << lista.getBuget() << "\n\n";
    }
}

bool Joc::startJoc(cosCumparaturi &cos, int limitaTimp) {
    Stopwatch timer;
    timer.start();
    bool timpExpirat = false;

    for (const auto& raion : magazin.getRaioane()) {
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
        int index;
        while (std::cin >> index) {
            if (index == -1) break;
            else if (index == 99) return false;
            else if (index >= 0 && index < int(raion.getItems().size())) {
                cos.adaugaInCos(raion.getItems()[index]);
                cos.sumadinCos();
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

std::ostream & operator<<(std::ostream &os, const Joc &obj) {
    os
            << "playerName: " << obj.playerName<< "\n"
            << " lista: " << obj.lista
            << " timp: " << obj.timp<< "\n";
    return os;
}
