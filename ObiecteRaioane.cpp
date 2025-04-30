//
// Created by avoro on 4/23/2025.
//
#include "ObiecteRaioane.h"
#include <vector>
#include "Item.h"


//paine
const Item itemulp1{"sourdough",5.0, "lidl"};
const Item itemulp2{"ciabatta", 12.0,"lidl"};
const Item itemulp3{"focaccia",10.0,"lidl"};
const Item itemulp4{"brioche",6.0,"lidl"};
const Item itemulp5{"rye bread",11.0,"lidl"};
const Item itemulp6{"sourdough", 6.0, "kaufland"};
const Item itemulp7{"ciabatta", 11.0, "kaufland"};
const Item itemulp8{"focaccia", 12.0, "kaufland"};
const Item itemulp9{"brioche", 10.0, "kaufland"};
const Item itemulp10{"rye bread",9.0, "kaufland"};
const Item itemulp11{"sourdough", 7.5, "auchan"};
const Item itemulp12{"ciabatta", 13.0, "auchan"};
const Item itemulp13{"focaccia", 11.0, "auchan"};
const Item itemulp14{"brioche",5.0, "auchan"};
const Item itemulp15{"rye bread",8.0, "auchan"};
//legume
const Item itemull1{"carrots",11.0,"lidl"};
const Item itemull2{"tomatoes",5.0,"lidl"};
const Item itemull3{"cucumbers",6.0,"lidl"};
const Item itemull4{"cabbage",3.0,"lidl"};
const Item itemull5{"potatoes",7.5,"lidl"};
const Item itemull6{"carrots", 10.0, "kaufland"};
const Item itemull7{"tomatoes", 7.0, "kaufland"};
const Item itemull8{"cucumbers", 8.0, "kaufland"};
const Item itemull9{"cabbage", 4.0, "kaufland"};
const Item itemull10{"potatoes", 6.5, "kaufland"};
const Item itemull11{"carrots", 9.0, "auchan"};
const Item itemull12{"tomatoes", 6.0, "auchan"};
const Item itemull13{"cucumbers", 7.0, "auchan"};
const Item itemull14{"cabbage", 3.5, "auchan"};
const Item itemull15{"potatoes", 6.0, "auchan"};
//fructe
const Item itemulf1{"apples", 10.0, "lidl"};
const Item itemulf2{"bananas", 5.0, "lidl"};
const Item itemulf3{"oranges", 7.0, "lidl"};
const Item itemulf4{"grapes", 12.0, "lidl"};
const Item itemulf5{"strawberries", 14.0, "lidl"};
const Item itemulf6{"apples", 11.0, "kaufland"};
const Item itemulf7{"bananas", 4.5, "kaufland"};
const Item itemulf8{"oranges", 8.0, "kaufland"};
const Item itemulf9{"grapes", 13.0, "kaufland"};
const Item itemulf10{"strawberries", 16.0, "kaufland"};
const Item itemulf11{"apples", 12.5, "auchan"};
const Item itemulf12{"bananas", 5.5, "auchan"};
const Item itemulf13{"oranges", 7.5, "auchan"};
const Item itemulf14{"grapes", 14.0, "auchan"};
const Item itemulf15{"strawberries", 15.5, "auchan"};

//bauturi
const Item itemulb1{"water", 1.5, "lidl"};
const Item itemulb2{"juice", 3.0, "lidl"};
const Item itemulb3{"soda", 3.5, "lidl"};
const Item itemulb4{"coffee", 4.5, "lidl"};
const Item itemulb5{"tea", 2.5, "lidl"};
const Item itemulb6{"water", 1.7, "kaufland"};
const Item itemulb7{"juice", 3.5, "kaufland"};
const Item itemulb8{"soda", 3.8, "kaufland"};
const Item itemulb9{"coffee", 5.0, "kaufland"};
const Item itemulb10{"tea", 2.8, "kaufland"};
const Item itemulb11{"water", 1.8, "auchan"};
const Item itemulb12{"juice", 4.0, "auchan"};
const Item itemulb13{"soda", 4.0, "auchan"};
const Item itemulb14{"coffee", 5.5, "auchan"};
const Item itemulb15{"tea", 3.0, "auchan"};
//kitchen utensils
const Item itemulk1{"spoon", 2.0, "lidl"};
const Item itemulk2{"fork", 2.0, "lidl"};
const Item itemulk3{"knife", 2.5, "lidl"};
const Item itemulk4{"cutting board", 5.0, "lidl"};
const Item itemulk5{"pan", 10.0, "lidl"};
const Item itemulk6{"spoon", 2.5, "kaufland"};
const Item itemulk7{"fork", 2.5, "kaufland"};
const Item itemulk8{"knife", 3.0, "kaufland"};
const Item itemulk9{"cutting board", 5.5, "kaufland"};
const Item itemulk10{"pan", 12.0, "kaufland"};
const Item itemulk11{"spoon", 3.0, "auchan"};
const Item itemulk12{"fork", 3.0, "auchan"};
const Item itemulk13{"knife", 3.5, "auchan"};
const Item itemulk14{"cutting board", 6.0, "auchan"};
const Item itemulk15{"pan", 13.0, "auchan"};

