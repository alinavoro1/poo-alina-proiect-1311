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
            os << item<< " ";
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
            os<<item<<" ";
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
               << "playerName: " << obj.playerName
               << " lista: " << obj.lista
               << " variantaJoc: " << obj.variantaJoc
               << " timp: " << obj.timp
               << " buget: " << obj.buget;
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
        for (const auto& item : lista.getItems()) {
            if (item.getPret() == 0){
                std::cout << "This version is not available right now\n";
            }
            else{
                std::cout << "This version is available right now\n";
            }
        }
    }

};

void listaGoala(const Joc& joc, const cosCumparaturi& cos) {
    if (joc.getLista().getItems().empty()) {
        // std::cout << "Lista de cumparaturi este goala. \n";
        if(cos.getItems().empty()) {
            std::cout << "Jocul are o problema....\n";
        }
        else if(cos.getItems() == cos.getLista().getItems()){
            std::cout<< "Bravo ai castigat.🙄";
        }
    else if (cos.getItems().size() != 0 && cos.getItems() != cos.getLista().getItems()){
        std::cout<<"NU AI ADUNAT TOT.:P";
    }
    else if(cos.getItems().size() == 0 and joc.getLista().getItems().size()!=0){
        std::cout<<"Jocul poate incepe!!!!!!!!!!!!!!!!!!";
    }
}
}

int main(){
    Items itemulp1{"sourdough",5.0, "lidl"},itemulp2{"ciabatta", 12.0,"lidl"}, itemulp3{"focaccia",10.0,"lidl"},itemulp4{"brioche",6.0,"lidl"},itemulp5{"rye bread",11.0,"lidl"},

        itemull1{"carrots",11.0,"lidl"},itemull2{"tomatoes",5.0,"lidl"},itemull3{"cucumbers",6.0,"lidl"},itemull4{"cabbage",3.0,"lidl"},itemull5{"potatoes",7.5,"lidl"},
        itemulf1{"banane",5,"kaufland"};
    Items itemulf2;
    itemulf2=itemulp1;
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

    std::vector<Items> bread_ = {itemulp1,itemulp2,itemulp3,itemulp4,itemulp5};
    raion raion1{"bread",bread_};
    std::cout<<raion1;
    std::cout<<"\n";

    std::vector<Items> vegetables_ = {itemull1,itemull2,itemull3,itemull4,itemull5};
    raion raion2{"vegetables", vegetables_};
    std::cout<<raion2;
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

