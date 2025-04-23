//
// Created by avoro on 4/23/2025.
//

#include "listaCumparaturi.h"

listaCumparaturi::listaCumparaturi() {}

listaCumparaturi::listaCumparaturi(const std::vector<Item> &items_, int buget_): items{items_}, buget{buget_} {}

listaCumparaturi::listaCumparaturi(const listaCumparaturi &other): items{other.items}, buget{other.buget} {}

listaCumparaturi & listaCumparaturi::operator=(const listaCumparaturi &other) {
    items = other.items;
    buget = other.buget;
    return *this;
}

const std::vector<Item> & listaCumparaturi::getItems() const {return this->items; }

int listaCumparaturi::getBuget() const {return this->buget; }

listaCumparaturi::~listaCumparaturi() = default;

void listaCumparaturi::calculeazaBuget(listaCumparaturi &lista) {
    double suma = 0.0;
    if (lista.items.size()> 0) {

        for (const auto& item : lista.items) {
            suma += item.getPret();
        }
    }
    int bugetFinal = int(round(suma)) + 5;//adaug 5 pentru ca bugetul sa nu fie restrictionat de brandul obiectelor din lista generata random
    //si sa pot alege de exemplu daca nu am destul timp si un obiect putin mai scump in cazul in care nu il vad pe cel mai ieftin
    //intrucat la mine sunt items cu acelasi nume dar brand diferit si pretul difera
    lista.buget = bugetFinal;
}

void listaCumparaturi::stergeProdus(const Item &item) {
    auto it = std::find_if(items.begin(), items.end(), [&](const Item& item_) {
        return item_.getName() == item.getName();
    });

    if (it != items.end()) {
        items.erase(it);
    }
}

std::ostream & operator<<(std::ostream &os, const listaCumparaturi &lista) {
    for (const auto& item : lista.items) {
        os<<item<<", ";
    }
    os << "\n";
    return os;
}
