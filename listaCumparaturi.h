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
    listaCumparaturi() = default;

    explicit listaCumparaturi(const std::vector<Item>& items_, int buget_ = 0)
        : Lista(items_), buget{buget_} {}

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

    ~listaCumparaturi() override = default;

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

    void afisare() const override {
        std::cout << *this;
    }

    Lista* clone() const override {
        return new listaCumparaturi(*this);
    }

    void calculTotal() override {
        double total = 0;
        for (const auto& item : items) {
            total += item.getPret();
        }
        // Aici adăugăm acel +5 din fosta funcție calculeazaBuget
        int bugetFinal = int(round(total)) + 5;
        buget = bugetFinal;
    }
};
//
// // class listaCumparaturi : public Lista{
// //     int buget;
// // public:
// //     // listaCumparaturi();
// //     // explicit listaCumparaturi(const std::vector <Item>& items_, int buget_ = 0);
// //     listaCumparaturi(const std::vector<Item>& items_, int buget_ = 0) : Lista(items_), buget(buget_) {}
// //
// //     listaCumparaturi(const listaCumparaturi& other);
// //
// //     //operator =
// //     listaCumparaturi& operator=(const listaCumparaturi& other);
// //
// //     int getBuget() const;
// //
// //     ~listaCumparaturi();
// //
// //     friend std::ostream& operator<<(std::ostream& os, const listaCumparaturi& lista);
// //
// //     void calculeazaBuget(listaCumparaturi& lista);
// //
// //     void stergeProdus(const Item& item);
// // };
// //
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
//     double calculTotal() const override {
//         double total = 0;
//         for (const auto& item : items) {
//             total += item.getPret();
//         }
//
//         int bugetFinal = int(round(total)) + 5;//adaug 5 pentru ca bugetul sa nu fie restrictionat de brandul obiectelor din lista generata random
//         //     //si sa pot alege de exemplu daca nu am destul timp si un obiect putin mai scump in cazul in care nu il vad pe cel mai ieftin
//         //     //intrucat la mine sunt items cu acelasi nume dar brand diferit si pretul difera
//         //
//         return bugetFinal;
//     }
// };
//
#endif //LISTACUMPARATURI_H
