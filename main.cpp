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
    Items() {}
    Items(const std::string& name_,const std::string& brand_) : name{name_}, pret{0.0}, brand{brand_}{}
    Items(const std::string& name_, double pret_,const std::string& brand_): name{name_}, pret{pret_}, brand{brand_} {
        // std::cout<<"constructor de initializare";
    }
    Items(const Items& other) : name{other.name}, pret{other.pret}, brand{other.brand} {
        // std::cout<<"constructor copiere\n";
    }
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
};

class raion {
private:
    std::string name;
    std::vector <Items> Item;
public:
    raion(const std::string& name_, std::vector <Items> Item_) : name{name_}, Item{Item_} {}
    raion(const raion&  other) : name{other.name}, Item{other.Item} {}
    const std::string& getName() const{ return name;}
    void getItems() const {
        for (const auto& item : Item) {
            std::cout << item.getName() <<"~"<<item.getBrand()<< std::endl;
        }
    }
    raion& operator=(const raion& other) {
        name = other.name;
        Item = other.Item;
        return *this;
    }
    ~raion() = default;

    friend std::ostream& operator<<(std::ostream& os, const raion& raion) {
        os << raion.name<< " ";
        for (const auto& item : raion.Item) {
            os << item.getName()<<" ";
        }
        os << " \n";
        return os;
    }
};

class listaCumparaturi {
private:
    std::vector <Items> items;
    int buget;
public:
    listaCumparaturi(){}
    listaCumparaturi(std::vector <Items> items_) : items{items_}{}
    listaCumparaturi(std::vector <Items> items_, int buget_) : items{items_}, buget{buget_} {}
    listaCumparaturi(const listaCumparaturi& other) : items{other.items}, buget{other.buget} {}
    int getBuget() const{ return this->buget;}
    // const std::vector& getItems() const { return this-> items;}???
    void getItem() const {
        for (const auto& item: items) {
            std::cout << item.getName() << "\n";
        }
    }
    //operator =
    listaCumparaturi& operator=(const listaCumparaturi& other) {
        items = other.items;
        buget = other.buget;
        std::cout << "operator= copiere Items\n";
        return *this;
    }
    const std::vector<Items>& getItems() const {return this->items; }

    ~listaCumparaturi() = default;

    friend std::ostream& operator<<(std::ostream& os, const listaCumparaturi& lista) {
        os<<"Buget: "<< lista.buget<<"\n";
        for (const auto& item : lista.items) {
            os<<item.getName()<<" ";
        }
        os << "\n";
        return os;
    }
};

class cosCumparaturi {
    listaCumparaturi lista;
    std::vector <Items> items;
    public:
    cosCumparaturi(const listaCumparaturi &lista_, const std::vector<Items> &items_): lista(lista_),items(items_) {}
    cosCumparaturi(const cosCumparaturi &other): lista(other.lista),items(other.items) {}

    cosCumparaturi& operator=(const cosCumparaturi &other) {
        if (this == &other)
            return *this;
        lista = other.lista;
        items = other.items;
        return *this;
    }

    void getLista() {
        lista.getItem();
    }

    ~cosCumparaturi() = default;

    // friend std::ostream& operator<<(std::ostream& os, const cosCumparaturi& cos) {
    //     for ( const auto& item : cos.lista) {
    //         os << item.getName()<<" ";
    //     }
    //     os << "\n";
    //     for (const auto& item : cos.items) {
    //         os << item.getName()<<" ";
    //     }
    //     os << "\n";
    //     return os;
    // }
};

class Joc {
private:
    std::string playerName;
    listaCumparaturi lista;
    int variantaJoc;
    int timp;
    int buget;
public:
    explicit Joc(const std::string& playerName_) : playerName{playerName_} {}
    Joc(int timp_, int buget_) : timp{timp_}, buget(buget_) {}
    explicit Joc(int timp_) : playerName("Default"), variantaJoc(0),timp{timp_} {}
    Joc(const std::string& playerName_,const listaCumparaturi& lista_,int varianta) : playerName{playerName_}, lista{lista_}, variantaJoc{varianta}{}

    int getVarianta() const{ return this->variantaJoc; }
    const listaCumparaturi& getLista() const{ return this->lista;}
    const std::string& getPlayer() const { return this->playerName; }
    int getTimer() const{ return this->timp; }
    int getBuget() const{ return this->buget; }

