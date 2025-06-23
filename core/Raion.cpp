// //
// // Created by avoro on 4/23/2025.
// //
//
#include "Raion.h"

Raion::Raion(const std::string &name_, const std::vector<Item> &items_):  items {items_}, name{name_}{}

Raion::Raion(const Raion &other):  items {other.items}, name{other.name}{}

const std::string & Raion::getName() const { return name;}

Raion & Raion::operator=(const Raion &other) {
    name = other.name;
    items = other.items;
    return *this;
}

Raion::~Raion() = default;

void Raion::aplicaReducere(double discount) {
    if (items.empty()) {
        throw RaionGol(name + " is empty [applying Discount PowerUp]");
    }
    for (auto& item : items) {
        item.aplicaDiscount(discount); // tot pentru powerupuri la 3 wins
    }
}

void Raion::sorteazaProduse() {
    if (items.empty()) {
        throw RaionGol(name + " is empty [applying Sort Items PowerUp]");
    }
    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.getPret() < b.getPret(); // Sortează crescător după preț pentru a adauga powerupuri la 2 winuri cred
    });
}

std::ostream & operator<<(std::ostream &os, const Raion &raion) {

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

const std::vector<Item>& Raion::getItems() const {
    return items;
}
