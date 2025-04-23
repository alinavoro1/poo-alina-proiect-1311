//
// Created by avoro on 4/23/2025.
//

#include "Joc.h"

Joc::Joc() {}

Joc::Joc(const std::string &playerName_): playerName{playerName_}, lista{}, variantaJoc(0), timp(0) {}

Joc::Joc(const std::string &playerName_, int varianta): playerName(playerName_), variantaJoc{varianta}, timp(0) {}

Joc::Joc(const std::string &playerName_, const listaCumparaturi &lista_, int varianta): playerName{playerName_}, lista{lista_}, variantaJoc{varianta}, timp(0) {}

int Joc::getVarianta() const {return variantaJoc;}

const listaCumparaturi & Joc::getLista() const { return this->lista; }

void Joc::setTimp(int timp_) {
    timp = timp_;
}

Joc & Joc::operator=(const Joc &other) {
    lista = other.lista;
    variantaJoc = other.variantaJoc;
    timp = other.timp;
    playerName = other.playerName;
    return *this;
}

Joc::~Joc() = default;

void Joc::setareTimer() {
    if (variantaJoc == 0) {
        std::cout << playerName << " please select a game version!\n";
        return;
    }
    else if (variantaJoc ==1) {
        setTimp(30);
    }
    else if (variantaJoc ==2) {
        setTimp(15);
    }
    else if (variantaJoc ==3) {
        setTimp(20);
    }
}

int Joc::verificarePret() const {
    int ok =0;
    for (const auto& item : lista.getItems()) {
        if (item.getPret() == 0){
            ok++;}
    }
    if(ok == 0){
        std::cout << "this version is available right now.\n";
        return 1;
    }
    else{
        std::cout << "this version is not availble right now.\n";
        return 0;}
}

std::ostream & operator<<(std::ostream &os, const Joc &obj) {
    os
            << "playerName: " << obj.playerName<< "\n"
            << " lista: " << obj.lista
            << " variantaJoc: " << obj.variantaJoc << "\n"
            << " timp: " << obj.timp<< "\n";
    return os;
}
