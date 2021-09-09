/*
** EPITECH PROJECT, 2021
** init_structure.cpp
** File description:
** produce
*/

#include "../include/SFML.hpp"

void LIB::Window::initStart()
{
    this->window.create(sf::VideoMode(1920, 1080), "Arcade", sf::Style::Resize | sf::Style::Close);
    this->status.statusNameGame = 1;
    this->status.statusNameLib = 1;
    this->status.statusTab = 0;
    this->scoreGame = 0;
    this->status.statusWindow = 0;
    this->restartGame = false;
    this->name = "Paul";

    //:w!this->music.openFromFile("ressources/sound/Sound_Theme.ogg")

    if (!this->font.loadFromFile("ressources/font/Demode.ttf")) {
        this->exit = 84;
    } else {
        this->exit = 0;
    }
    fillStructureSprite();
    fillStructureText();
}

void LIB::Window::fillStructureSprite()
{

    if (!this->sprite.Windowtext.loadFromFile("ressources/picture/BackMenu.jpg"))
        this->exit = 84;
    this->sprite.Windowsprit.setTexture(this->sprite.Windowtext);
}

void LIB::Window::filleStrutureTextGame()
{

    this->text.textGame.textGame.setString("Game");
    this->text.textGame.textGame.setFont(this->font);
    this->text.textGame.textGame.setFillColor(sf::Color::White);
    this->text.textGame.textGame.setCharacterSize(42);
    this->text.textGame.textGame.setPosition(650, 350);

    this->text.textGame.HyphenGameOne.setString("- ");
    this->text.textGame.HyphenGameOne.setFont(this->font);
    this->text.textGame.HyphenGameOne.setFillColor(sf::Color::White);
    this->text.textGame.HyphenGameOne.setCharacterSize(32);
    this->text.textGame.HyphenGameOne.setPosition(635, 400);

    this->text.textGame.HyphenGameTwo.setString("- ");
    this->text.textGame.HyphenGameTwo.setFont(this->font);
    this->text.textGame.HyphenGameTwo.setFillColor(sf::Color::White);
    this->text.textGame.HyphenGameTwo.setCharacterSize(32);
    this->text.textGame.HyphenGameTwo.setPosition(635, 450);

    this->text.textGame.textGameOne.setString("Pacman");
    this->text.textGame.textGameOne.setFont(this->font);
    this->text.textGame.textGameOne.setFillColor(sf::Color::Red);
    this->text.textGame.textGameOne.setCharacterSize(32);
    this->text.textGame.textGameOne.setPosition(650, 400);

    this->text.textGame.textGameTwo.setString("Snake");
    this->text.textGame.textGameTwo.setFont(this->font);
    this->text.textGame.textGameTwo.setFillColor(sf::Color::White);
    this->text.textGame.textGameTwo.setCharacterSize(32);
    this->text.textGame.textGameTwo.setPosition(650, 450);

}

void LIB::Window::filleStrutureTextLib()
{
    this->text.textLib.textLib.setString("LIB");
    this->text.textLib.textLib.setFont(this->font);
    this->text.textLib.textLib.setFillColor(sf::Color::White);
    this->text.textLib.textLib.setCharacterSize(42);
    this->text.textLib.textLib.setPosition(1150, 350);

    this->text.textLib.textLibSFML.setString("SFML");
    this->text.textLib.textLibSFML.setFont(this->font);
    this->text.textLib.textLibSFML.setFillColor(sf::Color::Red);
    this->text.textLib.textLibSFML.setCharacterSize(32);
    this->text.textLib.textLibSFML.setPosition(1150, 400);

    this->text.textLib.textLibSDL.setString("SDL");
    this->text.textLib.textLibSDL.setFont(this->font);
    this->text.textLib.textLibSDL.setFillColor(sf::Color::White);
    this->text.textLib.textLibSDL.setCharacterSize(32);
    this->text.textLib.textLibSDL.setPosition(1150, 450);

    this->text.textLib.textLibNCURSES.setString("NCURSES");
    this->text.textLib.textLibNCURSES.setFont(this->font);
    this->text.textLib.textLibNCURSES.setFillColor(sf::Color::White);
    this->text.textLib.textLibNCURSES.setCharacterSize(32);
    this->text.textLib.textLibNCURSES.setPosition(1150, 500);

    filleStrutureTextLibHyphen();
}

void LIB::Window::filleStrutureTextLibHyphen()
{
    this->text.textLib.HyphenLibSFML.setString("- ");
    this->text.textLib.HyphenLibSFML.setFont(this->font);
    this->text.textLib.HyphenLibSFML.setFillColor(sf::Color::White);
    this->text.textLib.HyphenLibSFML.setCharacterSize(32);
    this->text.textLib.HyphenLibSFML.setPosition(1135, 400);

    this->text.textLib.HyphenLibSDL.setString("- ");
    this->text.textLib.HyphenLibSDL.setFont(this->font);
    this->text.textLib.HyphenLibSDL.setFillColor(sf::Color::White);
    this->text.textLib.HyphenLibSDL.setCharacterSize(32);
    this->text.textLib.HyphenLibSDL.setPosition(1135, 450);

    this->text.textLib.HyphenLibNCURSES.setString("- ");
    this->text.textLib.HyphenLibNCURSES.setFont(this->font);
    this->text.textLib.HyphenLibNCURSES.setFillColor(sf::Color::White);
    this->text.textLib.HyphenLibNCURSES.setCharacterSize(32);
    this->text.textLib.HyphenLibNCURSES.setPosition(1135, 500);
}

