//
// Created by avoro on 4/23/2025.
//

#ifndef JOC_H
#define JOC_H
#include <atomic>
#include <iostream>
#include <tabulate.hpp>
#include <unordered_set>

#include "cosCumparaturi.h"
#include "listaCumparaturi.h"
#include "Magazin.h"
#include "Stopwatch.h"


class Joc {
    Magazin magazin;
    std::string playerName;
    int varianta=0;
    listaCumparaturi lista;
    int timp;
    std::atomic<bool> running = false;
public:
    Joc ();
    explicit Joc(const std::string& playerName_);

    Joc(const std::string& playerName_,const listaCumparaturi& lista_);


    const listaCumparaturi& getLista() const;


    Joc& operator=(const Joc& other);

    ~Joc();

    friend std::ostream & operator<<(std::ostream &os, const Joc &obj);


    int verificarePret() const;

    Joc(const Magazin& magazin, const std::string& nume);

    void listaGoala(const cosCumparaturi& cos);

    void run();


    int selecteazaVersiune();

    void afiseazaLista(const listaCumparaturi& lista, int versiune);

    bool startJoc( cosCumparaturi& cos, int limitaTimp);
};



#endif //JOC_H
