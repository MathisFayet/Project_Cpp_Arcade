/*
** EPITECH PROJECT, 2021
** init_structure.cpp
** File description:
** produce
*/

#include "../include/SFML.hpp"

void LIB::Window::drawSprite()
{
    this->window.draw(this->sprite.Windowsprit);
}

void LIB::Window::drawTextNameScore()
{
    drawSquareName();
    this->window.draw(this->text.name.textName);
    this->window.draw(this->text.name.Score);
}

void LIB::Window::drawTouchBack()
{
    drawSquareTouch();
    this->window.draw(this->text.textTouch.textF1);
    this->window.draw(this->text.textTouch.textF2);
    this->window.draw(this->text.textTouch.textF3);
    this->window.draw(this->text.textTouch.textF4);
    this->window.draw(this->text.textTouch.textF5);
    this->window.draw(this->text.textTouch.textF6);
    this->window.draw(this->text.textTouch.textF7);
    this->window.draw(this->text.textTouch.textTAB);
    this->window.draw(this->text.textTouch.textUP);
    this->window.draw(this->text.textTouch.textDOWN);
}

void LIB::Window::drawText()
{
    this->window.draw(this->text.textNameWindow);
    this->window.draw(this->text.textGame.textGameOne);
    this->window.draw(this->text.textGame.textGameTwo);
    this->window.draw(this->text.textGame.HyphenGameOne);
    this->window.draw(this->text.textGame.HyphenGameTwo);
    this->window.draw(this->text.textGame.textGame);
    this->window.draw(this->text.textLib.textLib);
    this->window.draw(this->text.textLib.textLibSFML);
    this->window.draw(this->text.textLib.textLibSDL);
    this->window.draw(this->text.textLib.textLibNCURSES);
    this->window.draw(this->text.textLib.HyphenLibSFML);
    this->window.draw(this->text.textLib.HyphenLibSDL);
    this->window.draw(this->text.textLib.HyphenLibNCURSES);
    drawTouchBack();
    drawTextNameScore();
}

void LIB::Window::drawSquareName()
{
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(20, 20)),
        sf::Vertex(sf::Vector2f(20, 200))
    };
    sf::Vertex line2[] = {
        sf::Vertex(sf::Vector2f(20, 20)),
        sf::Vertex(sf::Vector2f(400, 20))
    };
    sf::Vertex line3[] = {
        sf::Vertex(sf::Vector2f(400, 20)),
        sf::Vertex(sf::Vector2f(400, 200))
    };
    sf::Vertex line4[] = {
        sf::Vertex(sf::Vector2f(20, 200)),
        sf::Vertex(sf::Vector2f(400, 200))
    };

    window.draw(line, 2, sf::Lines);
    window.draw(line2, 2, sf::Lines);
    window.draw(line3, 2, sf::Lines);
    window.draw(line4, 2, sf::Lines);
}

void LIB::Window::drawSquareTouch()
{
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(20, 900)),
        sf::Vertex(sf::Vector2f(20, 1000))
    };
    sf::Vertex line2[] = {
        sf::Vertex(sf::Vector2f(20, 900)),
        sf::Vertex(sf::Vector2f(1850, 900))
    };
    sf::Vertex line3[] = {
        sf::Vertex(sf::Vector2f(1850, 900)),
        sf::Vertex(sf::Vector2f(1850, 1000))
    };
    sf::Vertex line4[] = {
        sf::Vertex(sf::Vector2f(20, 1000)),
        sf::Vertex(sf::Vector2f(1850, 1000))
    };

    window.draw(line, 2, sf::Lines);
    window.draw(line2, 2, sf::Lines);
    window.draw(line3, 2, sf::Lines);
    window.draw(line4, 2, sf::Lines);
}

void LIB::Window::drawMainMenu()
{
    clearWindow();
    drawSprite();
    drawText();
    drawWindow();
}