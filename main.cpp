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

#include "Joc.h"
#include "Item.h"
#include "Raion.h"
#include <set>

#include "ObiecteRaioane.h"
#include "Stopwatch.h"
#include "Magazin.h"

// class Lista {
// protected:
//     std::vector<Item> items;
//
// public:
//     Lista() = default;
//     Lista(const std::vector<Item>& items_) : items(items_) {}
//
//     virtual ~Lista() = default;
//
//     virtual void afisare() const = 0;
//     virtual Lista* clone() const = 0;
//
//     virtual void calculTotal() = 0;
//
//     const std::vector<Item>& getItems() const {
//         return items;
//     }
//
//     Lista& operator=(const Lista& other) {
//         if (this != &other) {
//             items = other.items;
//         }
//         return *this;
//     }
// };

// class listaCumparaturi : public Lista {
//     int buget;
//
// public:
//     listaCumparaturi() = default;
//
//     explicit listaCumparaturi(const std::vector<Item>& items_, int buget_ = 0)
//         : Lista(items_), buget{buget_} {}
//
//     listaCumparaturi(const listaCumparaturi& other)
//         : Lista(other.items), buget{other.buget} {}
//
//     listaCumparaturi& operator=(const listaCumparaturi& other) {
//         if (this != &other) {
//             Lista::operator=(other);
//             buget = other.buget;
//         }
//         return *this;
//     }
//
//     int getBuget() const {
//         return buget;
//     }
//
//     ~listaCumparaturi() override = default;
//
//     friend std::ostream& operator<<(std::ostream& os, const listaCumparaturi& lista) {
//         for (const auto& item : lista.items) {
//             os << item << ", ";
//         }
//         os << "\n";
//         return os;
//     }
//
//     void stergeProdus(const Item& item) {
//         auto it = std::find_if(items.begin(), items.end(), [&](const Item& item_) {
//             return item_.getName() == item.getName();
//         });
//         if (it != items.end()) {
//             items.erase(it);
//         }
//     }
//
//     void afisare() const override {
//         std::cout << *this;
//     }
//
//     Lista* clone() const override {
//         return new listaCumparaturi(*this);
//     }
//
//     void calculTotal() override {
//         double total = 0;
//         for (const auto& item : items) {
//             total += item.getPret();
//         }
//         // Aici adăugăm acel +5 din fosta funcție calculeazaBuget
//         int bugetFinal = int(round(total)) + 5;
//         buget = bugetFinal;
//     }
// };

// class cosCumparaturi: public Lista {
//     listaCumparaturi lista;
//     double totalPlata;
// public:
//     cosCumparaturi(const listaCumparaturi &lista_, const std::vector<Item> &items_, double totalPlata_ = 0.0):Lista(items_), lista(lista_), totalPlata(totalPlata_){}
//     cosCumparaturi(const cosCumparaturi &other):  Lista(other.items), lista(other.lista), totalPlata(other.totalPlata) {}
//     explicit cosCumparaturi( double totalPlata_ = 0.0 ) : totalPlata(totalPlata_) {}
//
//     cosCumparaturi& operator=(const cosCumparaturi &other) {
//         if (this != &other) {
//             Lista::operator=(other);
//             lista = other.lista;
//             totalPlata = other.totalPlata;
//         }
//         return *this;
//     }
//     double getTotalPlata() const {return totalPlata; }
//
//     const listaCumparaturi& getLista() const {return lista;}
//
//     ~cosCumparaturi() override = default;
//
//     friend std::ostream& operator<<(std::ostream& os, const cosCumparaturi& cos) {
//         os <<"Your shopping list: "<< cos.lista;
//         os << "Your shopping bag: ";
//         for (const auto& item : cos.items) {
//             os<< item<< ", ";
//         }
//         os << "\n";
//         os << "Total price: " << cos.totalPlata<<"\n";
//         os<<"\n";
//         return os;
//     }
//
//     void calculTotal() override{
//         if (items.empty()) {
//             std::cout << "Shopping bag is empty 🤣\n";
//         }
//         else {
//             totalPlata = 0.0;
//             for (const auto& item: items) {
//                 totalPlata += item.getPret();
//             }
//
//             std::cout << "Your total is now: " << totalPlata << std::endl;
//         }
//     }
//     void adaugaInCos(const Item &item) {
//         items.push_back(item);
//         lista.stergeProdus(item);
//     }
//
//
//     void afisare() const override {
//         std::cout << *this;
//     }
//
//
//     Lista* clone() const override {
//         return new cosCumparaturi(*this);
//     }
// };

