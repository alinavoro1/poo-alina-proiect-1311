#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class Items {
private:
    std::string name;
    double pret;
    std::string brand;
public:
    Items(): pret(0.0) {}
    Items(const std::string& name_,const std::string& brand_) : name{name_}, pret{0.0}, brand{brand_}{}
    Items(const std::string& name_,double pret_,const std::string& brand_): name{name_}, pret{pret_}, brand{brand_} {}
    Items(const Items& other) : name{other.name}, pret{other.pret}, brand{other.brand} {}
    const std::string& getName() const{ return this->name;}
    double getPret() const{ return this->pret;}
    const std::string& getBrand() const{ return this->brand;}

    //operator =
    Items& operator=(const Items& other) {
        this->name = other.name;
        this->pret = other.pret;
        this->brand = other.brand;
        std::cout <<"op=\n";
        return *this;
    }

    ~Items() = default;

    friend std::ostream& operator<<(std::ostream& os, const Items& item) {
        os<< item.name << "~" << item.brand << " ($" << item.pret << ")";
        return os;
    }

    bool operator==(const Items& other) const {
        return name == other.name && pret == other.pret && brand == other.brand;
    }
};

class raion {
private:
    std::string name;
    std::vector <Items> Item;
public:
    raion(const std::string& name_,const std::vector <Items>& Item_) : name{name_}, Item{Item_} {}
    raion(const raion&  other) : name{other.name}, Item{other.Item} {}
    const std::string& getName() const{ return name;}
    raion& operator=(const raion& other) {
        name = other.name;
        Item = other.Item;
        return *this;
    }
    ~raion() = default;

    friend std::ostream & operator<<(std::ostream &os, const raion &obj) {
        os<< "name: " << obj.name<< "\n";
        for (const auto& item : obj.Item) {
            os << item<< ", ";
        }
        return os;
    }
};

class listaCumparaturi {
private:
    std::vector <Items> items;
    // int buget;
public:
    listaCumparaturi() : items{} {}
    explicit listaCumparaturi(const std::vector <Items>& items_) : items{items_}{}
    listaCumparaturi(const listaCumparaturi& other) : items{other.items} {}

    //operator =
    listaCumparaturi& operator=(const listaCumparaturi& other) {
        items = other.items;
        std::cout << "operator= copiere Items\n";
        return *this;
    }
    const std::vector<Items>& getItems() const {return this->items; }

    ~listaCumparaturi() = default;

    friend std::ostream& operator<<(std::ostream& os, const listaCumparaturi& lista) {
        for (const auto& item : lista.items) {
            os<<item<<", ";
        }
        os << "\n";
        return os;
    }
};
class Joc;
class cosCumparaturi {
    listaCumparaturi lista;
    std::vector <Items> items;
    int totalPlata;
    public:
    cosCumparaturi(const listaCumparaturi &lista_, const std::vector<Items> &items_, int totalPlata_ = 0): lista(lista_),items(items_), totalPlata(totalPlata_) {}
    cosCumparaturi(const cosCumparaturi &other): lista(other.lista),items(other.items), totalPlata(other.totalPlata) {}

    cosCumparaturi& operator=(const cosCumparaturi &other) {
        if (this == &other)
            return *this;
        lista = other.lista;
        items = other.items;
        totalPlata = other.totalPlata;
        return *this;
    }
    const listaCumparaturi& getLista() const {return lista;}
    const std::vector<Items>& getItems() const {return this->items;}

    ~cosCumparaturi() = default;

    friend std::ostream& operator<<(std::ostream& os, const cosCumparaturi& cos) {
        os <<"cosul trebuie sa contina: "<< cos.lista;
        os << "total plata: " << cos.totalPlata<<"\n";
        for (const auto& item : cos.items) {
            os<< item<< "\n";
        }
        os<<"\n";
        return os;
    }

    double sumadinCos() {
        double suma = 0;
        for (const auto& item: items){
            suma+=item.getPret();
        }
    return suma;}
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
};

