#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <set>
#include <random>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <chrono>
#include <thread>
#include <atomic>
#include <tabulate.hpp>
#include <indicators.hpp>

#include "cosCumparaturi.h"
#include "Item.h"
#include "Joc.h"
#include "listaCumparaturi.h"
#include "Raion.h"
#include "ObiecteRaioane.h"
#include "Stopwatch.h"
#include "Magazin.h"

void listaGoala(const Joc& joc, const cosCumparaturi& cos) {
    if (joc.getLista().getItems().empty()) {
        std::cout << "The shopping list is empty. \n The game cannot start.\n";
    }
    else if (cos.getLista().getItems().empty()) {
        std::unordered_set<std::string> produse;
        for (const auto& item : joc.getLista().getItems()) {
            produse.insert(item.getName());
        }
        for (const auto& item : cos.getItems()) {
            if (produse.find(item.getName()) == produse.end()) {
                std::cout<<"The shopping cart is not it.";
                return;
            }
        }
        if (joc.getVarianta() == 3) {
            if (cos.getTotalPlata() <= joc.getLista().getBuget()) {
                std::cout<<"Congrats! You won!";
            }
            else {
                std::cout<<"You lost!";
            }
        }
        else {
            std::cout << "Congrats! You won!";
        }
    }
    else {
        std::cout << "You lost!";
    }
}

listaCumparaturi listGenerator(const Magazin& magazin) {
    std::set<std::string> produse;
    std::vector<Item> listaMea;

    for (const Raion& r : magazin.getRaioane()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::vector<Item> produseleRndm = r.getItems();
        std::shuffle(produseleRndm.begin(),produseleRndm.end(),gen);

        std::uniform_int_distribution<int> dist(0, 3);
        int numItems = std::min(dist(gen), (int)produseleRndm.size());

        for (int i = 0; i< numItems; ++i) {
            if (produse.insert(produseleRndm[i].getName()).second) {
                listaMea.push_back(produseleRndm[i]);
            }
        }
    }

    return listaCumparaturi(listaMea);
}


int main() {
    Magazin magazin{get_raioane()};
    std::cout << get_raioane()[0] << "\n\n";
    std::cout<<"\n";

    std::cout<<"Enter player name: ";
    std::string nume;
    std::cin>>nume;

    tabulate::Table welcoming;
    std::string greet;
    greet = "Welcome,\n ";
    greet += nume;
    greet += "!";
    welcoming.add_row({greet});

    welcoming.format()
        .padding_top(2)
        .padding_bottom(2)
        .padding_left(8)
        .padding_right(8)
        .font_style({tabulate::FontStyle::bold, tabulate::FontStyle::dark})
        .font_align(tabulate::FontAlign::center)
        .font_color(tabulate::Color::white)
        .corner_top_left("@")
        .corner_top_right("%")
        .corner_bottom_left("%")
        .corner_bottom_right("@")

        .corner_top_left_color(tabulate::Color::cyan)
        .corner_top_right_color(tabulate::Color::yellow)
        .corner_bottom_left_color(tabulate::Color::green)
        .corner_bottom_right_color(tabulate::Color::red)

        .border_top("`")
        .border_bottom("`")
        .border_left("^")
        .border_right("^")

        .border_left_color(tabulate::Color::yellow)
        .border_right_color(tabulate::Color::green)
        .border_top_color(tabulate::Color::cyan)
        .border_bottom_color(tabulate::Color::red);

    std::cout<<welcoming<<"\n";

    std::string replay;

    do {
        std::cout<<"Select a game version:\n - [ 1 ] 1min 30s timer no budget\n - [ 2 ] 1min timer no budget\n - [ 3 ] 1min timer with budget\n ";
        int versiune;
        std::cin>>versiune;

        int limitaTimp = 0;
        switch (versiune) {
            case 1: limitaTimp = 90; break;
            case 2: limitaTimp = 60; break;
            case 3: limitaTimp = 60; break;
            default: std::cout<< "Invalid version\n"; return 1;
        }

        listaCumparaturi lista;
        lista =  listGenerator(magazin);
        lista.calculeazaBuget(lista);

        tabulate::Table listaInit;
        std::vector<std::string> display_items;
        for (const auto& item: lista.getItems()) {
            display_items.push_back(item.getName());
        }

        std::string display_combined;
        for (size_t i = 0; i < display_items.size(); i++) {
            display_combined += display_items[i];
            if ( i< display_items.size() -1)
                display_combined += ", ";
        }

        listaInit.add_row({display_combined});


        listaInit[0][0].format()
            .font_style({tabulate::FontStyle::italic})
            .font_color(tabulate::Color::red);
        std::cout<<"Your list contains: \n";
        std::cout<<listaInit<<"\n";

        if (versiune == 3) {
            std::cout<< "Your budget is: " << lista.getBuget()<< "\n";
        }
        std::cout<<"\n";
        listaCumparaturi lista2;
        lista2 = lista;
        cosCumparaturi cos{lista2, {}};

        Joc start{nume, lista, versiune };
        start.setareTimer();
        if (start.verificarePret()==1) {
            std::string raspuns;
            std::cout<<"Do you want to start the game? (y/n)\n";
            std::cin>>raspuns;
            if (raspuns == "y" || raspuns == "Y") {
                Stopwatch timer;
                timer.start();
                bool timpExpirat = false;
                for (const auto& raion : magazin.getRaioane()) {
                    if (timer.elapsed() >= limitaTimp) {
                        std::cout << "\n⏰ Time has expired! You lost!\n";
                        timpExpirat = true;
                        break;
                    }
                    std::cout<< raion;
                    std::cout<<"\n";
                    std::cout<< "\n";

                    tabulate::Table listaDisplay;
                    std::vector<std::string> item_names;
                    for (const auto& item: cos.getLista().getItems()) {
                        item_names.push_back(item.getName());
                    }

                    std::string items_combined;
                    for (size_t i = 0; i < item_names.size(); i++) {
                        items_combined += item_names[i];
                        if ( i< item_names.size() -1)
                            items_combined += ", ";
                    }

                    listaDisplay.add_row({"Your list", items_combined});

                    listaDisplay[0][0].format()
                        .font_style({tabulate::FontStyle::italic})
                        .font_color(tabulate::Color::magenta);

                    std::cout<<listaDisplay<<"\n";

                    std::cout<< "\n";
                    std::cout<<"Pick a number to add the item to the cart, -1 if you want to go to the next aisle or 99 to exit game\n";
                    std::cout<<"Enter number: ";
                    int index;
                    while (std::cin>>index) {
                        if ( index == -1) break;
                        else if ( index >=0 && index < int(raion.getItems().size())) {
                            cos.adaugaInCos(raion.getItems()[index]);
                            cos.sumadinCos();
                        }
                        else if (index == 99) {
                            std::cout<< "Exiting ... \n. \n. \n. \n";
                            break;
                        }
                        else {
                            std::cout<<"Invalid number\n";
                        }
                    }
                    if (index == 99) break;
                }
                if (!timpExpirat) {
                    double timpFinal = timer.elapsed();
                    std::cout<<"You finished in " <<timpFinal<< " seconds!\n" <<std::endl;
                }
                std::cout<<cos;

            }
        }
        listaGoala(start,cos);
        std::cout<<" Do you want to play again? Please...\n";
        std::cin>>replay;
    }while (replay == "y");
    return 0;
}