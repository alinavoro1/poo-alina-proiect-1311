//
// Created by avoro on 4/23/2025.
//

#include "Obiecte.h"

//paine
Item itemulp1{"sourdough",5.0, "lidl"};
Item itemulp2{"ciabatta", 12.0,"lidl"};
Item itemulp3{"focaccia",10.0,"lidl"};
Item itemulp4{"brioche",6.0,"lidl"};
Item itemulp5{"rye bread",11.0,"lidl"};
Item itemulp6{"sourdough", 6.0, "kaufland"};
Item itemulp7{"ciabatta", 11.0, "kaufland"};
Item itemulp8{"focaccia", 12.0, "kaufland"};
Item itemulp9{"brioche", 10.0, "kaufland"};
Item itemulp10{"rye bread",9.0, "kaufland"};
Item itemulp11{"sourdough", 7.5, "auchan"};
Item itemulp12{"ciabatta", 13.0, "auchan"};
Item itemulp13{"focaccia", 11.0, "auchan"};
Item itemulp14{"brioche",5.0, "auchan"};
Item itemulp15{"rye bread",8.0, "auchan"};
//legume
Item itemull1{"carrots",11.0,"lidl"};
Item itemull2{"tomatoes",5.0,"lidl"};
Item itemull3{"cucumbers",6.0,"lidl"};
Item itemull4{"cabbage",3.0,"lidl"};
Item itemull5{"potatoes",7.5,"lidl"};
Item itemull6{"carrots", 10.0, "kaufland"};
Item itemull7{"tomatoes", 7.0, "kaufland"};
Item itemull8{"cucumbers", 8.0, "kaufland"};
Item itemull9{"cabbage", 4.0, "kaufland"};
Item itemull10{"potatoes", 6.5, "kaufland"};
Item itemull11{"carrots", 9.0, "auchan"};
Item itemull12{"tomatoes", 6.0, "auchan"};
Item itemull13{"cucumbers", 7.0, "auchan"};
Item itemull14{"cabbage", 3.5, "auchan"};
Item itemull15{"potatoes", 6.0, "auchan"};
//fructe
Item itemulf1{"apples", 10.0, "lidl"};
Item itemulf2{"bananas", 5.0, "lidl"};
Item itemulf3{"oranges", 7.0, "lidl"};
Item itemulf4{"grapes", 12.0, "lidl"};
Item itemulf5{"strawberries", 14.0, "lidl"};
Item itemulf6{"apples", 11.0, "kaufland"};
Item itemulf7{"bananas", 4.5, "kaufland"};
Item itemulf8{"oranges", 8.0, "kaufland"};
Item itemulf9{"grapes", 13.0, "kaufland"};
Item itemulf10{"strawberries", 16.0, "kaufland"};
Item itemulf11{"apples", 12.5, "auchan"};
Item itemulf12{"bananas", 5.5, "auchan"};
Item itemulf13{"oranges", 7.5, "auchan"};
Item itemulf14{"grapes", 14.0, "auchan"};
Item itemulf15{"strawberries", 15.5, "auchan"};

//bauturi
Item itemulb1{"water", 1.5, "lidl"};
Item itemulb2{"juice", 3.0, "lidl"};
Item itemulb3{"soda", 3.5, "lidl"};
Item itemulb4{"coffee", 4.5, "lidl"};
Item itemulb5{"tea", 2.5, "lidl"};
Item itemulb6{"water", 1.7, "kaufland"};
Item itemulb7{"juice", 3.5, "kaufland"};
Item itemulb8{"soda", 3.8, "kaufland"};
Item itemulb9{"coffee", 5.0, "kaufland"};
Item itemulb10{"tea", 2.8, "kaufland"};
Item itemulb11{"water", 1.8, "auchan"};
Item itemulb12{"juice", 4.0, "auchan"};
Item itemulb13{"soda", 4.0, "auchan"};
Item itemulb14{"coffee", 5.5, "auchan"};
Item itemulb15{"tea", 3.0, "auchan"};

//kitchen utensils
Item itemulk1{"spoon", 2.0, "lidl"};
Item itemulk2{"fork", 2.0, "lidl"};
Item itemulk3{"knife", 2.5, "lidl"};
Item itemulk4{"cutting board", 5.0, "lidl"};
Item itemulk5{"pan", 10.0, "lidl"};
Item itemulk6{"spoon", 2.5, "kaufland"};
Item itemulk7{"fork", 2.5, "kaufland"};
Item itemulk8{"knife", 3.0, "kaufland"};
Item itemulk9{"cutting board", 5.5, "kaufland"};
Item itemulk10{"pan", 12.0, "kaufland"};
Item itemulk11{"spoon", 3.0, "auchan"};
Item itemulk12{"fork", 3.0, "auchan"};
Item itemulk13{"knife", 3.5, "auchan"};
Item itemulk14{"cutting board", 6.0, "auchan"};
Item itemulk15{"pan", 13.0, "auchan"};

