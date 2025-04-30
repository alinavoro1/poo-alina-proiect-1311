# Tag & Bag - Supermarket

# Un joc care provoaca neliniste🛒

## Table of Contents
- [Reguli](#Regulile-jocului)
- [Features](#Features-de-implementat)
- [Teme ramase](#Tema-2)
- [Resurse](#Resurse)



### Regulile jocului

Jucatorul isi va alege dintre cele 3 variante de joc

- [ ] varianta usoara -> timer de 90 de secunde si niciun buget
- [ ] varianta medie -> timer de 60 secunde si niciun buget
- [ ] varianta grea -> timer de 60 de secunde si cu buget

La inceputul jocului, jucatorul va primii o lista de cumparaturi, indiferent de varianta aleasa. Lista va contine doar items din raioanele din joc. In timpul alocat, plimbandu-se prin raioane, playerul aduna toate obiectele de pe lista. Cand timpul se  va scurge, se va verifica daca cosul de cumparaturi este plin si coincide cu lista initiala, iar daca playerul a ales varianta 3, se va verifica si daca s-a incadrat in buget.

Pentru a selecta obiectele player-ul trebuie sa scrie indexul corespunzator obiectului dorit, iar pentru a naviga prin raioane trebuie sa scrie -1 sau 99 pentru a incheia jocul

## Features de implementat

features pe care vreau sa le mai implementez:
- [ ] interfata 
- [ ] bara pentru timer,sa stii cat timp a mai ramas

![full-shopping-cart-snacks-grocery-shopping-supermarket-cart](https://github.com/user-attachments/assets/3ba200f7-f8c7-46d8-af70-e37d7baf0fa3)

## Tema 2

#### Cerințe
- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri:
  - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [ ] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
    - afișare virtuală, interfață non-virtuală
  - [ ] apelarea constructorului din clasa de bază din constructori din derivate
  - [ ] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază
    - [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    - [ ] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
    - [ ] smart pointers (recomandat, opțional)
- [ ] excepții
  - [ ] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice
  - [ ] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
  - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] funcții *de nivel înalt*, de eliminat cât mai mulți getters/setters/funcții low-level
- [ ] minim 75-80% din codul propriu să fie C++
- [ ] la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, **pe lângă cele 3 derivate deja adăugate** din aceeași ierarhie
  - noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou
  - noua derivată va fi integrată în codul existent (adică va fi folosită, nu adăugată doar ca să fie)
- [ ] tag de `git` pe commit cu **toate bifele**: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] minim 85-90% din codul propriu să fie C++
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git` pe commit cu **toate bifele**: de exemplu `v0.3` sau `v1.0`

## Instrucțiuni de compilare

Proiectul este configurat cu CMake.

Instrucțiuni pentru terminal:

1. Pasul de configurare
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

Sau pe Windows cu GCC:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
```

La acest pas putem cere să generăm fișiere de proiect pentru diverse medii de lucru.


2. Pasul de compilare
```sh
cmake --build build --config Debug --parallel 6
```

Cu opțiunea `parallel` specificăm numărul de fișiere compilate în paralel.


3. Pasul de instalare (opțional)
```sh
cmake --install build --config Debug --prefix install_dir
```

Vezi și [`scripts/cmake.sh`](scripts/cmake.sh).

Observație: folderele `build/` și `install_dir/` sunt adăugate în fișierul `.gitignore` deoarece conțin fișiere generate și nu ne ajută să le versionăm.


## Resurse

- soon
