/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include "../../ILibrari.hpp"

typedef struct s_text_game {
    sf::Text textGame;
    sf::Text textGameOne;
    sf::Text textGameTwo;
    sf::Text HyphenGameOne;
    sf::Text HyphenGameTwo;
} text_game_t;

typedef struct s_text_lib {
    sf::Text textLib;
    sf::Text textLibSFML;
    sf::Text textLibSDL;
    sf::Text textLibNCURSES;
    sf::Text HyphenLibSFML;
    sf::Text HyphenLibSDL;
    sf::Text HyphenLibNCURSES;
} text_lib_t;

typedef struct s_square_name {
    sf::Text textName;
    sf::Text Score;
} square_name_t;

typedef struct s_text_touch {
    sf::Text textF1;
    sf::Text textF2;
    sf::Text textF3;
    sf::Text textF4;
    sf::Text textF5;
    sf::Text textF6;
    sf::Text textF7;
    sf::Text textTAB;
    sf::Text textUP;
    sf::Text textDOWN;
} text_touch_t;

typedef struct s_text {
    sf::Text textNameWindow;
    text_game_t textGame;
    text_lib_t textLib;
    square_name_t name;
    text_touch_t textTouch;
} text_t;

typedef struct s_sprite {
    sf::Texture Windowtext;
    sf::Sprite Windowsprit;

    typedef enum {
        WINDOW,
        GAME,
        UNDIFINE
    } Name;
    Name name;
} sprite_t;

typedef struct s_status {
    int statusNameGame;
    int statusNameLib;
    int statusTab;
    int statusWindow;
} status_t;

typedef struct s_score {
    std::string name;
    int score;
} score_t;

namespace LIB {
    class SaveScore {
        public:
            SaveScore();
            ~SaveScore();

            typedef enum {
                PACMAN,
                SNAKE
            } Game;
            void createFilePacman(std::string name, int score);
            void parsingFilePacman();

            void createFileSnake(std::string name, int score);
            void parsingFileSnake();

            void saveDataPacman(std::string name, int score);
            void saveDataSnake(std::string name, int score);
            void saveDataGame(std::string name, int score, LIB::SaveScore::Game);

            std::vector<score_t> getHightScorePacman();
            std::vector<score_t> getHightScoreSnake();

        private:
            std::string name;
            int score;
            std::string hightScore;
            int higthScore;
    };

    class Window : public LIB::ILibrari {
        public:
            Window();
            ~Window();

            void drawMainMenu();
            void windowWin();
            void windowLoose();
            Input getInput();

            void drawSprite();
            void drawText();
            void clearWindow();
            void destroyWindow();
            void drawWindow();

            void switchUp();
            void switchDown();
            void switchTab();

            void drawSquareName();
            void drawSquareTouch();

            void setText(text_t &);
            text_t getText(std::string &) const;

            void nextGame();
            void previousGame();
            void nextGraphicsLibrary();
            void previousGraphicsLibrary();

            void fillStructureSprite();
            void fillStructureText();
            void filleStrutureTextGame();
            void filleStrutureTextLib();
            void filleStrutureTextLibHyphen();
            void fillStrutureName();
            void fillStructureTextTouch();

            void drawTextNameScore();
            void drawTouchBack();

            int getExit() const;

            void initStart();
            void playSound();
            void stopSound();

            void setSprite(sprite_t &);
            sprite_t getSprite(std::string &) const;

            int getGame() const;
            int getLib() const;

        private:
            LIB::SaveScore savescore;
            status_t status;
            text_t text;
            sprite_t sprite;
//            sf::Music music;
            sf::Font font;
            sf::Event event;
            sf::RenderWindow window;
            std::string name;
            int scoreGame;
            int exit;
            bool restartGame;
    };
};

#endif /* !SFML_HPP_ */
