//
// Created by avoro on 4/23/2025.
//

#ifndef LISTACUMPARATURI_H
#define LISTACUMPARATURI_H
#include <algorithm>
#include <cmath>
#include <vector>

#include "Item.h"
#include "Lista.h"

class listaCumparaturi : public Lista {
    int buget;

public:
    listaCumparaturi(): buget(0) {}

    explicit listaCumparaturi(const std::vector<Item>& items_, int buget_ = 0)
        : Lista(items_), buget{buget_} {}
    explicit listaCumparaturi(int buget_): buget(buget_) {

    }

    listaCumparaturi(const listaCumparaturi& other)
        : Lista(other.items), buget{other.buget} {}

    listaCumparaturi& operator=(const listaCumparaturi& other) {
        if (this != &other) {
            Lista::operator=(other);
            buget = other.buget;
        }
        return *this;
    }

    int getBuget() const {
        return buget;
    }

    ~listaCumparaturi()  = default;

    friend std::ostream& operator<<(std::ostream& os, const listaCumparaturi& lista) {
        for (const auto& item : lista.items) {
            os << item << ", ";
        }
        os << "\n";
        return os;
    }

    void stergeProdus(const Item& item) {
        auto it = std::find_if(items.begin(), items.end(), [&](const Item& item_) {
            return item_.getName() == item.getName();
        });
        if (it != items.end()) {
            items.erase(it);
        }
    }

    void calculTotal() {
        double total = 0;
        for (const auto& item : items) {
            total += item.getPret();
        }
        // Aici adăugăm acel +5 din fosta funcție calculeazaBuget
        int bugetFinal = int(round(total)) + 5;
        buget = bugetFinal;
    }
};

#endif //LISTACUMPARATURI_H
