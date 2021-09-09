/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** Nibbler
*/

#include "../include/Nibbler.hpp"

extern "C" AllForOne::IGame *creategame()
{
        return new(AllForOne::Nibbler);
}

extern "C" void destroygame(AllForOne::Nibbler *game)
{
        delete (dynamic_cast<AllForOne::IGame *>(game));
}

AllForOne::Nibbler::Nibbler()
{

}

AllForOne::Nibbler::~Nibbler()
{

}

int AllForOne::Nibbler::getExit() const
{
    return (this->exit);
}

int AllForOne::Nibbler::getScore() const
{
    return (this->score);
}

void AllForOne::Nibbler::initAll()
{
    this->exit = 0;
    this->score = 0;
    this->sizeSnake = 4;
    readMap();
}

void AllForOne::Nibbler::gameLoop()
{
    readMap();
}

void AllForOne::Nibbler::readMap()
{
    std::fstream indata;
    int num;
    indata.open("map.txt");

    if(!indata) {
        std::cerr << "Error: file could not be opened" << std::endl;
        return;
    }
    indata >> num;
    while ( !indata.eof() ) {
        indata >> num;
    }
    indata.close();
    std::cout << "End-of-file reached.." << std::endl;
}
