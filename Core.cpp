/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** Core
*/

#include <dlfcn.h>
#include <string>
#include "core/include/Core.hpp"
#include "games/IGame.hpp"

Core::Core()
{
    this->libpos = -1;
    this->gamepos = -1;
    this->status = 1;
    this->restart = false;
}

Core::~Core()
{
    closeLibrary();
}


void Core::getLibARGV(std::string &name)
{
    this->libpos = -1;
    for (std::vector<std::string>::iterator it = begin(this->nameLib); it != end(this->nameLib); it++) {
        this->libpos++;
        if (*it == name) {
            this->lib.name = *it;
            return;
        }
    }
    this->libpos = -84;
}

void Core::getGame(std::string &name)
{
    this->gamepos = -1;
    for (std::vector<std::string>::iterator it = begin(this->nameGame); it != end(this->nameGame); it++) {
        this->gamepos++;
        if (*it == name) {
            this->game.name = *it;
            return;
        }
    }
    this->gamepos = -84;
}

int Core::handleEvent(Input input)
{
    switch(input) {
        case Input::NO_INPUT:
            return (true);
        case Input::F1:
            this->library->destroyWindow();
            PreviousLib();
            encapsulationLib();
            this->library->initStart();
            break;
        case Input::F2:
            this->library->destroyWindow();
            nextLib();
            encapsulationLib();
            this->library->initStart();
            break;
        case Input::F3:
            previousGame();
            break;
        case Input::F4:
            nextGame();
            break;
        case Input::F5:
            restartGame();
            break;
        case Input::F6:
            goBackToTheMenu();
            break;
        case Input::F7:
            this->library->destroyWindow();
            return (false);
        case Input::ENTER:
            changeLibandGame();
            break;
        default:
            return (true);
        }
    return (true);
}

void Core::changeLibandGame()
{
    this->statusgamelib.gameStatus = this->library->getGame();
    this->statusgamelib.libStatus = this->library->getLib();

    if (this->statusgamelib.gameStatus == 1)
        this->gamepos = 0;
    else if (this->statusgamelib.gameStatus == 2)
        this->gamepos = 1;

    if (this->statusgamelib.libStatus == 1)
        this->libpos = 2;
    else if (this->statusgamelib.libStatus == 2)
        this->libpos = 1;
    else if (this->statusgamelib.libStatus == 3)
        this->libpos = 0;

    this->library->destroyWindow();
    getLibARGV(this->nameLib.at(this->libpos));
    encapsulationLib();
    this->library->initStart();
}

void Core::nextGame()
{
    int i = 0;
    std::vector<std::string>::iterator it = begin(this->nameGame);

    for (; it != end(this->nameGame); it++) {
        if (this->gamepos == i) {
            break;
        }
        i++;
    }
    this->gamepos++;

    if (this->gamepos == this->nameGame.size()) {
        this->gamepos = 0;
    }

    getGame(this->nameGame.at(this->gamepos));
}

void Core::previousGame()
{
    int i = 0;
    std::vector<std::string>::iterator it = begin(this->nameGame);

    for (; it != end(this->nameGame); it++) {
        if (this->gamepos == i) {
            break;
        }
        i++;
    }
    this->gamepos--;
    if (this->gamepos < 0) {
        it = begin(this->nameGame);
        int u;
        for (u = 0; it != end(this->nameGame); it++) {
            u++;
        }
        this->gamepos = u -1;
    }
    getGame(this->nameGame.at(this->gamepos));

}

void Core::nextLib()
{
    int i = 0;
    std::vector<std::string>::iterator it = begin(this->nameLib);

    for (; it != end(this->nameLib); it++) {
        if (this->libpos == i) {
            break;
        }
        i++;
    }
    this->libpos++;
    if (this->libpos == this->nameLib.size()) {
        this->libpos = 0;
    }
    getLibARGV(this->nameLib.at(this->libpos));
}