    void setTimp(int timp_) {
        timp = timp_;
    }

    void setBuget(int buget_) {
        buget = buget_;
    }

    Joc& operator=(const Joc& other) {
        if (this == &other)
            return *this;
        lista = other.lista;
        variantaJoc = other.variantaJoc;
        timp = other.timp;
        buget = other.buget;
        playerName = other.playerName;
        return *this;
    }
    ~Joc() = default;

    // friend std::ostream& operator<<(std::ostream& os, const Joc& joc) {
    //     os<< "Player: "<< joc.playerName << " ";
    //     os<< "Varianta joc: "<< joc.variantaJoc<< " ";
    //     os<< "Timp: "<< joc.timp<< " ";
    //     os<< "Buget: "<< joc.buget<< " ";
    //     os<< "lista cumparaturi : ";
    //     for (const auto& item : joc.lista) {
    //         os<< item.getName()<<" ";
    //     }
    //     os << "\n";
    //     return os;
    // }

    friend std::ostream & operator<<(std::ostream &os, const Joc &obj) {
        return os
               << "playerName: " << obj.playerName
               << " lista: " << obj.lista
               << " variantaJoc: " << obj.variantaJoc
               << " timp: " << obj.timp
               << " buget: " << obj.buget;
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
        }
    }
    //aici o sa completez cu varianta cand lista este goala dar  cosul de  cumparaturi
    //este plin deci jocul se termina
    //aceasta este varianta cand lista este goala inainte de a incepe jocul deci
    //ar trebui ca  jocul sa nu porneasca.
    void listaGoala() const {
        if (lista.getItems().empty()) {
            std::cout << "Lista de cumparaturi este goala. \n";
            return;
        }
        else {
            std::cout<<"Jocul poate incepe!!!!!!!!!!!!!!!!!!";
        }
    }
};

int main() {
    Items itemulp1{"sourdough", "lidl"},itemulp2{"ciabatta", 12.0,"lidl"}, itemulp3{"focaccia",10.0,"lidl"},itemulp4{"brioche",6.0,"lidl"},itemulp5{"rye bread",11.0,"lidl"},

        itemull1{"carrots",11.0,"lidl"},itemull2{"tomatoes",5.0,"lidl"},itemull3{"cucumbers",6.0,"lidl"},itemull4{"cabbage",3.0,"lidl"},itemull5{"potatoes",7.5,"lidl"},
        itemulf1{"banane",5,"kaufland"};
    Items itemulf2;
    itemulf2=itemulp1;
    // std::cout<<itemulf2.getName()<<"\n";
    std::cout << itemulp1.getName()<<"~"<<itemulp1.getBrand()<<"\n";
    // std::cout<<"\n";

    std::vector<Items> var1 = {itemulp1,itemull1};
    std::vector<Items> var2 = {itemulf1,itemull1};
    std::vector<Items> var3 = {itemulp1,itemulf1};
    listaCumparaturi lista1{var1,35},lista2{var2,70};
    std::cout<<"lista 1:\n";
    lista1.getItem();
    // std::cout<<lista1.getBuget()<<"\n";
    std::cout<<"lista 2:\n";
    lista2.getItem();
    // std::cout<<lista2.getBuget()<<"\n";
    std::cout<<"\n";

    cosCumparaturi cos1{lista1,{}};
    std::cout<<"ce trebuie sa fie in cos la finalul jocului: ";
    cos1.getLista();
    std::cout<<"\n";

    std::vector<Items> bread_ = {itemulp1,itemulp2,itemulp3,itemulp4,itemulp5};
    raion raion1{"bread",bread_};
    std::cout<<raion1.getName()<<":\n";
    raion1.getItems();
    std::cout<<"\n";

    std::vector<Items> vegetables_ = {itemull1,itemull2,itemull3,itemull4,itemull5};
    raion raion2{"vegetables", vegetables_};
    std::cout<<raion2.getName()<<":\n";
    raion2.getItems();
    std::cout<<"\n";

    Joc start("Alina", lista1, 1);
    start.setareTimer();
    std::cout<<start.getTimer()<<"\n";
    start.verificarePret();
    start.listaGoala();
    std::cout<<"\n";

    std::cout<<start;

    return 0;
}