//gradina
Item itemulg1{"fertilizer", 7.0, "lidl"};
Item itemulg2{"seeds", 5.0, "lidl"};
Item itemulg3{"watering can", 6.0, "lidl"};
Item itemulg4{"garden gloves", 5.0, "lidl"};
Item itemulg5{"plant pots", 6.0, "lidl"};
Item itemulg6{"fertilizer", 7.5, "kaufland"};
Item itemulg7{"seeds", 5.5, "kaufland"};
Item itemulg8{"watering can", 6.5, "kaufland"};
Item itemulg9{"garden gloves", 5.5, "kaufland"};
Item itemulg10{"plant pots", 6.5, "kaufland"};
Item itemulg11{"fertilizer", 8.0, "auchan"};
Item itemulg12{"seeds", 6.0, "auchan"};
Item itemulg13{"watering can", 7.0, "auchan"};
Item itemulg14{"garden gloves", 6.0, "auchan"};
Item itemulg15{"plant pots", 7.0, "auchan"};

//school supplies
Item itemulss1{"notebook", 2.5, "lidl"};
Item itemulss2{"pen", 1.0, "lidl"};
Item itemulss3{"pencil", 0.8, "lidl"};
Item itemulss4{"eraser", 0.6, "lidl"};
Item itemulss5{"ruler", 2.5, "lidl"};
Item itemulss6{"notebook", 2.8, "kaufland"};
Item itemulss7{"pen", 1.2, "kaufland"};
Item itemulss8{"pencil", 1.0, "kaufland"};
Item itemulss9{"eraser", 0.7, "kaufland"};
Item itemulss10{"ruler", 3.0, "kaufland"};
Item itemulss11{"notebook", 3.0, "auchan"};
Item itemulss12{"pen", 1.5, "auchan"};
Item itemulss13{"pencil", 1.2, "auchan"};
Item itemulss14{"eraser", 0.8, "auchan"};
Item itemulss15{"ruler", 3.5, "auchan"};

//snacks
Item itemuls1{"chips", 4.0, "lidl"};
Item itemuls2{"popcorn", 3.0, "lidl"};
Item itemuls3{"pretzels", 4.0, "lidl"};
Item itemuls4{"nuts", 5.0, "lidl"};
Item itemuls5{"crackers", 3.5, "lidl"};
Item itemuls6{"chips", 4.5, "kaufland"};
Item itemuls7{"popcorn", 3.5, "kaufland"};
Item itemuls8{"pretzels", 4.5, "kaufland"};
Item itemuls9{"nuts", 5.5, "kaufland"};
Item itemuls10{"crackers", 4.0, "kaufland"};
Item itemuls11{"chips", 5.0, "auchan"};
Item itemuls12{"popcorn", 4.0, "auchan"};
Item itemuls13{"pretzels", 5.0, "auchan"};
Item itemuls14{"nuts", 6.0, "auchan"};
Item itemuls15{"crackers", 4.5, "auchan"};
//carne
Item itemulc1{"chicken breast", 18.0, "lidl"};
Item itemulc2{"ground beef", 15.0, "lidl"};
Item itemulc3{"pork chops", 17.0, "lidl"};
Item itemulc4{"sausage", 12.0, "lidl"};
Item itemulc5{"steak", 24.0, "lidl"};
Item itemulc6{"chicken breast", 20.0, "kaufland"};
Item itemulc7{"ground beef", 18.0, "kaufland"};
Item itemulc8{"pork chops", 19.0, "kaufland"};
Item itemulc9{"sausage", 13.0, "kaufland"};
Item itemulc10{"steak", 26.0, "kaufland"};
Item itemulc11{"chicken breast", 19.0, "auchan"};
Item itemulc12{"ground beef", 17.0, "auchan"};
Item itemulc13{"pork chops", 18.0, "auchan"};
Item itemulc14{"sausage", 12.5, "auchan"};
Item itemulc15{"steak", 25.0, "auchan"};

//dairy
Item itemuld1{"milk", 2.5, "lidl"};
Item itemuld2{"cheese", 5.0, "lidl"};
Item itemuld3{"butter", 4.5, "lidl"};
Item itemuld4{"yogurt", 2.0, "lidl"};
Item itemuld5{"cream", 3.0, "lidl"};
Item itemuld6{"milk", 2.8, "kaufland"};
Item itemuld7{"cheese", 5.5, "kaufland"};
Item itemuld8{"butter", 4.8, "kaufland"};
Item itemuld9{"yogurt", 2.2, "kaufland"};
Item itemuld10{"cream", 3.2, "kaufland"};
Item itemuld11{"milk", 3.0, "auchan"};
Item itemuld12{"cheese", 5.8, "auchan"};
Item itemuld13{"butter", 4.2, "auchan"};
Item itemuld14{"yogurt", 2.5, "auchan"};
Item itemuld15{"cream", 3.5, "auchan"};

//dulciuri - sweets sw
Item itemulsw1{"chocolate", 8.0, "lidl"};
Item itemulsw2{"gummy bears", 6.0, "lidl"};
Item itemulsw3{"biscuits", 5.0, "lidl"};
Item itemulsw4{"candy bars", 7.0, "lidl"};
Item itemulsw5{"lollipops", 4.0, "lidl"};
Item itemulsw6{"chocolate", 8.5, "kaufland"};
Item itemulsw7{"gummy bears", 7.0, "kaufland"};
Item itemulsw8{"biscuits", 6.0, "kaufland"};
Item itemulsw9{"candy bars", 8.5, "kaufland"};
Item itemulsw10{"lollipops", 5.0, "kaufland"};
Item itemulsw11{"chocolate", 9.0, "auchan"};
Item itemulsw12{"gummy bears", 7.5, "auchan"};
Item itemulsw13{"biscuits", 6.5, "auchan"};
Item itemulsw14{"candy bars", 9.0, "auchan"};
Item itemulsw15{"lollipops", 5.5, "auchan"};