//gradina
const Item itemulg1{"fertilizer", 7.0, "lidl"};
const Item itemulg2{"seeds", 5.0, "lidl"};
const Item itemulg3{"watering can", 6.0, "lidl"};
const Item itemulg4{"garden gloves", 5.0, "lidl"};
const Item itemulg5{"plant pots", 6.0, "lidl"};
const Item itemulg6{"fertilizer", 7.5, "kaufland"};
const Item itemulg7{"seeds", 5.5, "kaufland"};
const Item itemulg8{"watering can", 6.5, "kaufland"};
const Item itemulg9{"garden gloves", 5.5, "kaufland"};
const Item itemulg10{"plant pots", 6.5, "kaufland"};
const Item itemulg11{"fertilizer", 8.0, "auchan"};
const Item itemulg12{"seeds", 6.0, "auchan"};
const Item itemulg13{"watering can", 7.0, "auchan"};
const Item itemulg14{"garden gloves", 6.0, "auchan"};
const Item itemulg15{"plant pots", 7.0, "auchan"};

//school supplies
const Item itemulss1{"notebook", 2.5, "lidl"};
const Item itemulss2{"pen", 1.0, "lidl"};
const Item itemulss3{"pencil", 0.8, "lidl"};
const Item itemulss4{"eraser", 0.6, "lidl"};
const Item itemulss5{"ruler", 2.5, "lidl"};
const Item itemulss6{"notebook", 2.8, "kaufland"};
const Item itemulss7{"pen", 1.2, "kaufland"};
const Item itemulss8{"pencil", 1.0, "kaufland"};
const Item itemulss9{"eraser", 0.7, "kaufland"};
const Item itemulss10{"ruler", 3.0, "kaufland"};
const Item itemulss11{"notebook", 3.0, "auchan"};
const Item itemulss12{"pen", 1.5, "auchan"};
const Item itemulss13{"pencil", 1.2, "auchan"};
const Item itemulss14{"eraser", 0.8, "auchan"};
const Item itemulss15{"ruler", 3.5, "auchan"};

//snacks
const Item itemuls1{"chips", 4.0, "lidl"};
const Item itemuls2{"popcorn", 3.0, "lidl"};
const Item itemuls3{"pretzels", 4.0, "lidl"};
const Item itemuls4{"nuts", 5.0, "lidl"};
const Item itemuls5{"crackers", 3.5, "lidl"};
const Item itemuls6{"chips", 4.5, "kaufland"};
const Item itemuls7{"popcorn", 3.5, "kaufland"};
const Item itemuls8{"pretzels", 4.5, "kaufland"};
const Item itemuls9{"nuts", 5.5, "kaufland"};
const Item itemuls10{"crackers", 4.0, "kaufland"};
const Item itemuls11{"chips", 5.0, "auchan"};
const Item itemuls12{"popcorn", 4.0, "auchan"};
const Item itemuls13{"pretzels", 5.0, "auchan"};
const Item itemuls14{"nuts", 6.0, "auchan"};
const Item itemuls15{"crackers", 4.5, "auchan"};
//carne
const Item itemulc1{"chicken breast", 18.0, "lidl"};
const Item itemulc2{"ground beef", 15.0, "lidl"};
const Item itemulc3{"pork chops", 17.0, "lidl"};
const Item itemulc4{"sausage", 12.0, "lidl"};
const Item itemulc5{"steak", 24.0, "lidl"};
const Item itemulc6{"chicken breast", 20.0, "kaufland"};
const Item itemulc7{"ground beef", 18.0, "kaufland"};
const Item itemulc8{"pork chops", 19.0, "kaufland"};
const Item itemulc9{"sausage", 13.0, "kaufland"};
const Item itemulc10{"steak", 26.0, "kaufland"};
const Item itemulc11{"chicken breast", 19.0, "auchan"};
const Item itemulc12{"ground beef", 17.0, "auchan"};
const Item itemulc13{"pork chops", 18.0, "auchan"};
const Item itemulc14{"sausage", 12.5, "auchan"};
const Item itemulc15{"steak", 25.0, "auchan"};

//dairy
const Item itemuld1{"milk", 2.5, "lidl"};
const Item itemuld2{"cheese", 5.0, "lidl"};
const Item itemuld3{"butter", 4.5, "lidl"};
const Item itemuld4{"yogurt", 2.0, "lidl"};
const Item itemuld5{"cream", 3.0, "lidl"};
const Item itemuld6{"milk", 2.8, "kaufland"};
const Item itemuld7{"cheese", 5.5, "kaufland"};
const Item itemuld8{"butter", 4.8, "kaufland"};
const Item itemuld9{"yogurt", 2.2, "kaufland"};
const Item itemuld10{"cream", 3.2, "kaufland"};
const Item itemuld11{"milk", 3.0, "auchan"};
const Item itemuld12{"cheese", 5.8, "auchan"};
const Item itemuld13{"butter", 4.2, "auchan"};
const Item itemuld14{"yogurt", 2.5, "auchan"};
const Item itemuld15{"cream", 3.5, "auchan"};

