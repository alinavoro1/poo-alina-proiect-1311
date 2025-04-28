//
// Created by avoro on 4/23/2025.
//

#ifndef LISTA_H
#define LISTA_H
#include <algorithm>
#include <vector>

#include "Item.h"
class Lista {
protected:
    std::vector<Item> items;

public:
    Lista() = default;
    Lista(const std::vector<Item>& items_) : items(items_) {}

    Lista(const Lista& other) {
        items = other.items;
    }


    virtual ~Lista() = default;

    // virtual void afisare() const = 0;
    // virtual Lista* clone() const = 0;

    virtual void calculTotal() {};

    const std::vector<Item>& getItems() const {
        return items;
    }

    Lista& operator=(const Lista& other) {
        if (this != &other) {
            items = other.items;
        }
        return *this;
    }

    virtual void aplicaReducere(double discount) {
        for (auto& item : items) {
            item.aplicaDiscount(discount); // tot pentru powerupuri la 1 win
        }
    }

    virtual void sorteazaProduse() {
        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.getPret() < b.getPret(); // Sortează crescător după preț pentru a adauga powerupuri la 3 winuri cred
        });
    }

    // virtual void afiseazaLista() const {
    //     for (const auto& item : items) {
    //         std::cout << item.getName() << ": " << item.getPret() << "$\n";
    //     }
    // }
};

#endif //LISTA_H
