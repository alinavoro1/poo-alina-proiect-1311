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



class Item {
    std::string name;
    double pret;
    std::string brand;
public:
    Item(): pret(0.0) {}
    Item(const std::string& name_,const std::string& brand_) : name{name_}, pret{0.0}, brand{brand_}{}
    Item(const std::string& name_,double pret_,const std::string& brand_): name{name_}, pret{pret_}, brand{brand_} {}
    Item(const Item& other) : name{other.name}, pret{other.pret}, brand{other.brand} {}
    const std::string& getName() const{ return this->name;}
    double getPret() const{ return this->pret;}

    //operator =
    Item& operator=(const Item& other) {
        this->name = other.name;
        this->pret = other.pret;
        this->brand = other.brand;
        return *this;
    }

    ~Item() = default;

    friend std::ostream& operator<<(std::ostream& os, const Item& item) {
        os<< item.name << "~" << item.brand << " ($" << item.pret << ")";
        return os;
    }

    bool operator==(const Item& other) const {
        return name == other.name && pret == other.pret && brand == other.brand;
    }
};

// std::string to_string(const Item& item) {
//     return item.getName();
// }

class raion {
    std::string name;
    std::vector <Item> items;
public:
    raion(const std::string& name_,const std::vector <Item>& Item_) : name{name_}, items{Item_} {}
    raion(const raion&  other) : name{other.name}, items{other.items} {}
    const std::string& getName() const{ return name;}
    raion& operator=(const raion& other) {
        name = other.name;
        items = other.items;
        return *this;
    }
    ~raion() = default;

    friend std::ostream & operator<<(std::ostream &os, const raion &obj) {

        tabulate::Table header;
        tabulate::Table tabel;

        header.add_row({ "Aisle: " + obj.name });
        header[0].format()
            .width(60)
            .font_align(tabulate::FontAlign::center)
            .font_style({tabulate::FontStyle::bold})
            .font_background_color(tabulate::Color::red)
            .font_color(tabulate::Color::white);

        size_t n = obj.items.size();
        size_t cols = 3;

        for (size_t i = 0; i < n; i += cols) {
            std::vector<std::string> row;
            for (size_t j = 0; j < cols; ++j) {
                if (i + j < n) {
                    std::stringstream ss;
                    ss << "[" << (i + j) << "] " << obj.items[i + j];
                    row.push_back(ss.str());
                } else {
                    row.push_back("");
                }
            }
            tabel.add_row(tabulate::Table::Row_t{row.begin(),row.end()});
        }

        tabel.format()
            .font_align(tabulate::FontAlign::center)
            .padding_top(0)
            .padding_bottom(0);

        os << header << "\n" << tabel << "\n";
        return os;
    }


    const std::vector <Item>& getItems() const { return items;}
};

class listaCumparaturi {
    std::vector <Item> items;
    int buget;
public:
    listaCumparaturi() {}
    explicit listaCumparaturi(const std::vector <Item>& items_, int buget_ = 0) : items{items_}, buget{buget_}{}
    listaCumparaturi(const listaCumparaturi& other) : items{other.items}, buget{other.buget} {}

    //operator =
    listaCumparaturi& operator=(const listaCumparaturi& other) {
        items = other.items;
        buget = other.buget;
        return *this;
    }
    const std::vector<Item>& getItems() const {return this->items; }

    int getBuget() const {return this->buget; }

    ~listaCumparaturi() = default;

    friend std::ostream& operator<<(std::ostream& os, const listaCumparaturi& lista) {
        for (const auto& item : lista.items) {
            os<<item<<", ";
        }
        os << "\n";
        return os;
    }

