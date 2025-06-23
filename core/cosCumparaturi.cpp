//
// Created by avoro on 4/23/2025.
//

#include "cosCumparaturi.h"

cosCumparaturi::cosCumparaturi(const listaCumparaturi &lista_, const std::vector<Item> &items_, double totalPlata_):items{items_}, lista(lista_), totalPlata(totalPlata_) {}

cosCumparaturi::cosCumparaturi(const cosCumparaturi &other):  items{other.items}, lista(other.lista), totalPlata(other.totalPlata) {}

cosCumparaturi::cosCumparaturi(double totalPlata_): totalPlata(totalPlata_) {}

cosCumparaturi & cosCumparaturi::operator=(const cosCumparaturi &other) {
    if (this != &other) {
        items = other.items;
        lista = other.lista;
        totalPlata = other.totalPlata;
    }
    return *this;
}

double cosCumparaturi::getTotalPlata() const {return totalPlata; }

const listaCumparaturi & cosCumparaturi::getLista() const {return lista;}

cosCumparaturi::~cosCumparaturi() = default;

void cosCumparaturi::calculTotal() {
    if (items.empty()) {
        std::cout << "Shopping bag is empty 🤣\n";
    }
    else {
        totalPlata = 0.0;
        for (const auto& item: items) {
            if (item.getPret() < 0) {
                //exceptie in cazul in care pretul este mai mic decat 0
                std::string msg;
                msg = " is the invalid price for the " + item.getName();
                throw PretInvalid (item.getPret(),msg );
            }
            totalPlata += item.getPret();
        }

        std::cout << "Your total is now: " << totalPlata << std::endl;
    }
}

void cosCumparaturi::adaugaInCos(const Item &item) {
    items.push_back(item);
    lista.stergeProdus(item);
}

std::ostream & operator<<(std::ostream &os, const cosCumparaturi &cos) {
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

const std::vector<Item>& cosCumparaturi::getItems() const {
    return items;
}