// class Raion: public Lista {
//     std::string name;
// public:
//     Raion(const std::string& name_,const std::vector <Item>& items_) : Lista(items_),name{name_}{}
//     Raion(const Raion&  other) : Lista(other),name{other.name} {}
//
//     const std::string& getName() const{ return name;}
//
//     Raion& operator=(const Raion& other) {
//         name = other.name;
//         Lista::operator=(other);
//         return *this;
//     }
//
//     ~Raion() override = default;
//
//     friend std::ostream & operator<<(std::ostream &os, const Raion& raion) {
//
//         tabulate::Table header;
//         tabulate::Table tabel;
//
//         header.add_row({ "Aisle: " + raion.name });
//         header[0].format()
//             .width(60)
//             .font_align(tabulate::FontAlign::center)
//             .font_style({tabulate::FontStyle::bold})
//             .font_background_color(tabulate::Color::red)
//             .font_color(tabulate::Color::white);
//
//         size_t n = raion.items.size();
//         size_t cols = 3;
//
//         for (size_t i = 0; i < n; i += cols) {
//             std::vector<std::string> row;
//             for (size_t j = 0; j < cols; ++j) {
//                 if (i + j < n) {
//                     std::stringstream ss;
//                     ss << "[" << (i + j) << "] " << raion.items[i + j];
//                     row.push_back(ss.str());
//                 } else {
//                     row.push_back("");
//                 }
//             }
//             tabel.add_row(tabulate::Table::Row_t{row.begin(),row.end()});
//         }
//
//         tabel.format()
//             .font_align(tabulate::FontAlign::center)
//             .padding_top(0)
//             .padding_bottom(0);
//
//         os << header << "\n" << tabel << "\n";
//         return os;
//     }
//
// };

// class Magazin {
//     std::vector <Raion> raioane;
// public:
//     explicit Magazin(const std::vector<Raion> &raioane_): raioane(raioane_) {
//     }
//
//     Magazin() {}
//
//     ~Magazin() = default;
//
//     Magazin(const Magazin &other): raioane(other.raioane) {
//     }
//
//     Magazin & operator=(const Magazin &other) {
//         if (this == &other)
//             return *this;
//         raioane = other.raioane;
//         return *this;
//     }
//
//     friend std::ostream& operator<<(std::ostream& os, const Magazin& magazin) {
//         os << "raioane: ";
//         for (const auto& items : magazin.raioane) {
//             os << items << ", ";
//         }
//         os << "\n";
//         return os;
//     }
//
//     const std::vector<Raion> & getRaioane() const { return this->raioane;}
//
//     listaCumparaturi genereazaListaCumparaturi() const {
//         std::set<std::string> produse;
//         std::vector<Item> listaMea;
//
//         for (const Raion& r : getRaioane()) {
//             std::random_device rd;
//             std::mt19937 gen(rd());
//             std::vector<Item> produseleRndm = r.getItems();
//             std::shuffle(produseleRndm.begin(), produseleRndm.end(), gen);
//
//             std::uniform_int_distribution<int> dist(0, 3);
//             int numItems = std::min(dist(gen), (int)produseleRndm.size());
//
//             for (int i = 0; i < numItems; ++i) {
//                 if (produse.insert(produseleRndm[i].getName()).second) {
//                     listaMea.push_back(produseleRndm[i]);
//                 }
//             }
//         }
//
//         return listaCumparaturi(listaMea);
//     }
// };

