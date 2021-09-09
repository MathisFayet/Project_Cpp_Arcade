/*
** EPITECH PROJECT, 2021
** nCurse
** File description:
** main
*/
/*

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
{ // Function for draw les noms
    int index = 0;
    int move = 0;

    std::string name_games[2] = {
        "Nibbler",
        "PacMan"
    };
    for (index = 0; index < 2; index++) {
        if (index == move) {
            wattron(this->window[GAMES].win, A_REVERSE);
        }
        mvwprintw(this->window[GAMES].win, index+2, 2, name_games[index].c_str());
        wattroff(this->window[GAMES].win, A_REVERSE);
    }
    index = 0;
    std::string name_lib[3] = {
        "SFML",
        "SDL2",
        "nCurses"
    };
    for (index = 0; index < 3; index++) {
        if (index == move) {
            wattron(this->window[LIBR].win, A_REVERSE);
        }
        mvwprintw(this->window[LIBR].win, index+2, 2, name_lib[index].c_str());
        wattroff(this->window[LIBR].win, A_REVERSE);
    }
    index = 0;
    std::string name_libr[3] = {
        "PREVIOUS GRAPHICS LIBRARY: F1",
        "",
        "NEXT GRAPHICS LIBRARY: F2"
    };
    std::string names_games[3] = {
        "PREVIOUS GAME: F3",
        "",
        "NEXT GAME: F4"
    };
    std::string names_options[3] = {
        "RESTART THE GAME: F5",
        "",
        "GO BACK TO THE MENU: F6"
    };
    std::string names_switch[3] = {
        "EXIT: F7",
        "",
        "SWITCH GAME/LIB: TAB"
    };
    std::string names_moove[3] = {
        "UP: UP",
        "",
        "DOWN: DOWN"
    };

    while (index < 3) {
        mvwprintw(this->window[OPTIONS].win, index+3, 4, name_libr[index].c_str());
        mvwprintw(this->window[OPTIONS].win, index+3, 38, names_games[index].c_str());
        mvwprintw(this->window[OPTIONS].win, index+3, 62, names_options[index].c_str());
        mvwprintw(this->window[OPTIONS].win, index+3, 91, names_switch[index].c_str());
        mvwprintw(this->window[OPTIONS].win, index+3, 120, names_moove[index].c_str());
        wattroff(this->window[OPTIONS].win, A_REVERSE);
        index++;
    }

    index = 0;
    std::string name_names[1] = { 
        "Names: "
    };
    std::string name_scoreboard[1] = {
        "Score: ",
    };
    while (index < 1) {
        mvwprintw(this->window[SCOREBOARD].win, index+4, 2, name_names[index].c_str());
        mvwprintw(this->window[SCOREBOARD].win, index+8, 2, name_scoreboard[index].c_str());
        wattroff(this->window[SCOREBOARD].win, A_REVERSE);
        index++;
    }
}

LIB::Draw create_module(int height, int width, int y, int x)
{
    LIB::Draw m(height, width, x, y, newwin(height, width, y, x));
    return m;
}

void LIB::Draw::draw_my_lib()
{
    if (this->window[GAMES].win) {
        wclear(this->window[GAMES].win);
        box(this->window[GAMES].win, 0, 0);
        wprintw(this->window[GAMES].win, "Choose you're games ");
    }
    if (this->window[LIBR].win) {
        wclear(this->window[LIBR].win);
        box(this->window[LIBR].win, 0, 0);
        wprintw(this->window[LIBR].win, "Choose you're lib ");
    }
    if (this->window[OPTIONS].win) {
        wclear(this->window[OPTIONS].win);
        box(this->window[OPTIONS].win, 0, 0);
        wprintw(this->window[OPTIONS].win, "All the options for this menu ");


    }
    if (this->window[SCOREBOARD].win) {
        wclear(this->window[SCOREBOARD].win);
        box(this->window[SCOREBOARD].win, 0, 0);
        wprintw(this->window[SCOREBOARD].win, "You're scoreboard ");
    }
}

void LIB::Draw::reload_window()
{
    unsigned int x = 0;
    unsigned int y = 0;

    clear();
    draw_my_lib();  // --> call my function()

    getmaxyx(stdscr, x, y);
    this->width = x;
    this->height = y;
    refresh();

    wrefresh(this->window[GAMES].win);
    wrefresh(this->window[LIBR].win);
    wrefresh(this->window[OPTIONS].win);
    wrefresh(this->window[SCOREBOARD].win);
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
    this->window[GAMES] = create_module(20, 25, 15, 145);
    this->window[LIBR] = create_module(20, 25, 15, 80);
    this->window[OPTIONS] = create_module(9, 201, 43, 5);
    this->window[SCOREBOARD] = create_module(30, 50, 2, 4);

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
    mvwprintw(this->window[GAMES].win, 1, 1 ,"Score");
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

*/