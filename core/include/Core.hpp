/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "../../librari/ILibrari.hpp"
#include <memory>
#include <dirent.h>
#include <vector>
#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<string.h>
#include<fstream>
#include <ftw.h>
#include <fnmatch.h>
#include "../../games/IGame.hpp"

typedef struct s_librari {
    void *libone;
    std::string name;
} librari_t;

typedef struct s_game {
    void *game;
    std::string name;
} game_t;

typedef struct s_gamelib {
    int gameStatus;
    int libStatus;
} gamelib_t;

class Core {
    public:
        Core();
        ~Core();

        int Game(std::string);
        void *getLibrary(std::string &name);
        void closeLibrary();
        bool verifIfIsLibrary(void *);

        void getLibARGV(std::string &);
        void getGame(std::string &);
        void getALlLibrairi();
        void getALlGame();

        int handleEvent(Input input);
        void helper();

        void changeLibandGame();

        void encapsulationLib();
        void encapsulationGame();
        void nextGame();
        void previousGame();
        void nextLib();
        void PreviousLib();

        void goBackToTheMenu();
        void restartGame();

        int getExit() const;

        int windowLoop();
        int gameLoop();

        void setNameLib(std::string &);
        void setNameGame(std::string &);

    private:
        int exit;
        librari_t lib;
        game_t game;
        std::shared_ptr<LIB::ILibrari> library;
        std::shared_ptr<AllForOne::IGame> games;
        std::vector<std::string> nameLib;
        std::vector<std::string> nameGame;
        int libpos;
        int gamepos;
        int status;
        bool restart;
        gamelib_t statusgamelib;
};

void destructorlib(LIB::ILibrari *lib);
void destructorgame(AllForOne::IGame *lib);
#endif /* !CORE_HPP_ */