//dulciuri - sweets sw
const Item itemulsw1{"chocolate", 8.0, "lidl"};
const Item itemulsw2{"gummy bears", 6.0, "lidl"};
const Item itemulsw3{"biscuits", 5.0, "lidl"};
const Item itemulsw4{"candy bars", 7.0, "lidl"};
const Item itemulsw5{"lollipops", 4.0, "lidl"};
const Item itemulsw6{"chocolate", 8.5, "kaufland"};
const Item itemulsw7{"gummy bears", 7.0, "kaufland"};
const Item itemulsw8{"biscuits", 6.0, "kaufland"};
const Item itemulsw9{"candy bars", 8.5, "kaufland"};
const Item itemulsw10{"lollipops", 5.0, "kaufland"};
const Item itemulsw11{"chocolate", 9.0, "auchan"};
const Item itemulsw12{"gummy bears", 7.5, "auchan"};
const Item itemulsw13{"biscuits", 6.5, "auchan"};
const Item itemulsw14{"candy bars", 9.0, "auchan"};
const Item itemulsw15{"lollipops", 5.5, "auchan"};

const std::vector< Item> bread_ = {itemulp1, itemulp2, itemulp3, itemulp4, itemulp5, itemulp6, itemulp7, itemulp8, itemulp9, itemulp10, itemulp11, itemulp12, itemulp13, itemulp14, itemulp15};
const std::vector<Item> vegetables_ = {itemull1, itemull2, itemull3, itemull4, itemull5, itemull6, itemull7, itemull8, itemull9, itemull10, itemull11, itemull12, itemull13, itemull14, itemull15};
const std::vector<Item> fruits_ = {itemulf1, itemulf2, itemulf3, itemulf4, itemulf5, itemulf6, itemulf7, itemulf8, itemulf9, itemulf10, itemulf11, itemulf12, itemulf13, itemulf14, itemulf15};
const std::vector<Item> drinks_ = {itemulb1, itemulb2, itemulb3, itemulb4, itemulb5, itemulb6, itemulb7, itemulb8, itemulb9, itemulb10, itemulb11, itemulb12, itemulb13, itemulb14, itemulb15};
const std::vector<Item> kitchen_ = {itemulk1, itemulk2, itemulk3, itemulk4, itemulk5, itemulk6, itemulk7, itemulk8, itemulk9, itemulk10, itemulk11, itemulk12, itemulk13, itemulk14, itemulk15};
const std::vector<Item> garden_ = {itemulg1, itemulg2, itemulg3, itemulg4, itemulg5, itemulg6, itemulg7, itemulg8, itemulg9, itemulg10, itemulg11, itemulg12, itemulg13, itemulg14, itemulg15};
const std::vector<Item> school_ = {itemulss1, itemulss2, itemulss3, itemulss4, itemulss5, itemulss6, itemulss7, itemulss8, itemulss9, itemulss10, itemulss11, itemulss12, itemulss13, itemulss14, itemulss15};
const std::vector<Item> snacks_ = {itemuls1, itemuls2, itemuls3, itemuls4, itemuls5, itemuls6, itemuls7, itemuls8, itemuls9, itemuls10, itemuls11, itemuls12, itemuls13, itemuls14, itemuls15};
const std::vector<Item> meat_ = {itemulc1, itemulc2, itemulc3, itemulc4, itemulc5, itemulc6, itemulc7, itemulc8, itemulc9, itemulc10, itemulc11, itemulc12, itemulc13, itemulc14, itemulc15};
const std::vector<Item> dairy_ = {itemuld1, itemuld2, itemuld3, itemuld4, itemuld5, itemuld6, itemuld7, itemuld8, itemuld9, itemuld10, itemuld11, itemuld12, itemuld13, itemuld14, itemuld15};
const std::vector< Item> sweets_ = {itemulsw1, itemulsw2, itemulsw3, itemulsw4, itemulsw5, itemulsw6, itemulsw7, itemulsw8, itemulsw9, itemulsw10, itemulsw11, itemulsw12, itemulsw13, itemulsw14, itemulsw15};

const Raion raionb{"bread",bread_};
const Raion raionf{"fruits",fruits_};
const Raion raiond{"drinks",drinks_};
const Raion raionk{"kitchen",kitchen_};
const Raion raiong{"garden",garden_};
const Raion raionv{"vegetables",vegetables_};
const Raion raionss{"school supplies", school_};
const Raion raions{"snacks", snacks_};
const Raion raionm{"meat", meat_};
const Raion raionda{"dairy", dairy_};
const Raion raionsw{"sweets", sweets_};


const std::vector<Raion> get_raioane() {
    return {raiond, raionf,raionv, raionb, raionk, raiong, raionss, raions, raionm, raionda, raionsw};
}
