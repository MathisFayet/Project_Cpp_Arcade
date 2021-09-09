/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** OneForAll
*/

#ifndef ONEFORALL_HPP_
#define ONEFORALL_HPP_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../../ILibrari.hpp"

typedef struct s_texture {
    SDL_Texture *textureackground;
    SDL_Surface *surfaceackground;
} texture_t;

typedef struct s_render {
    SDL_Renderer *renderWindow;
} render_t;

typedef struct s_window {
    SDL_Window *window;
} window_t;

typedef struct s_fontText {
    SDL_Texture *textWindow;
    SDL_Rect posWindow;
    SDL_Texture *textName;
    SDL_Rect posName;
    SDL_Texture *textScore;
    SDL_Rect posScore;
} fontText_t;

typedef struct s_FontGame {
    SDL_Texture *Game;
    SDL_Rect posGame;

    SDL_Texture *Game1;
    SDL_Rect posGame1;
    SDL_Texture *Game2;
    SDL_Rect posGame2;

    SDL_Texture *Hyphen1;
    SDL_Rect posHyphen1;
    SDL_Texture *Hyphen2;
    SDL_Rect posHyphen2;
} FontGame_t;

typedef struct s_FontLib {
    SDL_Texture *Lib;
    SDL_Rect posLib;

    SDL_Texture *Lib1;
    SDL_Rect posLib1;
    SDL_Texture *Lib2;
    SDL_Rect posLib2;
    SDL_Texture *Lib3;
    SDL_Rect posLib3;

    SDL_Texture *Hyphen1;
    SDL_Rect posHyphen1;
    SDL_Texture *Hyphen2;
    SDL_Rect posHyphen2;
    SDL_Texture *Hyphen3;
    SDL_Rect posHyphen3;
} FontLib_t;

typedef struct s_fontTouch {
    SDL_Texture *touch1;
    SDL_Rect posTouch1;
    SDL_Texture *touch2;
    SDL_Rect posTouch2;
    SDL_Texture *touch3;
    SDL_Rect posTouch3;
    SDL_Texture *touch4;
    SDL_Rect posTouch4;
    SDL_Texture *touch5;
    SDL_Rect posTouch5;
    SDL_Texture *touch6;
    SDL_Rect posTouch6;
    SDL_Texture *touch7;
    SDL_Rect posTouch7;
    SDL_Texture *touch8;
    SDL_Rect posTouch8;
    SDL_Texture *touch9;
    SDL_Rect posTouch9;
    SDL_Texture *touch10;
    SDL_Rect posTouch10;
} fontTouch_t;

typedef struct s_status {
    int statusNameLib;
    int statusNameGame;
    int statusTab;
} status_t;

namespace LIB
{
    class SDL2Graph: public LIB::ILibrari
    {
        public:
            SDL2Graph();
            ~SDL2Graph();
            void Score(int score);

            void drawScene();
            void clearScene();
            void initSurface();
            void initTexture();
            void initFontTextWindow();
            void initFontTextName();
            void initFontTextScore();
            void initRender();

            void initFontTouch();

            void initGame();
            void initFontGame();
            void initHyphenGame();

            void initLib();
            void initFontLib();
            void initHyphenLib();

            TTF_Font *initFont(const std::string &, int);
            SDL_Surface *initSurface(TTF_Font *, const std::string &, const SDL_Color &);
            SDL_Rect initRect(int x, int y, int h, int w);

            void drawMainMenu();


            Input getInput();
            void windowWin();
            void windowLoose();
            void destroyMainMenu();
            void initStart();
            void playSound();
            void stopSound();
            int getExit() const;

            void drawTextNameScore();

            void switchUp();
            void switchDown();
            void switchTab();

            void destroyWindow();
            void draw_rectangle_not_fill(SDL_Rect &rectangle, const SDL_Color &color);

            void drawRectangleNameScore();
            void drawRectangleTouch();
            void drawGame();
            void drawLib();
            void drawTouch();

            int getGame() const;
            int getLib() const;

        private:
            SDL_Window *window;
            SDL_Renderer *renderWindow;

            unsigned int score;
            std::string name;

            SDL_Event event;
            texture_t texture;
            fontText_t fontText;
            int exit;

            FontLib_t fontLib;
            FontGame_t fontGame;
            fontTouch_t fontTouch;

            status_t status;
    };
}

#endif /* !ONEFORALL_HPP_ */
