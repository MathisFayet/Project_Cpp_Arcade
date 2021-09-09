/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
#define PARSING_HPP_

#include <iostream>
#include <vector>
#include <dirent.h>
#include "Core.hpp"

class Parsing {
    public:
        Parsing();
        ~Parsing();
        void PleaseWorkUFckingWindow();
        std::vector<std::string> FileParser(std::string path);
        std::unique_ptr<AllForOne::Core> _core;

    protected:
    private:
};

#endif /* !PARSING_HPP_ */