class Joc {
private:
    std::string playerName;
    listaCumparaturi lista;
    int variantaJoc;
    int timp;
    int buget;
public:
    explicit Joc(const std::string& playerName_) : playerName{playerName_}, lista{}, variantaJoc(0), timp(0), buget(0) {}
    Joc(const std::string& playerName_,const listaCumparaturi& lista_,int varianta) : playerName{playerName_}, lista{lista_}, variantaJoc{varianta}, timp(0), buget(0) {}

    int getVarianta() const{ return this->variantaJoc; }
    const std::string& getPlayer() const { return this->playerName; }
    int getTimer() const{ return this->timp; }
    int getBuget() const{ return this->buget; }
    const listaCumparaturi& getLista() const { return this->lista; }

    void setTimp(int timp_) {
        timp = timp_;
    }

    void setBuget(int buget_) {
        buget = buget_;
    }

    Joc& operator=(const Joc& other) {
        lista = other.lista;
        variantaJoc = other.variantaJoc;
        timp = other.timp;
        buget = other.buget;
        playerName = other.playerName;
        return *this;
    }
    ~Joc() = default;

    friend std::ostream & operator<<(std::ostream &os, const Joc &obj) {
        os
               << "playerName: " << obj.playerName<< "\n"
               << " lista: " << obj.lista
               << " variantaJoc: " << obj.variantaJoc << "\n"
               << " timp: " << obj.timp<< "\n"
               << " buget: " << obj.buget << "\n";
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
            setBuget(150);
        }
    }

    void verificarePret() const {
        int ok =0;
        for (const auto& item : lista.getItems()) {
            if (item.getPret() == 0){
                ok++;}
        }
        if(ok == 0){
            std::cout << "this version is available right now.\n";
    }
        else{
            std::cout << "this version is not availble right now.\n";}
}

};

void listaGoala(const Joc& joc, const cosCumparaturi& cos) {
    if (joc.getLista().getItems().empty()) {
        // std::cout << "Lista de cumparaturi este goala. \n";
        if(cos.getItems().empty()) {
            std::cout << "Jocul are o problema....\n";
            return;
        }
        else if(cos.getItems() == cos.getLista().getItems()){
            std::cout<< "Bravo ai castigat.🙄\n"; //o sa adaug si un if pt varianta 3 de  joc sa verific daca suma din cos se  incadreaza in buget.
            return;
        }
}
    else if(cos.getItems().empty()!=true){
        std::cout<<"NU AI ADUNAT TOT.:P\n";
              return;
    }
    else{
    std::cout<<"Jocul poate incepe!!!!!!!!!!!!!!!!!!\n";}

}

