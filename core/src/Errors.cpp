/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** Errors
*/

#include "Errors.hpp"

Errors::Errors(std::string const &message, std::string const &component)
{
}

Errors::~Errors()
{
}

void Errors::CheckArguments(int index, char **lib)
{
    if (index != 2)
    {
        std::cout << "ERROR, It must be : ./arcade ./lib/lib_name.so" << std::endl;
        exit(84);
    }
}

GraphicalInitError::GraphicalInitError(std::string const &message, std::string const &component) : Errors(message, component)
{

}