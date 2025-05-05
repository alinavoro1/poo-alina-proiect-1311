#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <tabulate.hpp>

#include "Joc.h"
#include "ObiecteRaioane.h"
#include "Magazin.h"


int main() {
    try {
        Magazin magazin{get_raioane()};
        // std::cout << get_raioane()[0] << "\n\n";
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

        Joc joc{magazin, nume};
        Joc::initStatic();
        joc.run();
    }
    catch (const RaionGol& e) {
        std::cerr <<"[Empty aisle Error]: "<< e.what()<< "\n";
    }
    catch (const PretInvalid& e) {
        std::cerr << "[Price Error]: " << e.what()<< "\n";
    }
    catch (const ExceptieListaGoala& e) {
        std::cerr << "[Empty list Error]: " << e.what()<< "\n";
    }
    catch (const TimpNegativ& e) {
        std::cerr << "[Time value Error]: " << e.what()<< "\n";
    }
    catch (const ValueException& e) {
        std::cerr<< "[Value Error]: " << e.what()<< "\n";
    }
    catch (const EroarePowerUp& e) {
        std::cerr << "[PowerUp Error]: " << e.what()<< "\n";
    }

    catch (const std::exception& e) {
        std::cerr << "[App Exception]: " << e.what()<< "\n";
    }
    return 0;
}