void Core::PreviousLib()
{
    int i = 0;
    std::vector<std::string>::iterator it = begin(this->nameLib);

    for (; it != end(this->nameLib); it++) {
        if (this->libpos == i) {
            break;
        }
        i++;
    }
    this->libpos--;
    if (this->libpos < 0) {
        it = begin(this->nameLib);
        int u;
        for (u = 0; it != end(this->nameLib); it++) {
            u++;
        }
        this->libpos = u -1;
    }
    getLibARGV(this->nameLib.at(this->libpos));
}

int Core::Game(std::string name)
{
    name = name.substr(2, name.length());
    getALlLibrairi();
    getLibARGV(name);
    encapsulationLib();

    if (this->exit == 84)
        return (84);
    return (windowLoop());
}

int Core::windowLoop()
{
    bool exit = true;

    this->library->initStart();

    if (this->library->getExit() == 84)
        return (84);

    while (exit != false) {
        Input input = this->library->getInput();
        exit = handleEvent(input);
        this->library->drawMainMenu();
    }
    return (0);
}

std::vector<std::string> name;

void Core::encapsulationLib()
{
    if (this->libpos == -84) {
        std::cerr << "Sorry but Its not a library" << std::endl;
        this->exit = 84;
        return;
    }

    this->lib.libone = getLibrary(this->lib.name);

    if (!verifIfIsLibrary(this->lib.libone)) {
        this->exit = 84;
        return;
    }

    void *createLibrari = dlsym(this->lib.libone, "createLib");
    auto  librari = ((LIB::ILibrari *(*)()) createLibrari)();
    std::shared_ptr<LIB::ILibrari> Ilib(librari, &destructorlib);
    this->library = Ilib;
}

void Core::encapsulationGame()
{
    if (this->gamepos == -84) {
        std::cerr << "Sorry but Its not a library" << std::endl;
        this->exit = 84;
        return;
    }

    this->game.game = getLibrary(this->game.name);

    if (!verifIfIsLibrary(this->game.game)) {
        this->exit = 84;
        return;
    }

    void *creategame = dlsym(this->game.game, "creategame");
    auto game = ((AllForOne::IGame *(*)()) creategame)();
    std::shared_ptr<AllForOne::IGame> IGame(game, &destructorgame);
    this->games = IGame;
}

static int explore(const char *fpath, const struct stat *sb, int typeflag)
{
    if (typeflag == FTW_F) {
        if (fnmatch("*.so", fpath, FNM_CASEFOLD) == 0) {
            std::string Name(fpath);
            name.push_back(Name);
        }
    }
    return 0;
}

void Core::setNameLib(std::string &name)
{
    this->nameLib.push_back(name);
}

void Core::setNameGame(std::string &name)
{
    this->nameGame.push_back(name);
}

void Core::getALlLibrairi()
{
    ftw("lib", explore, 1);
    this->nameLib = std::move(name);
}

void Core::getALlGame()
{
    ftw("games", explore, 1);
    this->nameGame = std::move(name);
    for (auto it = begin(name); it != end(name); it++)
        std::cout << *it << std::endl;
}

void Core::goBackToTheMenu()
{
    this->status = 1;
}

void Core::restartGame()
{
    this->restart = true;
}

void destructorlib(LIB::ILibrari *lib)
{
    (void)lib;
}

void destructorgame(AllForOne::IGame *lib)
{
    (void)lib;
}
bool Core::verifIfIsLibrary(void *lib)
{
   return (dlsym(lib, "createLib") != nullptr && dlsym(lib, "destroyLib") != nullptr);
}

void *Core::getLibrary(std::string &name)
{
    void *library = dlopen(name.c_str(), RTLD_NOW);

    if (library == nullptr) {
        this->exit = 64;
        return (nullptr);
    }
    dlerror();
    return (library);
}

void Core::closeLibrary()
{
    dlclose(this->lib.libone);
}

int Core::getExit() const
{
    return (this->exit);
}

void Core::helper()
{
    std::cout << "./arcade lib.so" << std::endl;
    std::cout << "Description:\nUse a library to start a programme must be in directory lib/" << std::endl;
}
