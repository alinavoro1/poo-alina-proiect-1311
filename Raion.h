//
// Created by avoro on 4/23/2025.
//

#ifndef RAION_H
#define RAION_H
#include <string>
#include <tabulate.hpp>
#include <vector>

#include "Item.h"
#include "Lista.h"

class Raion: public Lista {
    std::string name;
public:
    Raion(const std::string& name_,const std::vector <Item>& items_) : Lista(items_),name{name_}{}
    Raion(const Raion&  other) : Lista(other),name{other.name} {}

    const std::string& getName() const{ return name;}

    Raion& operator=(const Raion& other) {
        name = other.name;
        Lista::operator=(other);
        return *this;
    }

    ~Raion() override = default;

    friend std::ostream & operator<<(std::ostream &os, const Raion& raion) {

        tabulate::Table header;
        tabulate::Table tabel;

        header.add_row({ "Aisle: " + raion.name });
        header[0].format()
            .width(60)
            .font_align(tabulate::FontAlign::center)
            .font_style({tabulate::FontStyle::bold})
            .font_background_color(tabulate::Color::red)
            .font_color(tabulate::Color::white);

        size_t n = raion.items.size();
        size_t cols = 3;

        for (size_t i = 0; i < n; i += cols) {
            std::vector<std::string> row;
            for (size_t j = 0; j < cols; ++j) {
                if (i + j < n) {
                    std::stringstream ss;
                    ss << "[" << (i + j) << "] " << raion.items[i + j];
                    row.push_back(ss.str());
                } else {
                    row.push_back("");
                }
            }
            tabel.add_row(tabulate::Table::Row_t{row.begin(),row.end()});
        }

        tabel.format()
            .font_align(tabulate::FontAlign::center)
            .padding_top(0)
            .padding_bottom(0);

        os << header << "\n" << tabel << "\n";
        return os;
    }

    void afisare() const override {
        std::cout << *this;
    }

    Lista* clone() const override {
        return new Raion(*this);
    }

    void calculTotal() override {
        std::cout << "calculTotal() nu este definit pentru Raion.\n";
    }

};


//
//
// class Raion: public Lista {
//     std::string name;
//     std::vector<Item> items;
// public:
//     Raion(const std::string& name_,const std::vector <Item>& Item_);
//
//     Raion(const Raion&  other);
//
//     const std::string& getName() const;
//
//     Raion& operator=(const Raion& other);
//
//     ~Raion();
//
//     friend std::ostream & operator<<(std::ostream &os, const Raion &obj);
//
//
//     const std::vector <Item>& getItems() const;
// };
//
//
//
#endif //RAION_H
