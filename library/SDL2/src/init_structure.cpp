/*
** EPITECH PROJECT, 2021
** init_structure.cpp
** File description:
** produce
*/

#include "../include/OneForAll.hpp"

void LIB::SDL2Graph::initStart()
{
    this->exit = 0;
    this->status.statusTab = 0;
    this->status.statusNameLib = 1;
    this->status.statusNameGame = 1;
    this->name = "PAUL";
    this->score = 0;

    IMG_Init(IMG_INIT_JPG);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return;
    }

    if (TTF_Init() < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return;
    }

    this->window = SDL_CreateWindow("Arcade - SDL INTERFACE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);

    if (this->window == nullptr) {
            std::cerr << "SDL window creation failed." << std::endl;
            this->exit = 84;
            return;
    }

    initRender();
    initTexture();
    initFontTextWindow();
    initFontTextName();
    initFontTextScore();

    initGame();
    initLib();

    initFontTouch();

    if (this->exit == 84) {
        std::cout << "pas cool" << std::endl;
    }
}

void LIB::SDL2Graph::initTexture()
{
    this->texture.surfaceackground = IMG_Load("ressources/picture/BackMenu.jpg");
    this->texture.textureackground = SDL_CreateTextureFromSurface(this->renderWindow, this->texture.surfaceackground);
}

void LIB::SDL2Graph::initRender()
{
    this->renderWindow = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    if (this->renderWindow == nullptr) {
        std::cerr << "SDL renderer creation failed." << std::endl;
        this->exit = 84;
    }
}

TTF_Font *LIB::SDL2Graph::initFont(const std::string &name, int num)
{
    TTF_Font* font = TTF_OpenFont(name.c_str(), num);

    if (font == nullptr) {
        std::cerr << "SDL font creation failed." << std::endl;
        this->exit = 84;
        return (nullptr);
    }
    return (font);
}

SDL_Surface *LIB::SDL2Graph::initSurface(TTF_Font *Font, const std::string &name, const SDL_Color &color)
{
    SDL_Surface* text = TTF_RenderText_Solid(Font, name.c_str(), color);

    if (text == nullptr) {
        std::cerr << "SDL Surface creation failed." << std::endl;
        this->exit = 84;
        return (nullptr);
    }
    return (text);
}

SDL_Rect LIB::SDL2Graph::initRect(int x, int y, int h, int w)
{
    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.h = h;
    rect.w = w;

    return (rect);
}

void LIB::SDL2Graph::initFontTextWindow()
{
    TTF_Font* font = initFont("ressources/font/Demode.ttf", 32);
    SDL_Surface *surface = initSurface(font, "Arcade - SDL2 interface", SDL_Color{255, 255, 255, 255});

    this->fontText.posWindow = initRect(650, 63, 100, 700);

    this->fontText.textWindow = SDL_CreateTextureFromSurface(this->renderWindow, surface);

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}

void LIB::SDL2Graph::initFontTextName()
{
    TTF_Font* font = initFont("ressources/font/Demode.ttf", 32);
    SDL_Surface *surface = initSurface(font, "name = " + this->name, SDL_Color{255, 255, 255, 255});

    this->fontText.posName = initRect(50, 50, 32, 125);

    this->fontText.textName = SDL_CreateTextureFromSurface(this->renderWindow, surface);

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}