void LIB::Window::fillStrutureName()
{
    this->text.name.textName.setString("Name = " + this->name);
    this->text.name.textName.setFont(this->font);
    this->text.name.textName.setFillColor(sf::Color::White);
    this->text.name.textName.setCharacterSize(32);
    this->text.name.textName.setPosition(50, 50);

    this->text.name.Score.setString("Score = " + std::to_string(this->scoreGame));
    this->text.name.Score.setFont(this->font);
    this->text.name.Score.setFillColor(sf::Color::White);
    this->text.name.Score.setCharacterSize(32);
    this->text.name.Score.setPosition(50, 125);
}

void LIB::Window::fillStructureTextTouch()
{
    this->text.textTouch.textF1.setString("Previous graphics library: F1");
    this->text.textTouch.textF1.setFont(this->font);
    this->text.textTouch.textF1.setFillColor(sf::Color::White);
    this->text.textTouch.textF1.setCharacterSize(25);
    this->text.textTouch.textF1.setPosition(25, 915);

    this->text.textTouch.textF2.setString("Next graphics library: F2");
    this->text.textTouch.textF2.setFont(this->font);
    this->text.textTouch.textF2.setFillColor(sf::Color::White);
    this->text.textTouch.textF2.setCharacterSize(25);
    this->text.textTouch.textF2.setPosition(25, 950);

    this->text.textTouch.textF3.setString("Previous game: F3");
    this->text.textTouch.textF3.setFont(this->font);
    this->text.textTouch.textF3.setFillColor(sf::Color::White);
    this->text.textTouch.textF3.setCharacterSize(25);
    this->text.textTouch.textF3.setPosition(450, 915);

    this->text.textTouch.textF4.setString("Next game: F4");
    this->text.textTouch.textF4.setFont(this->font);
    this->text.textTouch.textF4.setFillColor(sf::Color::White);
    this->text.textTouch.textF4.setCharacterSize(25);
    this->text.textTouch.textF4.setPosition(450, 950);

    this->text.textTouch.textF5.setString("Restart the game: F5");
    this->text.textTouch.textF5.setFont(this->font);
    this->text.textTouch.textF5.setFillColor(sf::Color::White);
    this->text.textTouch.textF5.setCharacterSize(25);
    this->text.textTouch.textF5.setPosition(725, 915);

    this->text.textTouch.textF6.setString("Go back to the menu: F6");
    this->text.textTouch.textF6.setFont(this->font);
    this->text.textTouch.textF6.setFillColor(sf::Color::White);
    this->text.textTouch.textF6.setCharacterSize(25);
    this->text.textTouch.textF6.setPosition(725, 950);

    this->text.textTouch.textF7.setString("Exit: F7");
    this->text.textTouch.textF7.setFont(this->font);
    this->text.textTouch.textF7.setFillColor(sf::Color::White);
    this->text.textTouch.textF7.setCharacterSize(25);
    this->text.textTouch.textF7.setPosition(1100, 915);

    this->text.textTouch.textTAB.setString("Switch Game/Lib: TAB");
    this->text.textTouch.textTAB.setFont(this->font);
    this->text.textTouch.textTAB.setFillColor(sf::Color::White);
    this->text.textTouch.textTAB.setCharacterSize(25);
    this->text.textTouch.textTAB.setPosition(1100, 950);

    this->text.textTouch.textUP.setString("Up: UP");
    this->text.textTouch.textUP.setFont(this->font);
    this->text.textTouch.textUP.setFillColor(sf::Color::White);
    this->text.textTouch.textUP.setCharacterSize(25);
    this->text.textTouch.textUP.setPosition(1500, 915);

    this->text.textTouch.textDOWN.setString("Down: Down");
    this->text.textTouch.textDOWN.setFont(this->font);
    this->text.textTouch.textDOWN.setFillColor(sf::Color::White);
    this->text.textTouch.textDOWN.setCharacterSize(25);
    this->text.textTouch.textDOWN.setPosition(1500, 950);

}

void LIB::Window::fillStructureText()
{
    this->text.textNameWindow.setString("Arcade - SFML INTERFACE");
    this->text.textNameWindow.setFont(this->font);
    this->text.textNameWindow.setFillColor(sf::Color::White);
    this->text.textNameWindow.setCharacterSize(50);
    this->text.textNameWindow.setPosition(650, 63);

    filleStrutureTextGame();
    filleStrutureTextLib();
    fillStrutureName();
    fillStructureTextTouch();
}