// class Joc {
//     Magazin magazin;
//     std::string playerName;
//     int varianta=0;
//     listaCumparaturi lista;
//     int timp;
//     std::atomic<bool> running = false;
// public:
//     Joc() {}
//
//     Joc(const std::string &playerName_): playerName{playerName_}, timp(0) {}
//
//     Joc(const std::string &playerName_, const listaCumparaturi &lista_): playerName{playerName_}, lista{lista_}, timp(0) {}
//
//     const listaCumparaturi & getLista() const { return this->lista; }
//
//     Joc & operator=(const Joc &other) {
//         lista = other.lista;
//         timp = other.timp;
//         varianta = other.varianta;
//         playerName = other.playerName;
//         return *this;
//     }
//
//     ~Joc() = default;
//
//     std::ostream & operator<<(std::ostream &os, const Joc &obj) {
//         os
//                 << "playerName: " << obj.playerName<< "\n"
//                 << " lista: " << obj.lista
//                 << " timp: " << obj.timp<< "\n";
//         return os;
//     }
//
//
//     int verificarePret() const {
//         int ok =0;
//         for (const auto& item : lista.getItems()) {
//             if (item.getPret() == 0){
//                 ok++;}
//         }
//         if(ok == 0){
//             std::cout << "this version is available right now.\n";
//             return 1;
//         }
//         else{
//             std::cout << "this version is not availble right now.\n";
//             return 0;}
//     }
//
//
//     Joc(const Magazin &magazin, const std::string &nume): magazin(magazin), playerName(nume), timp(0) {}
//
//     void listaGoala(const cosCumparaturi &cos) {
//         if (lista.getItems().empty()) {
//             std::cout << "The shopping list is empty. \nThe game cannot start.\n";
//         } else if (cos.getLista().getItems().empty()) {
//             std::unordered_set<std::string> produse;
//             for (const auto& item : lista.getItems()) {
//                 produse.insert(item.getName());
//             }
//             for (const auto& item : cos.getItems()) {
//                 if (produse.find(item.getName()) == produse.end()) {
//                     std::cout << "The shopping cart does not contain the correct items.";
//                     return;
//                 }
//             }
//             if (varianta == 3) {
//                 if (cos.getTotalPlata() <= lista.getBuget()) {
//                     std::cout << "Congrats! You won!";
//                 } else {
//                     std::cout << "You lost!";
//                 }
//             } else {
//                 std::cout << "Congrats! You won!";
//             }
//         } else {
//             std::cout << "You lost!";
//         }
//     }
//
//     void run() {
//         std::string replay;
//         do {
//             int versiune = selecteazaVersiune();
//             int limitaTimp = (versiune == 1) ? 90 : 60;
//
//             auto listaGenerata = magazin.genereazaListaCumparaturi();
//             listaGenerata.calculTotal();
//
//             afiseazaLista(listaGenerata, versiune);
//
//             listaCumparaturi lista2 = listaGenerata;
//             cosCumparaturi cos{lista2, {}};
//             Joc joc{playerName, listaGenerata};
//
//
//             if (joc.verificarePret() == 1) {
//                 std::string raspuns;
//                 std::cout << "Do you want to start the game? (y/n)\n";
//                 std::cin >> raspuns;
//
//                 if (raspuns == "y" || raspuns == "Y") {
//                     if (startJoc( cos, limitaTimp)) {
//                         std::cout << "You finished on time!\n";
//                     }
//                     std::cout << cos;
//                 }
//             }
//             listaGoala(cos);
//             std::cout << "Do you want to play again? Please...(y/n)\n";
//             std::cin >> replay;
//         } while (replay == "y");
//     }
//
//
//
//     int selecteazaVersiune() {
//         int versiune;
//         std::cout << "Select a game version:\n - [1] 1min 30s no budget\n - [2] 1min no budget\n - [3] 1min with budget\n";
//         std::cin >> versiune;
//         if (versiune < 1 || versiune > 3) {
//             std::cout << "Invalid version\n";
//             exit(1);
//         }
//         varianta = versiune;
//         return versiune;
//     }
//
//
//     void afiseazaLista(const listaCumparaturi& listaC, int versiune) {
//         tabulate::Table listaInit;
//         std::vector<std::string> display_items;
//         for (const auto& item: listaC.getItems()) {
//             display_items.push_back(item.getName());
//         }
//         std::string display_combined;
//         for (size_t i = 0; i < display_items.size(); ++i) {
//             display_combined += display_items[i];
//             if (i < display_items.size() - 1) display_combined += ", ";
//         }
//
//         listaInit.add_row({display_combined});
//         listaInit[0][0].format()
//                 .font_style({tabulate::FontStyle::italic})
//                 .font_color(tabulate::Color::red);
//
//         std::cout << "Your list contains:\n" << listaInit << "\n";
//         if (versiune == 3) {
//             std::cout << "Your budget is: " << lista.getBuget() << "\n\n";
//         }
//     }
//
//     bool startJoc(cosCumparaturi &cos, int limitaTimp) {
//         Stopwatch timer;
//         timer.start();
//         bool timpExpirat = false;
//
//         for (const auto& raion : magazin.getRaioane()) {
//             if (timer.elapsed() >= limitaTimp) {
//                 std::cout << "\n⏰ Time has expired! You lost!\n";
//                 timpExpirat = true;
//                 break;
//             }
//
//             std::cout << raion << "\n\n";
//             tabulate::Table listaDisplay;
//             std::vector<std::string> item_names;
//             for (const auto& item: cos.getLista().getItems()) {
//                 item_names.push_back(item.getName());
//             }
//
//             std::string items_combined;
//             for (size_t i = 0; i < item_names.size(); i++) {
//                 items_combined += item_names[i];
//                 if (i < item_names.size() - 1)
//                     items_combined += ", ";
//             }
//
//             listaDisplay.add_row({"Your list", items_combined});
//             listaDisplay[0][0].format()
//                     .font_style({tabulate::FontStyle::italic})
//                     .font_color(tabulate::Color::magenta);
//             std::cout << listaDisplay << "\n\n";
//
//             std::cout << "Pick a number to add the item to the cart, -1 to skip, 99 to exit game\n";
//             int index;
//             while (std::cin >> index) {
//                 if (index == -1) break;
//                 else if (index == 99) return false;
//                 else if (index >= 0 && index < int(raion.getItems().size())) {
//                     cos.adaugaInCos(raion.getItems()[index]);
//                     cos.calculTotal();
//                 } else {
//                     std::cout << "Invalid number\n";
//                 }
//             }
//         }
//
//         if (!timpExpirat) {
//             double timpFinal = timer.elapsed();
//             std::cout << "You finished in " << timpFinal << " seconds!\n";
//         }
//
//         return !timpExpirat;
//     }
// };




int main() {
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
    joc.run();

    return 0;
}