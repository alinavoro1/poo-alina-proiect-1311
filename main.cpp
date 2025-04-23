#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <unordered_set>
#include <chrono>
#include <thread>
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

    Joc joc{magazin, nume};
    joc.run();

    return 0;
}