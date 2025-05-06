// //
// // Created by avoro on 4/23/2025.
// //
//
#include "Joc.h"

int Joc::winRate = 0;
int Joc::lossRate = 0;
int Joc::currentStreak = 0;

Joc::Joc(): timp(0), powerUps(FabricaPowerUps::createDefaultPowerUps()) {}

Joc::Joc(const std::string &playerName_): playerName{playerName_}, timp(0),powerUps(FabricaPowerUps::createDefaultPowerUps()) {
}

Joc::Joc(const std::string &playerName_, const listaCumparaturi &lista_): playerName{playerName_}, lista{lista_}, timp(0), powerUps(FabricaPowerUps::createDefaultPowerUps()){
}

Joc::Joc(const Magazin &magazin, const std::string &nume): magazin(magazin), playerName(nume), timp(0), powerUps(FabricaPowerUps::createDefaultPowerUps()) { }

Joc::Joc(const Joc& other)
    : magazin(other.magazin),
      playerName(other.playerName),
      varianta(other.varianta),
      lista(other.lista),
      timp(other.timp)
{
    for (const auto& pu : other.powerUps) {
        powerUps.push_back(std::shared_ptr<PowerUp>(pu->clone()));
    }
}

Joc::~Joc() = default;

Joc & Joc::operator=(Joc other) {
    swap(*this, other);
    return *this;
}

void Joc::verificarePret() const {
    for (const auto& item : lista.getItems()) {
        if (item.getPret() == 0){
            throw PretInvalid(item.getPret(), " is the invalid price for " + item.getName());
        }
    }
    std::cout << termcolor::red << "this version is available right now.\n"<< termcolor::reset;
}

void Joc::inregistreazaWin(std::vector<std::shared_ptr<PowerUp>> &powerUps) {
    currentStreak++;
    // std::cout <<termcolor::on_red <<"[DEBUG]"<<powerUps.size() << "\n"<< termcolor::reset;
    // std::cout <<termcolor::on_red<< "[DEBUG] current win streak is : " << currentStreak << "\n"<< termcolor::reset;
    for (auto& power : powerUps) {
        if (power->canBeUsed(currentStreak)) {

            std::cout<<termcolor::green<< "you won the" << power->Name()<< "Do you want to learn how to use it?(y/n)\n"<<termcolor::reset;

            std::string dasaunu;
            std::cin >> dasaunu;
            while (dasaunu != "y" && dasaunu != "n" && dasaunu != "N" && dasaunu != "Y") {
                std::cout<< termcolor::red << "Not a valid response. Enter again: "<< termcolor::reset;
                std::cin >> dasaunu;
            }
            if (dasaunu == "y" || dasaunu == "n" || dasaunu == "N" || dasaunu == "Y") {
                power->showInfo(dasaunu);
            }
        }
    }
}

void Joc::aplicaPowerUp(const std::string &keyPress, Raion &raion, int &limit) {
    //pt a arunca o exceptie in cazul in care PowerUp -ul nu este activat desi ar trebui
    bool isActive = false;

    for (auto& power : powerUps) {
        if (power->canBeUsed(currentStreak)) {
            if (power->verifyKey(keyPress))
                isActive = true;
            if (power->canBeUsed(currentStreak)) {
                if (keyPress == "s" || keyPress == "d") {
                    power->activateAislePower(raion, currentStreak);
                }
                else if (keyPress == "t")
                    power->activateTimePower(limit);

                if (auto pwrup = std::dynamic_pointer_cast<Discount>(power)) {
                    int reducere;
                    reducere = (currentStreak - 3)*10;
                    std::cout<<termcolor::blue << "Power-Up applied. You got a discount of: " << reducere << " percent\n"<<termcolor::reset;//sa afiseze si discountul aplicat
                }
                else {
                    std::cout<<termcolor::blue<<"Power-Up applied. "<< power->Name()<<"\n"<< termcolor::reset;
                }
                break;
            }
        }
    }
    if (!isActive) {
        throw EroarePowerUp("PowerUp not applied due to an error.");
    }
}

void Joc::reseteazaStreak() {
    //arunc exceptii in cazul in care adaug functii care ar trebui sa modifice aceste atribute si poate ceva nu functioneaza bine in ele
    if (currentStreak < 0) {
        throw ValueException(currentStreak , "Invalid value for current streak. Something went wrong. " );
    }
    currentStreak = 0;
}

void Joc::initStatic() {
    winRate = 0;
    lossRate = 0;
}

void Joc::actualizeazaWin() {
    if (winRate < 0) {
        throw ValueException(winRate, "Invalid value for win rate. Something went wrong. ");
    }
    winRate++;
    // currentStreak++;
}

void Joc::actualizeazaLoss() {
    if (lossRate < 0) {
        throw ValueException(lossRate, "Invalid value for loss rate. Something went wrong. ");
    }
    lossRate++;
    reseteazaStreak();
}

