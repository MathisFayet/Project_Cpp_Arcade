/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** main
*/

#include "../include/Core.hpp"

int main(int ac, char **av)
{
    Core core;

    if (ac != 2 || av[1] == nullptr) {
        core.helper();
        return (84);
    }
    return (core.Game(av[1]));
}
