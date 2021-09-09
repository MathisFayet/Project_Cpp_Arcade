/*
** EPITECH PROJECT, 2021
** SFML.cpp
** File description:
** produce
*/

#include "../include/SFML.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowHandle.hpp>
#include <fstream>
#include <memory>
#include <string>

extern "C" LIB::ILibrari *createLib()
{
    return (new LIB::Window());
}

extern "C" void destroyLib(LIB::ILibrari *lib)
{
    delete lib;
}

LIB::Window::Window()
{
}

LIB::Window::~Window()
{
}

void LIB::Window::windowWin()
{

}

void LIB::Window::windowLoose()
{

}

Input LIB::Window::getInput()
{
    if (!this->window.pollEvent(event))
        return (Input::NO_INPUT);
    if (this->event.type == sf::Event::Closed)
        return (Input::F7);
    if (this->event.type == sf::Event::KeyPressed) {
        if (this->event.key.code == sf::Keyboard::Escape || this->event.key.code == sf::Keyboard::F7)
            return (Input::F7);
        if (this->event.key.code == sf::Keyboard::Up) {
            switchUp();
            return (Input::UP_ARROW);
        }
        if (this->event.key.code == sf::Keyboard::Down) {
            switchDown();
            return (Input::DOWN_ARROW);
        }
        if (this->event.key.code == sf::Keyboard::Tab) {
            switchTab();
            return (Input::TAB);
        }
        if (this->event.key.code == sf::Keyboard::F1)
            return (Input::F1);
        if (this->event.key.code == sf::Keyboard::F2)
            return (Input::F2);
        if (this->event.key.code == sf::Keyboard::F3)
            return (Input::F3);
        if (this->event.key.code == sf::Keyboard::F4)
            return (Input::F4);
        if (this->event.key.code == sf::Keyboard::F5)
            return (Input::F5);
        if (this->event.key.code == sf::Keyboard::F6)
            return (Input::F6);
        if (this->event.key.code == sf::Keyboard::Enter)
            return (Input::ENTER);
        /*
        if (event.text.unicode > 30 && (event.text.unicode < 127 || event.text.unicode > 159) && name.length() < 20) {
            return (Input::NO_INPUT);
        }
        */
    }
    return (Input::NO_INPUT);
}

void LIB::Window::clearWindow()
{
    this->window.clear();
}

void LIB::Window::drawWindow()
{
    this->exit = 1;
    this->window.display();
}

void LIB::Window::destroyWindow()
{
    //:wstopSound();
    this->window.close();
}

void LIB::Window::switchUp()
{
    if (this->status.statusNameGame == 2 && this->status.statusTab == 0) {
        this->text.textGame.textGameOne.setFillColor(sf::Color::Red);
        this->text.textGame.textGameTwo.setFillColor(sf::Color::White);
        this->status.statusNameGame = 1;
    }

    if (this->status.statusNameLib == 2 && this->status.statusTab == 1) {
        this->text.textLib.textLibSDL.setFillColor(sf::Color::White);
        this->text.textLib.textLibSFML.setFillColor(sf::Color::Red);
        this->text.textLib.textLibNCURSES.setFillColor(sf::Color::White);
        this->status.statusNameLib = 1;
    } else if (this->status.statusNameLib == 3 && this->status.statusTab == 1) {
        this->text.textLib.textLibSDL.setFillColor(sf::Color::Red);
        this->text.textLib.textLibSFML.setFillColor(sf::Color::White);
        this->text.textLib.textLibNCURSES.setFillColor(sf::Color::White);
        this->status.statusNameLib = 2;
    }
}

void LIB::Window::switchDown()
{
    if (this->status.statusNameGame == 1 && this->status.statusTab == 0) {
        this->text.textGame.textGameOne.setFillColor(sf::Color::White);
        this->text.textGame.textGameTwo.setFillColor(sf::Color::Red);
        this->status.statusNameGame = 2;
        return;
    }

    if (this->status.statusNameLib == 1 && this->status.statusTab == 1) {
        this->text.textLib.textLibSDL.setFillColor(sf::Color::Red);
        this->text.textLib.textLibSFML.setFillColor(sf::Color::White);
        this->text.textLib.textLibNCURSES.setFillColor(sf::Color::White);
        this->status.statusNameLib = 2;
    } else if (this->status.statusNameLib == 2 && this->status.statusTab == 1) {
        this->text.textLib.textLibSDL.setFillColor(sf::Color::White);
        this->text.textLib.textLibSFML.setFillColor(sf::Color::White);
        this->text.textLib.textLibNCURSES.setFillColor(sf::Color::Red);
        this->status.statusNameLib = 3;
    }
}

