/*
** EPITECH PROJECT, 2021
** nCurse
** File description:
** main
*/

#include "../include/nCurse.hpp"
#include <curses.h>

extern "C" LIB::ILibrari *createLib()
{
    return (new LIB::Draw());
}

extern "C" void destroyLib(LIB::ILibrari *lib)
{
    delete lib;
}

void LIB::Draw::drawMainMenu()
{ // Function for draw all
    int move = 0;
    int i = 0;
    std::string choice[2    ] = { 
        "Nibbler",
        "Pacman"
    };
        wattroff(this->games, A_REVERSE);
        mvwprintw(this->games, i+1, 10, "xxx");
    for (i = 0; i < 3; i++) {
        if (i == move) {
            wattron(this->games, A_REVERSE);
        }
    }
}

void LIB::Draw::initStart()
{
    initscr();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    cbreak();
    noecho();
    curs_set(0);

    getmaxyx(stdscr, this->width, this->height);
    if (has_colors()) {
        start_color();
    }

    this->games = newwin(20, 25, 5, 50);
    box(this->games, 0, 0);
    wprintw(this->games, "Choose you're games ");
    refresh();
    wrefresh(this->games);

    this->lib = newwin(20, 25, 5, 100);
    box(this->lib, 0, 0);
    wprintw(this->lib, "Choose you're lib ");
    refresh();
    wrefresh(this->lib);

    this->options = newwin(9, 120, 28, 5);
    box(this->options, 0, 0);
    wprintw(this->options, "Choose you're options ");
    refresh();
    wrefresh(this->options);


    this->scoreboard = newwin(15, 25, 2, 4);
    box(this->scoreboard, 0, 0);
    wprintw(this->scoreboard, "You're scoreboard ");
    refresh();
    wrefresh(this->scoreboard);
    //reload_window(); // --> call my function()
}

void LIB::Draw::windowWin()
{}

void LIB::Draw::windowLoose()
{}

Input LIB::Draw::getInput()
{
    this->letter = getch();

// INPUT FOR F(1-7)
    if (this->letter == KEY_F(1))
        return (Input::F1);
    if (this->letter == KEY_F(2))
        return (Input::F2);
    if (this->letter == KEY_F(3))
        return (Input::F3);
    if (this->letter == KEY_F(4))
        return (Input::F4);
    if (this->letter == KEY_F(5))
        return (Input::F5);
    if (this->letter == KEY_F(6))
        return (Input::F6);
    if (this->letter == KEY_F(7) || this->letter == 27)
        return (Input::F7);
    if (this->letter == 10)
        return (Input::ENTER);
    return (Input::NO_INPUT);
}

void LIB::Draw::drawTextNameScore()
{
    mvwprintw(this->scoreboard, 1, 1 ,"Score");
}

int LIB::Draw::getExit() const  
{
    return (this->exit);
}

void LIB::Draw::playSound() // Nothing else
{}

void LIB::Draw::stopSound() // Nothing else
{}

int LIB::Draw::getGame() const
{
    return (1);
}

int LIB::Draw::getLib() const
{
    return (1);
}

void LIB::Draw::destroyWindow()
{
    endwin();
}
