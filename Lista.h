//
// Created by avoro on 4/23/2025.
//

#ifndef LISTA_H
#define LISTA_H
#include <vector>

#include "Item.h"
class Lista {
protected:
    std::vector<Item> items;

public:
    Lista() = default;
    Lista(const std::vector<Item>& items_) : items(items_) {}

    virtual ~Lista() = default;

    virtual void afisare() const = 0;
    virtual Lista* clone() const = 0;

    virtual void calculTotal() = 0;

    const std::vector<Item>& getItems() const {
        return items;
    }

    Lista& operator=(const Lista& other) {
        if (this != &other) {
            items = other.items;
        }
        return *this;
    }

    Lista(const Lista& other) : items(other.items) {}
};


// // class Lista {
// // protected:
// //     std::vector<Item> items;
// //
// // public:
// //     Lista() = default;
// //     Lista(const std::vector<Item>& items_) : items(items_) {}
// //
// //     virtual ~Lista() = default;
// //
// //     virtual void afisare() const = 0;
// //     virtual Lista* clone() const = 0;
// //
// //     virtual double calculTotal() const = 0;
// //
// //     const std::vector<Item>& getItems() const {
// //         return items;
// //     }
// //
// //     Lista& operator=(const Lista& other) {
// //         if (this != &other) {
// //             items = other.items;
// //         }
// //         return *this;
// //     }
// // };
// class Lista {
// protected:
//     std::vector<Item> items;
//
// public:
//     Lista() = default;
//     Lista(const std::vector<Item>& items_) : items(items_) {}
//
//     virtual ~Lista() = default;
//
//     virtual void afisare() const = 0;
//     virtual Lista* clone() const = 0;
//
//     virtual double calculTotal() const = 0;
//
//     const std::vector<Item>& getItems() const {
//         return items;
//     }
//
//     Lista& operator=(const Lista& other) {
//         if (this != &other) {
//             items = other.items;
//         }
//         return *this;
//     }
// };
//
//
#endif //LISTA_H
