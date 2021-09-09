/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** Parsing
*/

#include "../include/Parsing.hpp"

Parsing::Parsing()
{
}

Parsing::~Parsing()
{
}

void Parsing::PleaseWorkUFckingWindow()
{
    _core->MainLoop();
}

std::vector<std::string> FileParser(std::string path)
{
    size_t check = 0;
    DIR *filename = nullptr;
    filename = opendir(path.c_str());
    struct dirent *directory = nullptr;
    std::vector<std::string> dir_name;

    if (filename == nullptr)
    {
        exit(84);
    }

    while ((directory = readdir(filename)) != nullptr)
    {
        std::string save(directory->d_name);
        check = save.find(".so");
        if (check != std::string::npos)
        {
            dir_name.push_back(save);
        }
    }
    return (dir_name);
}