    void calculeazaBuget(listaCumparaturi& lista) {
        double suma = 0.0;
        if (lista.items.size()> 0) {

            for (const auto& item : lista.items) {
                suma += item.getPret();
            }
        }
        int bugetFinal = int(round(suma)) + 5;
        lista.buget = bugetFinal;
    }
    void stergeProdus(const Item& item) {
        auto it = std::find_if(items.begin(), items.end(), [&](const Item& item_) {
            return item_.getName() == item.getName();
        });

        if (it != items.end()) {
            items.erase(it);
        }
    }
};
class Joc;
class cosCumparaturi {
    listaCumparaturi lista;
    std::vector <Item> items;
    double totalPlata;
    public:
    cosCumparaturi(const listaCumparaturi &lista_, const std::vector<Item> &items_, double totalPlata_ = 0.0): lista(lista_),items(items_), totalPlata(totalPlata_) {}
    cosCumparaturi(const cosCumparaturi &other): lista(other.lista),items(other.items), totalPlata(other.totalPlata) {}
    explicit cosCumparaturi( double totalPlata_ ) : totalPlata(totalPlata_) {}

    cosCumparaturi& operator=(const cosCumparaturi &other) {
        if (this == &other)
            return *this;
        lista = other.lista;
        items = other.items;
        totalPlata = other.totalPlata;
        return *this;
    }
    double getTotalPlata() const {return totalPlata; }
    const listaCumparaturi& getLista() const {return lista;}
    const std::vector<Item>& getItems() const {return this->items;}

    ~cosCumparaturi() = default;

    friend std::ostream& operator<<(std::ostream& os, const cosCumparaturi& cos) {
        os <<"Your shopping list: "<< cos.lista;
        os << "Your shopping bag: ";
        for (const auto& item : cos.items) {
            os<< item<< ", ";
        }
        os << "\n";
        os << "Total price: " << cos.totalPlata<<"\n";
        os<<"\n";
        return os;
    }

    void sumadinCos() {
        if (items.empty()) {
            std::cout << "Shopping bag is empty 🤣\n";
        }
        else {
            totalPlata = 0.0;
            for (const auto& item: items) {
                totalPlata += item.getPret();
            }

            std::cout << "Your total is now: " << totalPlata << std::endl;
        }
    }
    void adaugaInCos(const Item &item) {
        items.push_back(item);
        lista.stergeProdus(item);
    }
};

class Magazin {
    std::vector <raion> raioane;
public:
    explicit Magazin(const std::vector<raion> &raioane_)
        : raioane(raioane_) {
    }
    Magazin() {}

    ~Magazin() = default;

    Magazin(const Magazin &other)
        : raioane(other.raioane) {
    }

    Magazin & operator=(const Magazin &other) {
        if (this == &other)
            return *this;
        raioane = other.raioane;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Magazin& magazin) {
        os << "raioane: ";
        for (const auto& items : magazin.raioane) {
            os << items << ", ";
        }
        os << "\n";
        return os;
    }

    const std::vector <raion>& getRaioane() const { return this->raioane;}
};

class Joc {
    std::string playerName;
    listaCumparaturi lista;
    int variantaJoc;
    int timp;
    std::atomic <bool> running = false;
public:
    Joc () {}
    explicit Joc(const std::string& playerName_) : playerName{playerName_}, lista{}, variantaJoc(0), timp(0){}
    explicit Joc(const std::string& playerName_, int varianta) : playerName(playerName_), variantaJoc{varianta}, timp(0){}
    Joc(const std::string& playerName_,const listaCumparaturi& lista_,int varianta) : playerName{playerName_}, lista{lista_}, variantaJoc{varianta}, timp(0) {}
    int getVarianta() const {return variantaJoc;}
    const listaCumparaturi& getLista() const { return this->lista; }

    void setTimp(int timp_) {
        timp = timp_;
    }

    Joc& operator=(const Joc& other) {
        lista = other.lista;
        variantaJoc = other.variantaJoc;
        timp = other.timp;
        playerName = other.playerName;
        return *this;
    }
    ~Joc() = default;

    friend std::ostream & operator<<(std::ostream &os, const Joc &obj) {
        os
               << "playerName: " << obj.playerName<< "\n"
               << " lista: " << obj.lista
               << " variantaJoc: " << obj.variantaJoc << "\n"
               << " timp: " << obj.timp<< "\n";
        return os;
    }

