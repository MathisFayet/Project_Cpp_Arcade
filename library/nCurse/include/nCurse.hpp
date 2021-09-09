/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** nCurse
*/

#ifndef NCURSE_HPP_
#define NCURSE_HPP_

#include <ncurses.h>
#include <string>
#include <iostream>
#include <map>

#include "../../../librari/ILibrari.hpp"

typedef struct s_status {
    int statusNameGame;
    int statusNameLib;
    int statusTab;
    int statusWindow;
} status_t;

namespace LIB {
    class Draw : public LIB::ILibrari
    {
        public:
        /* Function for all lib */
            void drawMainMenu(); //draw les noms
            void initStart(); // creer ma window 
            void windowWin();
            void windowLoose();
            Input getInput(); // return les input check enum
            void drawTextNameScore(); // ça draw le name et le score en haut            int getExit() const; // int exit 84 si la window a des problemes (function pour check le probleme)
            void playSound();
            void stopSound();
            int getGame() const;
            int getLib() const;
            int getExit() const;
            void destroyWindow();

        /* Function add */
            void launch_library();
            void reload_window();
            void draw_my_lib();

        private:
            int width;
            int height;
            status_t status;
            int letter = 0;
            int exit;
            WINDOW *win;
            WINDOW *games;
            WINDOW *lib;
            WINDOW *options;
            WINDOW *scoreboard;

        protected:
    };
}
#endif /* !NCURSE_HPP_ */