void LIB::SDL2Graph::initFontTouch()
{
    TTF_Font* font = initFont("ressources/font/Demode.ttf", 32);
    SDL_Surface *surface1 = initSurface(font, "Previous graphics library: F1", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface2 = initSurface(font, "Next graphics library: F2", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface3 = initSurface(font, "Previous game: F3", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface4 = initSurface(font, "Next game: F4", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface5 = initSurface(font, "Restart the game: F5", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface6 = initSurface(font, "Go back to the menu: F6", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface7 = initSurface(font, "Exit: F7", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface8 = initSurface(font, "Switch Game/Lib: TAB", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface9 = initSurface(font, "Up: UP", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface10 = initSurface(font, "Down: Down", SDL_Color{255, 255, 255, 255});

    this->fontTouch.posTouch1 = initRect(25, 915, 32, 300);

    this->fontTouch.posTouch2 = initRect(25, 950, 32, 300);

    this->fontTouch.posTouch3 = initRect(450, 915, 32, 250);

    this->fontTouch.posTouch4 = initRect(450, 950, 32, 250);

    this->fontTouch.posTouch5 = initRect(725, 915, 32, 250);

    this->fontTouch.posTouch6 = initRect(725, 950, 32, 250);

    this->fontTouch.posTouch7 = initRect(1100, 915, 32, 150);

    this->fontTouch.posTouch8 = initRect(1100, 950, 32, 250);

    this->fontTouch.posTouch9 = initRect(1500, 915, 32, 125);
    this->fontTouch.posTouch10 = initRect(1500, 950, 32, 125);

    this->fontTouch.touch1 = SDL_CreateTextureFromSurface(this->renderWindow, surface1);
    this->fontTouch.touch2 = SDL_CreateTextureFromSurface(this->renderWindow, surface2);
    this->fontTouch.touch3 = SDL_CreateTextureFromSurface(this->renderWindow, surface3);
    this->fontTouch.touch4 = SDL_CreateTextureFromSurface(this->renderWindow, surface4);
    this->fontTouch.touch5 = SDL_CreateTextureFromSurface(this->renderWindow, surface5);
    this->fontTouch.touch6 = SDL_CreateTextureFromSurface(this->renderWindow, surface6);
    this->fontTouch.touch7 = SDL_CreateTextureFromSurface(this->renderWindow, surface7);
    this->fontTouch.touch8 = SDL_CreateTextureFromSurface(this->renderWindow, surface8);
    this->fontTouch.touch9 = SDL_CreateTextureFromSurface(this->renderWindow, surface9);
    this->fontTouch.touch10 = SDL_CreateTextureFromSurface(this->renderWindow, surface10);

    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(surface3);
    SDL_FreeSurface(surface4);
    SDL_FreeSurface(surface5);
    SDL_FreeSurface(surface6);
    SDL_FreeSurface(surface7);
    SDL_FreeSurface(surface8);
    SDL_FreeSurface(surface9);
    SDL_FreeSurface(surface10);

    TTF_CloseFont(font);
}

void LIB::SDL2Graph::initFontGame()
{
    TTF_Font* font = initFont("ressources/font/Demode.ttf", 32);
    SDL_Surface *surface = initSurface(font, "Game", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface1 = initSurface(font, "Pacman", SDL_Color{255, 0, 0, 0});
    SDL_Surface *surface2 = initSurface(font, "Snake", SDL_Color{255, 255, 255, 255});

    this->fontGame.posGame = initRect(650, 350, 32, 125);
    this->fontGame.posGame1 = initRect(650, 400, 32, 125);
    this->fontGame.posGame2 = initRect(650, 450, 32, 125);

    this->fontGame.Game = SDL_CreateTextureFromSurface(this->renderWindow, surface);
    this->fontGame.Game1 = SDL_CreateTextureFromSurface(this->renderWindow, surface1);
    this->fontGame.Game2 = SDL_CreateTextureFromSurface(this->renderWindow, surface2);

    SDL_FreeSurface(surface);
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);

    TTF_CloseFont(font);
}

void LIB::SDL2Graph::initHyphenGame()
{
    TTF_Font* font = initFont("ressources/font/Demode.ttf", 32);
    SDL_Surface *surface = initSurface(font, "- ", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface1 = initSurface(font, "- ", SDL_Color{255, 255, 255, 255});

    this->fontGame.posHyphen1 = initRect(600, 400, 32, 50);
    this->fontGame.posHyphen2 = initRect(600, 450, 32, 50);

    this->fontGame.Hyphen1 = SDL_CreateTextureFromSurface(this->renderWindow, surface);
    this->fontGame.Hyphen2 = SDL_CreateTextureFromSurface(this->renderWindow, surface1);

    SDL_FreeSurface(surface);
    SDL_FreeSurface(surface1);

    TTF_CloseFont(font);
}

void LIB::SDL2Graph::initFontLib()
{
    TTF_Font* font = initFont("ressources/font/Demode.ttf", 32);
    SDL_Surface *surface = initSurface(font, "LIB", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface1 = initSurface(font, "SFML", SDL_Color{255, 0, 0, 0});
    SDL_Surface *surface2 = initSurface(font, "SDL", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface3 = initSurface(font, "NCURSES", SDL_Color{255, 255, 255, 255});

    this->fontLib.posLib = initRect(1150, 350, 32, 125);
    this->fontLib.posLib1 = initRect(1150, 400, 32, 125);
    this->fontLib.posLib2 = initRect(1150, 450, 32, 125);
    this->fontLib.posLib3 = initRect(1150, 500, 32, 125);

    this->fontLib.Lib = SDL_CreateTextureFromSurface(this->renderWindow, surface);
    this->fontLib.Lib1 = SDL_CreateTextureFromSurface(this->renderWindow, surface1);
    this->fontLib.Lib2 = SDL_CreateTextureFromSurface(this->renderWindow, surface2);
    this->fontLib.Lib3 = SDL_CreateTextureFromSurface(this->renderWindow, surface3);

    SDL_FreeSurface(surface);
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(surface3);

    TTF_CloseFont(font);
}

void LIB::SDL2Graph::initHyphenLib()
{
    TTF_Font* font = initFont("ressources/font/Demode.ttf", 32);
    SDL_Surface *surface = initSurface(font, "- ", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface1 = initSurface(font, "- ", SDL_Color{255, 255, 255, 255});
    SDL_Surface *surface2 = initSurface(font, "- ", SDL_Color{255, 255, 255, 255});

    this->fontLib.posHyphen1 = initRect(1100, 400, 32, 50);
    this->fontLib.posHyphen2 = initRect(1100, 450, 32, 50);
    this->fontLib.posHyphen3 = initRect(1100, 500, 32, 50);

    this->fontLib.Hyphen1 = SDL_CreateTextureFromSurface(this->renderWindow, surface);
    this->fontLib.Hyphen2 = SDL_CreateTextureFromSurface(this->renderWindow, surface1);
    this->fontLib.Hyphen3 = SDL_CreateTextureFromSurface(this->renderWindow, surface2);

    SDL_FreeSurface(surface);
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);

    TTF_CloseFont(font);
}

void LIB::SDL2Graph::initGame()
{
    initFontGame();
    initHyphenGame();
}

void LIB::SDL2Graph::initLib()
{
    initFontLib();
    initHyphenLib();
}

void LIB::SDL2Graph::initFontTextScore()
{
    TTF_Font* font = initFont("ressources/font/Demode.ttf", 32);
    SDL_Surface *surface = initSurface(font, "Score = " + std::to_string(this->score), SDL_Color{255, 255, 255, 255});

    this->fontText.posScore = initRect(50, 125, 32, 125);

    this->fontText.textScore = SDL_CreateTextureFromSurface(this->renderWindow, surface);

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}
