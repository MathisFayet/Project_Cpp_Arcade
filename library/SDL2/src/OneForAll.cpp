/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** OneForAll
*/

#include "../include/OneForAll.hpp"

extern "C" LIB::ILibrari *createLib()
{
    return (new LIB::SDL2Graph());
}

extern "C" void destroyLib(LIB::ILibrari *lib)
{
    delete lib;
}

LIB::SDL2Graph::SDL2Graph()
{
}

LIB::SDL2Graph::~SDL2Graph()
{
}

int LIB::SDL2Graph::getExit() const
{
    return (this->exit);
}

void LIB::SDL2Graph::destroyWindow()
{
    SDL_DestroyTexture(this->fontGame.Hyphen1);
    SDL_DestroyTexture(this->fontGame.Hyphen2);

    SDL_DestroyTexture(this->fontGame.Game);
    SDL_DestroyTexture(this->fontGame.Game1);
    SDL_DestroyTexture(this->fontGame.Game2);

    SDL_DestroyTexture(this->fontTouch.touch1);
    SDL_DestroyTexture(this->fontTouch.touch2);
    SDL_DestroyTexture(this->fontTouch.touch3);
    SDL_DestroyTexture(this->fontTouch.touch4);
    SDL_DestroyTexture(this->fontTouch.touch5);
    SDL_DestroyTexture(this->fontTouch.touch6);
    SDL_DestroyTexture(this->fontTouch.touch7);
    SDL_DestroyTexture(this->fontTouch.touch8);
    SDL_DestroyTexture(this->fontTouch.touch9);
    SDL_DestroyTexture(this->fontTouch.touch10);

    SDL_DestroyTexture(this->fontText.textWindow);
    SDL_DestroyTexture(this->fontText.textName);
    SDL_DestroyTexture(this->fontText.textScore);

    SDL_FreeSurface(this->texture.surfaceackground);
    SDL_DestroyTexture(this->texture.textureackground);

    SDL_DestroyRenderer(this->renderWindow);
    SDL_DestroyWindow(this->window);
    TTF_Quit();
    SDL_Quit();
}

Input LIB::SDL2Graph::getInput()
{
    if (SDL_PollEvent(&this->event) != 0) {
        if (this->event.type == SDL_QUIT) {
            return (Input::F7);
        } else if (this->event.type == SDL_KEYDOWN) {
            switch (this->event.key.keysym.sym) {
                case SDLK_DOWN:
                    switchDown();
                    return DOWN_ARROW;
                case SDLK_UP:
                    switchUp();
                    return UP_ARROW;
                case SDLK_TAB:
                    switchTab();
                    return TAB;
                case SDLK_RETURN:
                    return ENTER;
                case SDLK_ESCAPE:
                    return (Input::F7);
                case SDLK_F1:
                    return (Input::F1);
                case SDLK_F3:
                    return (Input::F3);
                case SDLK_F2:
                    return (Input::F2);
                case SDLK_F4:
                    return (Input::F4);
                case SDLK_F5:
                    return (Input::F5);
                case SDLK_F6:
                    return (Input::F6);
                default:
                    return NO_INPUT;
            }
        }
    }
    return NO_INPUT;
}

void LIB::SDL2Graph::switchTab()
{
    if (this->status.statusTab == 0)
        this->status.statusTab = 1;
    else
        this->status.statusTab = 0;
}

void LIB::SDL2Graph::switchUp()
{
    TTF_Font* font = initFont("ressources/font/Demode.ttf", 32);

    if (this->status.statusNameGame == 2 && this->status.statusTab == 0) {
        SDL_DestroyTexture(this->fontGame.Game1);
        SDL_DestroyTexture(this->fontGame.Game2);
        SDL_Surface *surface1 = initSurface(font, "Pacman", SDL_Color{255, 0, 0, 0});
        SDL_Surface *surface2 = initSurface(font, "Snake", SDL_Color{255, 255, 255, 255});
        this->fontGame.posGame1 = initRect(650, 400, 32, 125);
        this->fontGame.posGame2 = initRect(650, 450, 32, 125);
        this->fontGame.Game1 = SDL_CreateTextureFromSurface(this->renderWindow, surface1);
        this->fontGame.Game2 = SDL_CreateTextureFromSurface(this->renderWindow, surface2);
        this->status.statusNameGame = 1;

        SDL_FreeSurface(surface1);
        SDL_FreeSurface(surface2);
        return;
    }

    if (this->status.statusNameLib == 2 && this->status.statusTab == 1) {
        SDL_DestroyTexture(this->fontLib.Lib1);
        SDL_DestroyTexture(this->fontLib.Lib2);
        SDL_DestroyTexture(this->fontLib.Lib3);

        SDL_Surface *surface1 = initSurface(font, "SFML", SDL_Color{255, 0, 0, 0});
        SDL_Surface *surface2 = initSurface(font, "SDL", SDL_Color{255, 255, 255, 255});
        SDL_Surface *surface3 = initSurface(font, "NCURSES", SDL_Color{255, 255, 255, 255});

        this->fontLib.posLib1 = initRect(1150, 400, 32, 125);
        this->fontLib.posLib2 = initRect(1150, 450, 32, 125);
        this->fontLib.posLib3 = initRect(1150, 500, 32, 125);

        this->fontLib.Lib1 = SDL_CreateTextureFromSurface(this->renderWindow, surface1);
        this->fontLib.Lib2 = SDL_CreateTextureFromSurface(this->renderWindow, surface2);
        this->fontLib.Lib3 = SDL_CreateTextureFromSurface(this->renderWindow, surface3);

        SDL_FreeSurface(surface1);
        SDL_FreeSurface(surface2);
        SDL_FreeSurface(surface3);
        this->status.statusNameLib = 1;
    } else if (this->status.statusNameLib == 3 && this->status.statusTab == 1) {
        SDL_DestroyTexture(this->fontLib.Lib1);
        SDL_DestroyTexture(this->fontLib.Lib2);
        SDL_DestroyTexture(this->fontLib.Lib3);

        SDL_Surface *surface1 = initSurface(font, "SFML", SDL_Color{255, 255, 255, 255});
        SDL_Surface *surface2 = initSurface(font, "SDL", SDL_Color{255, 0, 0, 0});
        SDL_Surface *surface3 = initSurface(font, "NCURSES", SDL_Color{255, 255, 255, 255});

        this->fontLib.posLib1 = initRect(1150, 400, 32, 125);
        this->fontLib.posLib2 = initRect(1150, 450, 32, 125);
        this->fontLib.posLib3 = initRect(1150, 500, 32, 125);

        this->fontLib.Lib1 = SDL_CreateTextureFromSurface(this->renderWindow, surface1);
        this->fontLib.Lib2 = SDL_CreateTextureFromSurface(this->renderWindow, surface2);
        this->fontLib.Lib3 = SDL_CreateTextureFromSurface(this->renderWindow, surface3);

        SDL_FreeSurface(surface1);
        SDL_FreeSurface(surface2);
        SDL_FreeSurface(surface3);
        this->status.statusNameLib = 2;
    }

    TTF_CloseFont(font);
}