void LIB::Window::switchTab()
{
    if (this->status.statusTab == 0)
        this->status.statusTab = 1;
    else
        this->status.statusTab = 0;
}

void LIB::Window::nextGame()
{
    if (this->status.statusNameGame == 1) {
        this->text.textGame.textGameOne.setFillColor(sf::Color::White);
        this->text.textGame.textGameTwo.setFillColor(sf::Color::Red);
        this->status.statusNameGame = 2;
    } else if (this->status.statusNameGame == 2) {
        this->text.textGame.textGameOne.setFillColor(sf::Color::Red);
        this->text.textGame.textGameTwo.setFillColor(sf::Color::White);
        this->status.statusNameGame = 1;
    }
}

void LIB::Window::previousGame()
{
    if (this->status.statusNameGame == 2) {
        this->text.textGame.textGameOne.setFillColor(sf::Color::Red);
        this->text.textGame.textGameTwo.setFillColor(sf::Color::White);
        this->status.statusNameGame = 1;
    } else if (this->status.statusNameGame == 1) {
        this->text.textGame.textGameOne.setFillColor(sf::Color::White);
        this->text.textGame.textGameTwo.setFillColor(sf::Color::Red);
        this->status.statusNameGame = 2;
    }
}

void LIB::Window::nextGraphicsLibrary()
{
    if (this->status.statusNameLib == 1) {
        this->text.textLib.textLibSDL.setFillColor(sf::Color::Red);
        this->text.textLib.textLibSFML.setFillColor(sf::Color::White);
        this->text.textLib.textLibNCURSES.setFillColor(sf::Color::White);
        this->status.statusNameLib = 2;
    } else if (this->status.statusNameLib == 2) {
        this->text.textLib.textLibSDL.setFillColor(sf::Color::White);
        this->text.textLib.textLibSFML.setFillColor(sf::Color::White);
        this->text.textLib.textLibNCURSES.setFillColor(sf::Color::Red);
        this->status.statusNameLib = 3;
    } else {
        this->text.textLib.textLibSDL.setFillColor(sf::Color::White);
        this->text.textLib.textLibSFML.setFillColor(sf::Color::Red);
        this->text.textLib.textLibNCURSES.setFillColor(sf::Color::White);
        this->status.statusNameLib = 1;
    }
}

void LIB::Window::previousGraphicsLibrary()
{
    if (this->status.statusNameLib == 2) {
        this->text.textLib.textLibSDL.setFillColor(sf::Color::White);
        this->text.textLib.textLibSFML.setFillColor(sf::Color::Red);
        this->text.textLib.textLibNCURSES.setFillColor(sf::Color::White);
        this->status.statusNameLib = 1;
    } else if (this->status.statusNameLib == 3) {
        this->text.textLib.textLibSDL.setFillColor(sf::Color::Red);
        this->text.textLib.textLibSFML.setFillColor(sf::Color::White);
        this->text.textLib.textLibNCURSES.setFillColor(sf::Color::White);
        this->status.statusNameLib = 2;
    } else {
        this->text.textLib.textLibSDL.setFillColor(sf::Color::White);
        this->text.textLib.textLibSFML.setFillColor(sf::Color::White);
        this->text.textLib.textLibNCURSES.setFillColor(sf::Color::Red);
        this->status.statusNameLib = 3;
    }
}

int LIB::Window::getLib() const
{
    return (this->status.statusNameLib);
}

int LIB::Window::getGame() const
{
    return (this->status.statusNameGame);
}

int LIB::Window::getExit() const
{
    return (this->exit);
}

void LIB::Window::playSound()
{
    //this->music.play();
}

void LIB::Window::stopSound()
{
    //this->music.stop();
}
