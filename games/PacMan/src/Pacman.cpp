/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** Pacman
*/

#include "../include/Pacman.hpp"

AllForOne::Pacman::Pacman()
{
    GameReset();
}

AllForOne::Pacman::~Pacman()
{
}

void AllForOne::Pacman::MoveWithInput(Input input)
{
    if (input == LEFT_ARROW || input == UP_ARROW || input == RIGHT_ARROW || input == DOWN_ARROW)
    {
        _OkInput = input;
    }
}

std::string AllForOne::Pacman::GameName()
{
    return std::string("Pacman");
}

std::string AllForOne::Pacman::GetBackground()
{
    return std::string("./../../ressources/background/retro_background.jpeg");
}

void AllForOne::Pacman::GameReset()
{
    _OkInput = NO_INPUT;
    _DIR = RIGHT_ARROW;
    _Miam = false;
    _Score = 0;
    _Animation = true;
    _GameOver = false;
    _Background.clear();
    
}