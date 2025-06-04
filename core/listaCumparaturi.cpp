//
// Created by avoro on 4/23/2025.
//

#include "listaCumparaturi.h"

listaCumparaturi::listaCumparaturi(): buget(0) {}

listaCumparaturi::listaCumparaturi(const std::vector<Item> &items_, int buget_): items{items_}, buget{buget_} {}

listaCumparaturi::listaCumparaturi(int buget_): buget(buget_) {

}

listaCumparaturi::listaCumparaturi(const listaCumparaturi &other): items{other.items}, buget{other.buget} {}

listaCumparaturi & listaCumparaturi::operator=(const listaCumparaturi &other) {
    if (this != &other) {
        items = other.items;
        buget = other.buget;
    }
    return *this;
}

int listaCumparaturi::getBuget() const {
    return buget;
}

listaCumparaturi::~listaCumparaturi() = default;

void listaCumparaturi::stergeProdus(const Item &item) {
    auto it = std::find_if(items.begin(), items.end(), [&](const Item& item_) {
        return item_.getName() == item.getName();
    });
    if (it != items.end()) {
        items.erase(it);
    }
}

void listaCumparaturi::calculTotal() {
    double total = 0;
    for (const auto& item : items) {
        total += item.getPret();
    }

    int bugetFinal = int(round(total)) + 5;//adaug 5 pentru a nu fi constrans de pretul fiecarui produs in parte, adica sa nu trebuiasca sa se potriveasca
    //la fiecare produs din lista fix brand-ul in primul rand pentru ca acesta nu este afisat in lista generata
    //si in al doilea rand pentru ca poate nu poti gasi de pe fiecare raion cea mai ieftina varianta a itemului
    //si sa poti castiga si cu o "greseala" sau doua

    buget = bugetFinal;
}

std::ostream & operator<<(std::ostream &os, const listaCumparaturi &lista) {
    for (const auto& item : lista.items) {
        os << item << ", ";
    }
    os << "\n";
    return os;
}

std::vector<Item> listaCumparaturi::getItems() const {
    return items;
}
