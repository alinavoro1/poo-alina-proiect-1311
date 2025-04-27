// //
// // Created by avoro on 4/23/2025.
// //
//
// #include "Raion.h"
//
// Raion::Raion(const std::string &name_, const std::vector<Item> &Item_): name{name_}, items{Item_} {}
//
// Raion::Raion(const Raion &other): name{other.name}, items{other.items} {}
//
// const std::string & Raion::getName() const { return name;}
//
// Raion & Raion::operator=(const Raion &other) {
//     name = other.name;
//     items = other.items;
//     return *this;
// }
//
// Raion::~Raion() = default;
//
// const std::vector<Item> & Raion::getItems() const { return items;}
//
// std::ostream & operator<<(std::ostream &os, const Raion &obj) {
//
//     tabulate::Table header;
//     tabulate::Table tabel;
//
//     header.add_row({ "Aisle: " + obj.name });
//     header[0].format()
//             .width(60)
//             .font_align(tabulate::FontAlign::center)
//             .font_style({tabulate::FontStyle::bold})
//             .font_background_color(tabulate::Color::red)
//             .font_color(tabulate::Color::white);
//
//     size_t n = obj.items.size();
//     size_t cols = 3;
//
//     for (size_t i = 0; i < n; i += cols) {
//         std::vector<std::string> row;
//         for (size_t j = 0; j < cols; ++j) {
//             if (i + j < n) {
//                 std::stringstream ss;
//                 ss << "[" << (i + j) << "] " << obj.items[i + j];
//                 row.push_back(ss.str());
//             } else {
//                 row.push_back("");
//             }
//         }
//         tabel.add_row(tabulate::Table::Row_t{row.begin(),row.end()});
//     }
//
//     tabel.format()
//             .font_align(tabulate::FontAlign::center)
//             .padding_top(0)
//             .padding_bottom(0);
//
//     os << header << "\n" << tabel << "\n";
//     return os;
// }
