//
// Created by avoro on 4/4/2025.
//

#ifndef JOC_H
#define JOC_H
#include <atomic>
#include <chrono>
#include <thread>

#include "listaCumparaturi.h"


class Joc {
private:
    std::string playerName;
    listaCumparaturi lista;
    int variantaJoc;
    int timp;
    std::atomic<bool> jocInDerulare;
public:
    Joc();

    explicit Joc(const std::string& playerName_);

    explicit Joc(const std::string& playerName_, int varianta);

    Joc(const std::string& playerName_,const listaCumparaturi& lista_,int varianta);

    int getVarianta() const;

    const listaCumparaturi& getLista() const;

    void setTimp(int timp_);

    Joc& operator=(Joc&& other) noexcept;

    ~Joc();

    friend std::ostream & operator<<(std::ostream &os, const Joc &obj);

    void setareTimer();

    int verificarePret() const;

    void startTimer();
};



#endif //JOC_H