void LIB::SDL2Graph::switchDown()
{
    TTF_Font* font = initFont("ressources/font/Demode.ttf", 32);

    if (this->status.statusNameGame == 1 && this->status.statusTab == 0) {
        SDL_DestroyTexture(this->fontGame.Game1);
        SDL_DestroyTexture(this->fontGame.Game2);
        SDL_Surface *surface1 = initSurface(font, "Pacman", SDL_Color{255, 255, 255, 255});
        SDL_Surface *surface2 = initSurface(font, "Snake", SDL_Color{255, 0, 0, 0});
        this->fontGame.posGame1 = initRect(650, 400, 32, 125);
        this->fontGame.posGame2 = initRect(650, 450, 32, 125);
        this->fontGame.Game1 = SDL_CreateTextureFromSurface(this->renderWindow, surface1);
        this->fontGame.Game2 = SDL_CreateTextureFromSurface(this->renderWindow, surface2);
        SDL_FreeSurface(surface1);
        SDL_FreeSurface(surface2);

        this->status.statusNameGame = 2;
        return;
    }

    if (this->status.statusNameLib == 1 && this->status.statusTab == 1) {
        SDL_DestroyTexture(this->fontLib.Lib1);
        SDL_DestroyTexture(this->fontLib.Lib2);
        SDL_DestroyTexture(this->fontLib.Lib3);

        SDL_Surface *surface1 = initSurface(font, "SFML", SDL_Color{255, 255, 255, 255});
        SDL_Surface *surface2 = initSurface(font, "SDL", SDL_Color{255, 0, 0, 0});
        SDL_Surface *surface3 = initSurface(font, "NCURSES", SDL_Color{255, 255, 255, 255});

        this->fontLib.posLib1 = initRect(1150, 400, 32, 125);
        this->fontLib.posLib2 = initRect(1150, 450, 32, 125);
        this->fontLib.posLib3 = initRect(1150, 500, 32, 125);

        this->fontLib.Lib1 = SDL_CreateTextureFromSurface(this->renderWindow, surface1);
        this->fontLib.Lib2 = SDL_CreateTextureFromSurface(this->renderWindow, surface2);
        this->fontLib.Lib3 = SDL_CreateTextureFromSurface(this->renderWindow, surface3);

        SDL_FreeSurface(surface1);
        SDL_FreeSurface(surface2);
        SDL_FreeSurface(surface3);
        this->status.statusNameLib = 2;
    } else if (this->status.statusNameLib == 2 && this->status.statusTab == 1) {
        SDL_DestroyTexture(this->fontLib.Lib1);
        SDL_DestroyTexture(this->fontLib.Lib2);
        SDL_DestroyTexture(this->fontLib.Lib3);

        SDL_Surface *surface1 = initSurface(font, "SFML", SDL_Color{255, 255, 255, 255});
        SDL_Surface *surface2 = initSurface(font, "SDL", SDL_Color{255, 255, 255, 255});
        SDL_Surface *surface3 = initSurface(font, "NCURSES", SDL_Color{255, 0, 0, 0});

        this->fontLib.posLib1 = initRect(1150, 400, 32, 125);
        this->fontLib.posLib2 = initRect(1150, 450, 32, 125);
        this->fontLib.posLib3 = initRect(1150, 500, 32, 125);

        this->fontLib.Lib1 = SDL_CreateTextureFromSurface(this->renderWindow, surface1);
        this->fontLib.Lib2 = SDL_CreateTextureFromSurface(this->renderWindow, surface2);
        this->fontLib.Lib3 = SDL_CreateTextureFromSurface(this->renderWindow, surface3);

        SDL_FreeSurface(surface1);
        SDL_FreeSurface(surface2);
        SDL_FreeSurface(surface3);
        this->status.statusNameLib = 3;
    }

    TTF_CloseFont(font);
}

void LIB::SDL2Graph::windowWin()
{

}

void LIB::SDL2Graph::windowLoose()
{

}

void LIB::SDL2Graph::playSound()
{

}

void LIB::SDL2Graph::stopSound()
{

}

int LIB::SDL2Graph::getLib() const
{
    return (this->status.statusNameLib);
}

int LIB::SDL2Graph::getGame() const
{
    return (this->status.statusNameGame);
}
