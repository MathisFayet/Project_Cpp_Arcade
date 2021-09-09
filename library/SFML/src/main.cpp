/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** produce
*/

#include "../include/SFML.hpp"

int handleEvent(Input input, LIB::Window &sfml)
{
    switch(input) {
        case Input::NO_INPUT:
            return (true);
        case Input::F1:
            sfml.previousGraphicsLibrary();
            break;
        case Input::F2:
            sfml.nextGraphicsLibrary();
            break;
        case Input::F3:
            sfml.previousGame();
            break;
        case Input::F4:
            sfml.nextGame();
            break;
        case Input::F5:
            sfml.restartTheGame();
            break;
        case Input::F6:
            sfml.goBackToTheMenu();
            break;
        case Input::F7:
            sfml.destroyWindow();
            return (false);
        default:
            return (true);
        }
    return (true);
}

int main()
{
    bool exit = true;

    LIB::Window sfml;

    sfml.initStart();
    if (sfml.getExit() == 84) {
        return (84);
    }
    sfml.playSound();

    while (exit) {
        Input input = sfml.getInput();
        std::cout << input << std::endl;
        exit = handleEvent(input, sfml);
        sfml.drawMainMenu();
    }
    return (0);
}