void Joc::calculProcent(int wins, int losses) {
    using namespace indicators;
    int totalJocuri = wins + losses;

    //exceptie care sa inlocuiasca if/else  ul de mai sus pentru ca nu ar trebui vreodata ca totalJocuri sa fie 0 sau mai putin
    if (totalJocuri <=0 ) {
        throw ValueException(totalJocuri, "Total of games played should not be zero or less. ");
    }
    double procentWin, procentLoss;
    procentWin = (wins * 100)/ totalJocuri;
    procentLoss = (losses * 100)/ totalJocuri;
    ProgressBar bar1{
        option::BarWidth{50},
        option::Start{"["},
        option::Fill{"■"},
        option::Lead{"|"},
        option::Remainder{"="},
        option::End{" ]"},
        option::ForegroundColor{Color::yellow},
        option::PrefixText{"Win rate =>  "},
        option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}
    };
    std::cout<< "       " << procentWin << "% win "<< procentLoss << "% loss\n";
    bar1.set_progress(procentWin);
    std::cout<<std::endl;

}

void Joc::listaGoala(const cosCumparaturi &cos, const listaCumparaturi &listaVerif) {
    // std::cout<<"lista initiala a fost : " << lista;
    if (cos.getLista().getItems().empty()) {
        std::unordered_set<std::string> produse;
        for (const auto& item : listaVerif.getItems()) {
            produse.insert(item.getName());
        }
        for (const auto& item : cos.getItems()) {
            if (produse.find(item.getName()) == produse.end()) {
                std::cout << "❌The shopping cart does not contain the correct items.\n ";
                actualizeazaLoss();
                return;
            }
        }
        if (varianta == 3) {
            if (cos.getTotalPlata() <= listaVerif.getBuget()) {
                std::cout << termcolor::blue << "Congrats! You won!💎💎💎💎👑👑👑\n"<< termcolor::reset;
                actualizeazaWin();
                inregistreazaWin(powerUps);
            } else {
                std::cout <<termcolor::red<< "You lost!❌❌\n"<< termcolor::reset;
                actualizeazaLoss();
            }
        } else {
            std::cout << termcolor::blue << "Congrats! You won!💎💎💎💎👑👑👑\n"<< termcolor::reset;
            actualizeazaWin();
            inregistreazaWin(powerUps);
        }
    } else {
        std::cout <<termcolor::red<< "You lost!❌❌\n"<< termcolor::reset;
        actualizeazaLoss();
    }
}

void Joc::run() {
    std::string replay;
    do {
        int versiune = selecteazaVersiune();
        int limitaTimp;
        if (versiune ==1) {
            limitaTimp = 90;
        }
        else if (versiune ==2 || versiune ==3) {
            limitaTimp = 60;
        }
        else {
            limitaTimp = 0;
        }

        listaCumparaturi listaGenerata = magazin.genereazaListaCumparaturi();

        if (listaGenerata.getItems().empty()) {
            throw ExceptieListaGoala("Generated shopping list is empty.");
        }

        afiseazaLista(listaGenerata, versiune);

        listaCumparaturi lista2;
        lista2 = listaGenerata;
        cosCumparaturi cos{lista2, {}};
        Joc joc{playerName, listaGenerata};

        verificarePret();

        std::string raspuns;
        std::cout << "Do you want to start the game? (y/n)\n";
        std::cin >> raspuns;

        if (raspuns == "y" || raspuns == "Y") {
            if (startJoc( cos, limitaTimp)) {
                std::cout << "You finished on time!\n";
            }
            std::cout << cos;
        }
        else if ( raspuns != "n" || raspuns != "N") {
            std::cout<< "Invalid response. Enter again(y/n!!) ";
            while (raspuns != "n" && raspuns != "N" && raspuns != "y" && raspuns != "Y") {
                std::cin >> raspuns;
            }
            if (raspuns == "y" || raspuns == "Y") {
                if (startJoc( cos, limitaTimp)) {
                    std::cout << "You finished on time!\n";
                }
                std::cout << cos;
            }
        }

        listaGoala(cos, listaGenerata);
        std::cout <<"Your win rate is: \n";
        calculProcent(winRate, lossRate);

        std::cout << "Do you want to play again? Please...(y/n)\n";
        std::cin >> replay;
    } while (replay == "y");
}

int Joc::selecteazaVersiune() {
    int versiune;

    std::cout << "Select a game version:\n ";
    std::cout<<termcolor::green<<"- [1] 1min 30s no budget\n"<< termcolor::reset;
    std::cout<<termcolor::yellow<<" - [2] 1min no budget\n"<< termcolor::reset;
    std::cout<<termcolor::red<<" - [3] 1min with budget\n"<< termcolor::reset;

    std::cin >> versiune;
    while (versiune < 1 || versiune > 3) {
        std::cout <<termcolor::red<< "Invalid version\n"<< termcolor::reset;
        std::cin >> versiune;
    }
    varianta = versiune;
    return versiune;
}