int main(){
//paine
    Items itemulp1{"sourdough",5.0, "lidl"},itemulp2{"ciabatta", 12.0,"lidl"}, itemulp3{"focaccia",10.0,"lidl"};
    Items itemulp4{"brioche",6.0,"lidl"},itemulp5{"rye bread",11.0,"lidl"};
    Items itemulp6{"sourdough", 6.0, "kaufland"}, itemulp7{"ciabatta", 11.0, "kaufland",}, itemulp8{"focaccia", 12.0, "kaufland"};
    Items itemulp9{"brioche", 10.0, "kaufland"}, itemulp10{"rye bread",9.0, "kaufland"};
    Items itemulp11{"sourdough", 7.5, "auchan"}, itemulp12{"ciabatta", 13.0, "auchan"}, itemulp13{"focaccia", 11.0, "auchan"};
    Items itemulp14{"brioche",5.0, "auchan"}, itemulp15{"rye bread",8.0, "auchan"};
//legume
    Items itemull1{"carrots",11.0,"lidl"}, itemull2{"tomatoes",5.0,"lidl"}, itemull3{"cucumbers",6.0,"lidl"};
    Items itemull4{"cabbage",3.0,"lidl"}, itemull5{"potatoes",7.5,"lidl"};
    Items itemull6{"carrots", 10.0, "kaufland"}, itemull7{"tomatoes", 7.0, "kaufland"}, itemull8{"cucumbers", 8.0, "kaufland"};
    Items itemull9{"cabbage", 4.0, "kaufland"}, itemull10{"potatoes", 6.5, "kaufland"};
    Items itemull11{"carrots", 9.0, "auchan"}, itemull12{"tomatoes", 6.0, "auchan"}, itemull13{"cucumbers", 7.0, "auchan"};
    Items itemull14{"cabbage", 3.5, "auchan"}, itemull15{"potatoes", 6.0, "auchan"};
//fructe
    Items itemulf1{"apples", 10.0, "lidl"}, itemulf2{"bananas", 5.0, "lidl"}, itemulf3{"oranges", 7.0, "lidl"};
    Items itemulf4{"grapes", 12.0, "lidl"}, itemulf5{"strawberries", 14.0, "lidl"};
    Items itemulf6{"apples", 11.0, "kaufland"}, itemulf7{"bananas", 4.5, "kaufland"}, itemulf8{"oranges", 8.0, "kaufland"};
    Items itemulf9{"grapes", 13.0, "kaufland"}, itemulf10{"strawberries", 16.0, "kaufland"};
    Items itemulf11{"apples", 12.5, "auchan"}, itemulf12{"bananas", 5.5, "auchan"}, itemulf13{"oranges", 7.5, "auchan"};
    Items itemulf14{"grapes", 14.0, "auchan"}, itemulf15{"strawberries", 15.5, "auchan"};
    Items itemulf16;
    itemulf16=itemulp1;
//bauturi
    Items itemulb1{"water", 1.5, "lidl"}, itemulb2{"juice", 3.0, "lidl"}, itemulb3{"soda", 3.5, "lidl"};
    Items itemulb4{"coffee", 4.5, "lidl"}, itemulb5{"tea", 2.5, "lidl"};
    Items itemulb6{"water", 1.7, "kaufland"}, itemulb7{"juice", 3.5, "kaufland"}, itemulb8{"soda", 3.8, "kaufland"};
    Items itemulb9{"coffee", 5.0, "kaufland"}, itemulb10{"tea", 2.8, "kaufland"};
    Items itemulb11{"water", 1.8, "auchan"}, itemulb12{"juice", 4.0, "auchan"}, itemulb13{"soda", 4.0, "auchan"};
    Items itemulb14{"coffee", 5.5, "auchan"}, itemulb15{"tea", 3.0, "auchan"};

//kitchen utensils
    Items itemulk1{"spoon", 2.0, "lidl"}, itemulk2{"fork", 2.0, "lidl"}, itemulk3{"knife", 2.5, "lidl"};
    Items itemulk4{"cutting board", 5.0, "lidl"}, itemulk5{"pan", 10.0, "lidl"};
    Items itemulk6{"spoon", 2.5, "kaufland"}, itemulk7{"fork", 2.5, "kaufland"}, itemulk8{"knife", 3.0, "kaufland"};
    Items itemulk9{"cutting board", 5.5, "kaufland"}, itemulk10{"pan", 12.0, "kaufland"};
    Items itemulk11{"spoon", 3.0, "auchan"}, itemulk12{"fork", 3.0, "auchan"}, itemulk13{"knife", 3.5, "auchan"};
    Items itemulk14{"cutting board", 6.0, "auchan"}, itemulk15{"pan", 13.0, "auchan"};

//gradina
    Items itemulg1{"fertilizer", 7.0, "lidl"}, itemulg2{"seeds", 5.0, "lidl"}, itemulg3{"watering can", 6.0, "lidl"};
    Items itemulg4{"garden gloves", 5.0, "lidl"}, itemulg5{"plant pots", 6.0, "lidl"};
    Items itemulg6{"fertilizer", 7.5, "kaufland"}, itemulg7{"seeds", 5.5, "kaufland"}, itemulg8{"watering can", 6.5, "kaufland"};
    Items itemulg9{"garden gloves", 5.5, "kaufland"}, itemulg10{"plant pots", 6.5, "kaufland"};
    Items itemulg11{"fertilizer", 8.0, "auchan"}, itemulg12{"seeds", 6.0, "auchan"}, itemulg13{"watering can", 7.0, "auchan"};
    Items itemulg14{"garden gloves", 6.0, "auchan"}, itemulg15{"plant pots", 7.0, "auchan"};

//school supplies
    Items itemuss1{"notebook", 2.5, "lidl"}, itemuss2{"pen", 1.0, "lidl"}, itemuss3{"pencil", 0.8, "lidl"};
    Items itemuss4{"eraser", 0.6, "lidl"}, itemuss5{"ruler", 2.5, "lidl"};
    Items itemuss6{"notebook", 2.8, "kaufland"}, itemuss7{"pen", 1.2, "kaufland"}, itemuss8{"pencil", 1.0, "kaufland"};
    Items itemuss9{"eraser", 0.7, "kaufland"}, itemuss10{"ruler", 3.0, "kaufland"};
    Items itemuss11{"notebook", 3.0, "auchan"}, itemuss12{"pen", 1.5, "auchan"}, itemuss13{"pencil", 1.2, "auchan"};
    Items itemuss14{"eraser", 0.8, "auchan"}, itemuss15{"ruler", 3.5, "auchan"};

//snacks
    Items itemuls1{"chips", 4.0, "lidl"}, itemuls2{"popcorn", 3.0, "lidl"}, itemuls3{"pretzels", 4.0, "lidl"};
    Items itemuls4{"nuts", 5.0, "lidl"}, itemuls5{"crackers", 3.5, "lidl"};
    Items itemuls6{"chips", 4.5, "kaufland"}, itemuls7{"popcorn", 3.5, "kaufland"}, itemuls8{"pretzels", 4.5, "kaufland"};
    Items itemuls9{"nuts", 5.5, "kaufland"}, itemuls10{"crackers", 4.0, "kaufland"};
    Items itemuls11{"chips", 5.0, "auchan"}, itemuls12{"popcorn", 4.0, "auchan"}, itemuls13{"pretzels", 5.0, "auchan"};
    Items itemuls14{"nuts", 6.0, "auchan"}, itemuls15{"crackers", 4.5, "auchan"};
//carne
    Items itemulc1{"chicken breast", 18.0, "lidl"}, itemulc2{"ground beef", 15.0, "lidl"}, itemulc3{"pork chops", 17.0, "lidl"};
    Items itemulc4{"sausage", 12.0, "lidl"}, itemulc5{"steak", 24.0, "lidl"};
    Items itemulc6{"chicken breast", 20.0, "kaufland"}, itemulc7{"ground beef", 18.0, "kaufland"}, itemulc8{"pork chops", 19.0, "kaufland"};
    Items itemulc9{"sausage", 13.0, "kaufland"}, itemulc10{"steak", 26.0, "kaufland"};
    Items itemulc11{"chicken breast", 19.0, "auchan"}, itemulc12{"ground beef", 17.0, "auchan"}, itemulc13{"pork chops", 18.0, "auchan"};
    Items itemulc14{"sausage", 12.5, "auchan"}, itemulc15{"steak", 25.0, "auchan"};

//dairy
    Items itemuld1{"milk", 2.5, "lidl"}, itemuld2{"cheese", 5.0, "lidl"}, itemuld3{"butter", 4.5, "lidl"};
    Items itemuld4{"yogurt", 2.0, "lidl"}, itemuld5{"cream", 3.0, "lidl"};
    Items itemuld6{"milk", 2.8, "kaufland"}, itemuld7{"cheese", 5.5, "kaufland"}, itemuld8{"butter", 4.8, "kaufland"};
    Items itemuld9{"yogurt", 2.2, "kaufland"}, itemuld10{"cream", 3.2, "kaufland"};
    Items itemuld11{"milk", 3.0, "auchan"}, itemuld12{"cheese", 5.8, "auchan"}, itemuld13{"butter", 4.2, "auchan"};
    Items itemuld14{"yogurt", 2.5, "auchan"}, itemuld15{"cream", 3.5, "auchan"};


//dulciuri - sweets sw
    Items itemulsw1{"chocolate", 8.0, "lidl"}, itemulsw2{"gummy bears", 6.0, "lidl"}, itemulsw3{"biscuits", 5.0, "lidl"};
    Items itemulsw4{"candy bars", 7.0, "lidl"}, itemulsw5{"lollipops", 4.0, "lidl"};
    Items itemulsw6{"chocolate", 8.5, "kaufland"}, itemulsw7{"gummy bears", 7.0, "kaufland"}, itemulsw8{"biscuits", 6.0, "kaufland"};
    Items itemulsw9{"candy bars", 8.5, "kaufland"}, itemulsw10{"lollipops", 5.0, "kaufland"};
    Items itemulsw11{"chocolate", 9.0, "auchan"}, itemulsw12{"gummy bears", 7.5, "auchan"}, itemulsw13{"biscuits", 6.5, "auchan"};
    Items itemulsw14{"candy bars", 9.0, "auchan"}, itemulsw15{"lollipops", 5.5, "auchan"};



    std::cout << itemulp1.getName()<<"~"<<itemulp1.getBrand()<<"\n";
    std::cout<<"\n";

    std::vector<Items> var1 = {itemulp1,itemull1};
    std::vector<Items> var2 = {itemulf1,itemull1};
    // std::vector<Items> var3 = {itemulp1,itemulf1};
    listaCumparaturi lista1{var1},lista2{var2};
    std::cout<<"lista 1:\n";
    std::cout<< lista1;

    std::cout<<"lista 2:\n";
    std::cout<< lista2;
    std::cout<<"\n";

    cosCumparaturi cos1{lista1,{itemulf1,itemulf2}, 12};
    std::cout<< cos1;
    std::cout<<"suma din cos este: \n";
    std::cout<<cos1.sumadinCos()<<"\n";

    std::vector<Items> bread_ = {itemulp1,itemulp2,itemulp3,itemulp4,itemulp5,itemulp6,itemulp7,itemulp8,itemulp9,itemulp10,itemulp11, itemulp12, itemulp13, itemulp14, itemulp15};
    raion raionp{"bread",bread_};
    std::cout<<raionp;
    std::cout<<"\n";

    std::vector<Items> vegetables_ = {itemull1,itemull2,itemull3,itemull4,itemull5, itemull6, itemull7, itemull8, itemull9, itemull10, itemull11, itemull12, itemull13, itemull14, itemull15};
    raion raionl{"vegetables", vegetables_};
    std::cout<<raionl;
    std::cout<<"\n";

    std::vector <Items> fruits_ = {itemulf1,itemulf2,itemulf3, itemulf4, itemulf5, itemulf6, itemulf7, itemulf8, itemulf9, itemulf10, itemulf11, itemulf12, itemulf13, itemulf14, itemulf15};
    raion raionf{"fruits", fruits_};
    std::cout<<raionf;
    std::cout<<"\n";

    std::vector <Items> drinks_ = {itemulb1, itemulb2, itemulb3, itemulb4, itemulb5, itemulb6, itemulb7, itemulb8, itemulb9, itemulb10, itemulb11, itemulb12, itemulb13, itemuld14, itemuld15};
    raion raionb{"drinks", drinks_};
    std::cout<<raionb;
    std::cout<<"\n";

    Magazin magazin{{raionb, raionf,raionl, raionp}};
    std::cout<<magazin;
    std::cout<<"\n";

    Joc start("Alina", lista1, 3);
    std::cout<<start;
    start.setareTimer();
    std::cout<<start.getPlayer()<<"\n";
    std::cout<<start.getVarianta()<<"\n";
    std::cout<<start.getTimer()<<"\n";
    std::cout<<start.getBuget()<<"\n";
    start.verificarePret();
    listaGoala(start, cos1);
    std::cout<<"\n";
    std::cout<<start;

    return 0;
}

