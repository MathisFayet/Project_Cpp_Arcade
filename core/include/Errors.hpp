/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <iostream>

class Errors {
    public:
        Errors(std::string const &message, std::string const &component);
        ~Errors();
        void CheckArguments(int index, char **lib);

    protected:
    private:
};

class   GraphicalInitError : public Errors
{
public:
	GraphicalInitError(std::string const &message,
		  std::string const &component = "Unknown");
};

#endif /* !ERRORS_HPP_ */