void Joc::afiseazaLista(listaCumparaturi listaC, int versiune) {
    tabulate::Table listaInit;
    std::vector<std::string> display_items;
    for (const auto& item: listaC.getItems()) {
        display_items.push_back(item.getName());
    }
    std::string display_combined;
    for (size_t i = 0; i < display_items.size(); ++i) {
        display_combined += display_items[i];
        if (i < display_items.size() - 1) display_combined += ", ";
    }

    listaInit.add_row({display_combined});
    listaInit[0][0].format()
            .font_style({tabulate::FontStyle::italic})
            .font_color(tabulate::Color::red);

    std::cout << "Your list contains:\n" << listaInit << "\n";
    if (versiune == 3) {
        listaC.calculTotal();
        std::cout << "Your budget is: " << listaC.getBuget() << "\n\n";
    }
}

bool Joc::startJoc(cosCumparaturi &cos, int limitaTimp) {
    Stopwatch timer;
    timer.start();
    bool timpExpirat = false;

    for (const auto& raion : magazin.getRaioane()) {
        Raion raionCrt = raion;
        if (timer.elapsed() >= limitaTimp) {
            std::cout << "\n⏰ Time has expired! You lost!\n";
            timpExpirat = true;
            break;
        }

        std::cout << raionCrt << "\n\n";
        tabulate::Table listaDisplay;
        std::vector<std::string> item_names;
        for (const auto& item: cos.getLista().getItems()) {
            item_names.push_back(item.getName());
        }

        std::string items_combined;
        for (size_t i = 0; i < item_names.size(); i++) {
            items_combined += item_names[i];
            if (i < item_names.size() - 1)
                items_combined += ", ";
        }

        listaDisplay.add_row({"Your list", items_combined});
        listaDisplay[0][0].format()
                .font_style({tabulate::FontStyle::italic})
                .font_color(tabulate::Color::magenta);
        std::cout << listaDisplay << "\n\n";

        std::cout << "Pick a number to add the item to the cart, -1 to skip, 99 to exit game\n";
        int ok=0;

        int lowest=21;//doar o valoare random, nu cred ca in viitorul apropiat o sa faca cineva streakul 21
        for (const auto& power : powerUps) {
            if (power->canBeUsed(currentStreak)) {
                ok++;
                if (lowest > currentStreak) {
                    lowest = currentStreak;
                }
            }
        }

        if (currentStreak >= lowest) {
            std::string inputKey;
            if (ok == 1) {
                std::cout<<"Press a key to use the available Power-Ups (s) or type x for no Power-Up: ";
            }
            if (ok == 2) {
                std::cout<< "Press a key to use the available Power-Ups (s/d) or type x for no Power-Up: ";
            }
            if (ok == 3 ) {
                std::cout << "Press a key to use the available Power-Ups (s/d/t) or type x for no Power-Up: ";
            }
            if (ok > 3) {
                std::cout << "Press a key to use the available Power-Ups (s/d/t/p) or type x for no Power-Up: ";
                ///clasa pe care o sa  o  adaug pentru commitul separat o sa aiba key-ul p
            }
            std::cin >> inputKey;
            if (inputKey != "x") {
                aplicaPowerUp(inputKey, raionCrt, limitaTimp);
                std::cout << "Pick a number to add the item to the cart, -1 to skip, 99 to exit game\n";
                // raion = raionCrt;
            }
        }

        int index;
        while (std::cin >> index) {
            if (index == -1) break;
            if (index == 99) return false;
            if (index >= 0 && index < int(raionCrt.getItems().size())) {
                cos.adaugaInCos(raionCrt.getItems()[index]);
                cos.calculTotal();
            } else {
                std::cout <<termcolor::red<< "Invalid number\n"<< termcolor::reset;
            }
        }
    }

    if (!timpExpirat) {
        double timpFinal = timer.elapsed();
        std::cout << "You finished in " << timpFinal << " seconds!\n";
    }

    return !timpExpirat;
}

std::ostream & operator<<(std::ostream &os, const Joc &joc) {
    os
            << "playerName: " << joc.playerName<< "\n"
            << " lista: " << joc.lista
            << " timp: " << joc.timp<< "\n";
    return os;
}

void swap(Joc &lhs, Joc &rhs) noexcept {
    using std::swap;
    swap(lhs.magazin, rhs.magazin);
    swap(lhs.playerName, rhs.playerName);
    swap(lhs.varianta, rhs.varianta);
    swap(lhs.lista, rhs.lista);
    swap(lhs.timp, rhs.timp);
    swap(lhs.powerUps, rhs.powerUps);
}