    void setareTimer() {
        if (variantaJoc == 0) {
            std::cout << playerName << " please select a game version!\n";
            return;
        }
        else if (variantaJoc ==1) {
            setTimp(30);
        }
        else if (variantaJoc ==2) {
            setTimp(15);
        }
        else if (variantaJoc ==3) {
            setTimp(20);
        }
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

};

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
                std::cout<<"Congrats! You lost!";
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
    std::random_device rd;
    std::mt19937 gen(rd());

    for (const raion& r : magazin.getRaioane()) {
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

class Stopwatch {
    std::chrono::high_resolution_clock::time_point start_time;
    bool running = false;
public:
    void start() {
        start_time = std::chrono::high_resolution_clock::now();
        running = true;
    }

    double elapsed() const {
        if (!running) return 0.0;
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = now - start_time;
        return elapsed.count();
    }
};

int main() {
    //paine
    Item itemulp1{"sourdough",5.0, "lidl"},itemulp2{"ciabatta", 12.0,"lidl"}, itemulp3{"focaccia",10.0,"lidl"};
    Item itemulp4{"brioche",6.0,"lidl"},itemulp5{"rye bread",11.0,"lidl"};
    Item itemulp6{"sourdough", 6.0, "kaufland"}, itemulp7{"ciabatta", 11.0, "kaufland"}, itemulp8{"focaccia", 12.0, "kaufland"};
    Item itemulp9{"brioche", 10.0, "kaufland"}, itemulp10{"rye bread",9.0, "kaufland"};
    Item itemulp11{"sourdough", 7.5, "auchan"}, itemulp12{"ciabatta", 13.0, "auchan"}, itemulp13{"focaccia", 11.0, "auchan"};
    Item itemulp14{"brioche",5.0, "auchan"}, itemulp15{"rye bread",8.0, "auchan"};
    //legume
    Item itemull1{"carrots",11.0,"lidl"}, itemull2{"tomatoes",5.0,"lidl"}, itemull3{"cucumbers",6.0,"lidl"};
    Item itemull4{"cabbage",3.0,"lidl"}, itemull5{"potatoes",7.5,"lidl"};
    Item itemull6{"carrots", 10.0, "kaufland"}, itemull7{"tomatoes", 7.0, "kaufland"}, itemull8{"cucumbers", 8.0, "kaufland"};
    Item itemull9{"cabbage", 4.0, "kaufland"}, itemull10{"potatoes", 6.5, "kaufland"};
    Item itemull11{"carrots", 9.0, "auchan"}, itemull12{"tomatoes", 6.0, "auchan"}, itemull13{"cucumbers", 7.0, "auchan"};
    Item itemull14{"cabbage", 3.5, "auchan"}, itemull15{"potatoes", 6.0, "auchan"};
    //fructe
    Item itemulf1{"apples", 10.0, "lidl"}, itemulf2{"bananas", 5.0, "lidl"}, itemulf3{"oranges", 7.0, "lidl"};
    Item itemulf4{"grapes", 12.0, "lidl"}, itemulf5{"strawberries", 14.0, "lidl"};
    Item itemulf6{"apples", 11.0, "kaufland"}, itemulf7{"bananas", 4.5, "kaufland"}, itemulf8{"oranges", 8.0, "kaufland"};
    Item itemulf9{"grapes", 13.0, "kaufland"}, itemulf10{"strawberries", 16.0, "kaufland"};
    Item itemulf11{"apples", 12.5, "auchan"}, itemulf12{"bananas", 5.5, "auchan"}, itemulf13{"oranges", 7.5, "auchan"};
    Item itemulf14{"grapes", 14.0, "auchan"}, itemulf15{"strawberries", 15.5, "auchan"};

    //bauturi
    Item itemulb1{"water", 1.5, "lidl"}, itemulb2{"juice", 3.0, "lidl"}, itemulb3{"soda", 3.5, "lidl"};
    Item itemulb4{"coffee", 4.5, "lidl"}, itemulb5{"tea", 2.5, "lidl"};
    Item itemulb6{"water", 1.7, "kaufland"}, itemulb7{"juice", 3.5, "kaufland"}, itemulb8{"soda", 3.8, "kaufland"};
    Item itemulb9{"coffee", 5.0, "kaufland"}, itemulb10{"tea", 2.8, "kaufland"};
    Item itemulb11{"water", 1.8, "auchan"}, itemulb12{"juice", 4.0, "auchan"}, itemulb13{"soda", 4.0, "auchan"};
    Item itemulb14{"coffee", 5.5, "auchan"}, itemulb15{"tea", 3.0, "auchan"};

    //kitchen utensils
    Item itemulk1{"spoon", 2.0, "lidl"}, itemulk2{"fork", 2.0, "lidl"}, itemulk3{"knife", 2.5, "lidl"};
    Item itemulk4{"cutting board", 5.0, "lidl"}, itemulk5{"pan", 10.0, "lidl"};
    Item itemulk6{"spoon", 2.5, "kaufland"}, itemulk7{"fork", 2.5, "kaufland"}, itemulk8{"knife", 3.0, "kaufland"};
    Item itemulk9{"cutting board", 5.5, "kaufland"}, itemulk10{"pan", 12.0, "kaufland"};
    Item itemulk11{"spoon", 3.0, "auchan"}, itemulk12{"fork", 3.0, "auchan"}, itemulk13{"knife", 3.5, "auchan"};
    Item itemulk14{"cutting board", 6.0, "auchan"}, itemulk15{"pan", 13.0, "auchan"};

    //gradina
    Item itemulg1{"fertilizer", 7.0, "lidl"}, itemulg2{"seeds", 5.0, "lidl"}, itemulg3{"watering can", 6.0, "lidl"};
    Item itemulg4{"garden gloves", 5.0, "lidl"}, itemulg5{"plant pots", 6.0, "lidl"};
    Item itemulg6{"fertilizer", 7.5, "kaufland"}, itemulg7{"seeds", 5.5, "kaufland"}, itemulg8{"watering can", 6.5, "kaufland"};
    Item itemulg9{"garden gloves", 5.5, "kaufland"}, itemulg10{"plant pots", 6.5, "kaufland"};
    Item itemulg11{"fertilizer", 8.0, "auchan"}, itemulg12{"seeds", 6.0, "auchan"}, itemulg13{"watering can", 7.0, "auchan"};
    Item itemulg14{"garden gloves", 6.0, "auchan"}, itemulg15{"plant pots", 7.0, "auchan"};

    //school supplies
    Item itemulss1{"notebook", 2.5, "lidl"}, itemulss2{"pen", 1.0, "lidl"}, itemulss3{"pencil", 0.8, "lidl"};
    Item itemulss4{"eraser", 0.6, "lidl"}, itemulss5{"ruler", 2.5, "lidl"};
    Item itemulss6{"notebook", 2.8, "kaufland"}, itemulss7{"pen", 1.2, "kaufland"}, itemulss8{"pencil", 1.0, "kaufland"};
    Item itemulss9{"eraser", 0.7, "kaufland"}, itemulss10{"ruler", 3.0, "kaufland"};
    Item itemulss11{"notebook", 3.0, "auchan"}, itemulss12{"pen", 1.5, "auchan"}, itemulss13{"pencil", 1.2, "auchan"};
    Item itemulss14{"eraser", 0.8, "auchan"}, itemulss15{"ruler", 3.5, "auchan"};

    //snacks
    Item itemuls1{"chips", 4.0, "lidl"}, itemuls2{"popcorn", 3.0, "lidl"}, itemuls3{"pretzels", 4.0, "lidl"};
    Item itemuls4{"nuts", 5.0, "lidl"}, itemuls5{"crackers", 3.5, "lidl"};
    Item itemuls6{"chips", 4.5, "kaufland"}, itemuls7{"popcorn", 3.5, "kaufland"}, itemuls8{"pretzels", 4.5, "kaufland"};
    Item itemuls9{"nuts", 5.5, "kaufland"}, itemuls10{"crackers", 4.0, "kaufland"};
    Item itemuls11{"chips", 5.0, "auchan"}, itemuls12{"popcorn", 4.0, "auchan"}, itemuls13{"pretzels", 5.0, "auchan"};
    Item itemuls14{"nuts", 6.0, "auchan"}, itemuls15{"crackers", 4.5, "auchan"};
    //carne
    Item itemulc1{"chicken breast", 18.0, "lidl"}, itemulc2{"ground beef", 15.0, "lidl"}, itemulc3{"pork chops", 17.0, "lidl"};
    Item itemulc4{"sausage", 12.0, "lidl"}, itemulc5{"steak", 24.0, "lidl"};
    Item itemulc6{"chicken breast", 20.0, "kaufland"}, itemulc7{"ground beef", 18.0, "kaufland"}, itemulc8{"pork chops", 19.0, "kaufland"};
    Item itemulc9{"sausage", 13.0, "kaufland"}, itemulc10{"steak", 26.0, "kaufland"};
    Item itemulc11{"chicken breast", 19.0, "auchan"}, itemulc12{"ground beef", 17.0, "auchan"}, itemulc13{"pork chops", 18.0, "auchan"};
    Item itemulc14{"sausage", 12.5, "auchan"}, itemulc15{"steak", 25.0, "auchan"};

    //dairy
    Item itemuld1{"milk", 2.5, "lidl"}, itemuld2{"cheese", 5.0, "lidl"}, itemuld3{"butter", 4.5, "lidl"};
    Item itemuld4{"yogurt", 2.0, "lidl"}, itemuld5{"cream", 3.0, "lidl"};
    Item itemuld6{"milk", 2.8, "kaufland"}, itemuld7{"cheese", 5.5, "kaufland"}, itemuld8{"butter", 4.8, "kaufland"};
    Item itemuld9{"yogurt", 2.2, "kaufland"}, itemuld10{"cream", 3.2, "kaufland"};
    Item itemuld11{"milk", 3.0, "auchan"}, itemuld12{"cheese", 5.8, "auchan"}, itemuld13{"butter", 4.2, "auchan"};
    Item itemuld14{"yogurt", 2.5, "auchan"}, itemuld15{"cream", 3.5, "auchan"};

    //dulciuri - sweets sw
    Item itemulsw1{"chocolate", 8.0, "lidl"}, itemulsw2{"gummy bears", 6.0, "lidl"}, itemulsw3{"biscuits", 5.0, "lidl"};
    Item itemulsw4{"candy bars", 7.0, "lidl"}, itemulsw5{"lollipops", 4.0, "lidl"};
    Item itemulsw6{"chocolate", 8.5, "kaufland"}, itemulsw7{"gummy bears", 7.0, "kaufland"}, itemulsw8{"biscuits", 6.0, "kaufland"};
    Item itemulsw9{"candy bars", 8.5, "kaufland"}, itemulsw10{"lollipops", 5.0, "kaufland"};
    Item itemulsw11{"chocolate", 9.0, "auchan"}, itemulsw12{"gummy bears", 7.5, "auchan"}, itemulsw13{"biscuits", 6.5, "auchan"};
    Item itemulsw14{"candy bars", 9.0, "auchan"}, itemulsw15{"lollipops", 5.5, "auchan"};

    std::vector<Item> bread_ = {itemulp1,itemulp2,itemulp3,itemulp4,itemulp5,itemulp6,itemulp7,itemulp8,itemulp9,itemulp10,itemulp11, itemulp12, itemulp13, itemulp14, itemulp15};
    raion raionb{"bread",bread_};

    std::vector<Item> vegetables_ = {itemull1,itemull2,itemull3,itemull4,itemull5, itemull6, itemull7, itemull8, itemull9, itemull10, itemull11, itemull12, itemull13, itemull14, itemull15};
    raion raionv{"vegetables", vegetables_};

    std::vector <Item> fruits_ = {itemulf1,itemulf2,itemulf3, itemulf4, itemulf5, itemulf6, itemulf7, itemulf8, itemulf9, itemulf10, itemulf11, itemulf12, itemulf13, itemulf14, itemulf15};
    raion raionf{"fruits", fruits_};

    std::vector <Item> drinks_ = {itemulb1, itemulb2, itemulb3, itemulb4, itemulb5, itemulb6, itemulb7, itemulb8, itemulb9, itemulb10, itemulb11, itemulb12, itemulb13, itemulb14, itemulb15};
    raion raiond{"drinks", drinks_};

    std::vector <Item> kitchen_ = {itemulk1, itemulk2, itemulk3, itemulk4, itemulk5, itemulk6, itemulk7, itemulk8, itemulk9, itemulk10, itemulk11, itemulk12, itemulk13, itemuld14, itemuld15};
    raion raionk{"Kitchen Utensils", kitchen_ };

    std::vector <Item> garden_ = {itemulg1, itemulg2, itemulg3, itemulg4, itemulg5, itemulg6, itemulg7, itemulg8, itemulg9, itemulg10, itemulg11, itemulg12, itemulg13, itemuld14, itemuld15};
    raion raiong{"garden", garden_};

    std::vector <Item> school_ = {itemulss1, itemulss2, itemulss3, itemulss4, itemulss5, itemulss6, itemulss7, itemulss8, itemulss9, itemulss10, itemulss11, itemulss12, itemulss13, itemulss14, itemulss15};
    raion raionss{"school supplies", school_};

    std::vector <Item> snacks_ = {itemuls1, itemuls2, itemuls3, itemuls4, itemuls5, itemuls6, itemuls7, itemuls8, itemuls9, itemuls10, itemuls11, itemuls12, itemuls13, itemuls14, itemuls15};
    raion raions{"snacks", snacks_};

    std::vector <Item> meat_ = {itemulc1, itemulc2, itemulc3, itemulc4, itemulc5, itemulc6, itemulc7, itemulc8, itemulc9, itemulc10, itemulc11, itemulc12, itemulc13, itemulc14, itemulc15};
    raion raionm{"meat", meat_};

    std::vector <Item> dairy_ = {itemuld1, itemuld2, itemuld3, itemuld4, itemuld5, itemuld6, itemuld7, itemuld8, itemuld9, itemuld10, itemuld11, itemuld12, itemuld13, itemuld14, itemuld15};
    raion raionda{"dairy", dairy_};

    std::vector <Item> sweets_ = {itemulsw1, itemulsw2, itemulsw3, itemulsw4, itemulsw5, itemulsw6, itemulsw7, itemulsw8, itemulsw9, itemulsw10, itemulsw11, itemulsw12, itemulsw13, itemulsw14, itemulsw15};
    raion raionsw{"sweets", sweets_};

    Magazin magazin{{raiond, raionf,raionv, raionb, raionk, raiong, raionss, raions, raionm, raionda, raionsw}};
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

        // listaInit.format()
        //     .border_top("═")
        //     .border_bottom("═")
        //     .border_left("║")
        //     .border_right("║")
        //     .corner_top_left("╔")
        //     .corner_top_right("╗")
        //     .corner_bottom_left("╚")
        //     .corner_bottom_right("╝");

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

                    // lista.format()
                    //     .border_top("═")
                    //     .border_bottom("═")
                    //     .border_left("║")
                    //     .border_right("║")
                    //     .corner_top_left("╔")
                    //     .corner_top_right("╗")
                    //     .corner_bottom_left("╚")
                    //     .corner_bottom_right("╝");

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