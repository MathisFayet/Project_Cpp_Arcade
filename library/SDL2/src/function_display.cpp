/*
** EPITECH PROJECT, 2021
** init_structure.cpp
** File description:
** produce
*/

#include "../include/OneForAll.hpp"

void LIB::SDL2Graph::draw_rectangle_not_fill(SDL_Rect &rectangle, const SDL_Color& color)
{
        SDL_SetRenderDrawColor(this->renderWindow, color.r, color.g, color.b, color.a);

    for (int y = rectangle.y; y < rectangle.y + rectangle.h; y++) {
        for (int x = rectangle.x; x < rectangle.x + rectangle.w; x++) {
            if(x == rectangle.x)
                SDL_RenderDrawPoint(this->renderWindow, x, y);
            if(x == rectangle.x + rectangle.w - 1)
                SDL_RenderDrawPoint(this->renderWindow, x, y);
            if(y == rectangle.y)
                SDL_RenderDrawPoint(this->renderWindow, x, y);
            if(y == rectangle.y + rectangle.h - 1)
                SDL_RenderDrawPoint(this->renderWindow, x, y);
        }
    }
}

void LIB::SDL2Graph::drawRectangleNameScore()
{
    SDL_Rect rectangle1{20, 20, 400, 200};

    draw_rectangle_not_fill(rectangle1, SDL_Color{255, 255, 255, 255});
}

void LIB::SDL2Graph::drawRectangleTouch()
{
    SDL_Rect rectangle2{20, 900, 1850, 1000};

    draw_rectangle_not_fill(rectangle2, SDL_Color{255, 255, 255, 255});
}

void LIB::SDL2Graph::drawLib()
{
    SDL_RenderCopy(this->renderWindow, this->fontLib.Lib, nullptr, &this->fontLib.posLib);
    SDL_RenderCopy(this->renderWindow, this->fontLib.Lib1, nullptr, &this->fontLib.posLib1);
    SDL_RenderCopy(this->renderWindow, this->fontLib.Lib2, nullptr, &this->fontLib.posLib2);
    SDL_RenderCopy(this->renderWindow, this->fontLib.Lib3, nullptr, &this->fontLib.posLib3);
    SDL_RenderCopy(this->renderWindow, this->fontLib.Hyphen1, nullptr, &this->fontLib.posHyphen1);
    SDL_RenderCopy(this->renderWindow, this->fontLib.Hyphen2, nullptr, &this->fontLib.posHyphen2);
    SDL_RenderCopy(this->renderWindow, this->fontLib.Hyphen3, nullptr, &this->fontLib.posHyphen3);
}

void LIB::SDL2Graph::drawTouch()
{
    SDL_RenderCopy(this->renderWindow, this->fontTouch.touch1, nullptr, &this->fontTouch.posTouch1);

    SDL_RenderCopy(this->renderWindow, this->fontTouch.touch2, nullptr, &this->fontTouch.posTouch2);

    SDL_RenderCopy(this->renderWindow, this->fontTouch.touch3, nullptr, &this->fontTouch.posTouch3);
    SDL_RenderCopy(this->renderWindow, this->fontTouch.touch4, nullptr, &this->fontTouch.posTouch4);

    SDL_RenderCopy(this->renderWindow, this->fontTouch.touch5, nullptr, &this->fontTouch.posTouch5);

    SDL_RenderCopy(this->renderWindow, this->fontTouch.touch6, nullptr, &this->fontTouch.posTouch6);

    SDL_RenderCopy(this->renderWindow, this->fontTouch.touch7, nullptr, &this->fontTouch.posTouch7);

    SDL_RenderCopy(this->renderWindow, this->fontTouch.touch8, nullptr, &this->fontTouch.posTouch8);
    SDL_RenderCopy(this->renderWindow, this->fontTouch.touch9, nullptr, &this->fontTouch.posTouch9);
    SDL_RenderCopy(this->renderWindow, this->fontTouch.touch10, nullptr, &this->fontTouch.posTouch10);
}

void LIB::SDL2Graph::drawGame()
{
    SDL_RenderCopy(this->renderWindow, this->fontGame.Game, nullptr, &this->fontGame.posGame);
    SDL_RenderCopy(this->renderWindow, this->fontGame.Game1, nullptr, &this->fontGame.posGame1);
    SDL_RenderCopy(this->renderWindow, this->fontGame.Game2, nullptr, &this->fontGame.posGame2);
    SDL_RenderCopy(this->renderWindow, this->fontGame.Hyphen1, nullptr, &this->fontGame.posHyphen1);
    SDL_RenderCopy(this->renderWindow, this->fontGame.Hyphen2, nullptr, &this->fontGame.posHyphen2);
}

void LIB::SDL2Graph::drawMainMenu()
{
    SDL_SetRenderDrawColor(this->renderWindow, 0, 0, 255, 255);
    SDL_RenderClear(this->renderWindow);

    SDL_RenderCopy(this->renderWindow, this->texture.textureackground, nullptr, nullptr);
    drawRectangleNameScore();
    SDL_RenderCopy(this->renderWindow, this->fontText.textName, nullptr, &this->fontText.posName);
    SDL_RenderCopy(this->renderWindow, this->fontText.textScore, nullptr, &this->fontText.posScore);
    SDL_RenderCopy(this->renderWindow, this->fontText.textWindow, nullptr, &this->fontText.posWindow);
    drawRectangleTouch();
    drawLib();

    drawGame();

    drawTouch();
    SDL_RenderPresent(this->renderWindow);
}

void LIB::SDL2Graph::drawTextNameScore()
{
    SDL_SetRenderDrawColor(this->renderWindow, 0, 0, 255, 255);
    SDL_RenderClear(this->renderWindow);

    SDL_RenderCopy(this->renderWindow, this->texture.textureackground, nullptr, nullptr);
    drawRectangleNameScore();
    SDL_RenderCopy(this->renderWindow, this->fontText.textName, nullptr, &this->fontText.posName);
    SDL_RenderCopy(this->renderWindow, this->fontText.textScore, nullptr, &this->fontText.posScore);
    SDL_RenderCopy(this->renderWindow, this->fontText.textWindow, nullptr, &this->fontText.posWindow);
    SDL_RenderPresent(this->renderWindow);
}