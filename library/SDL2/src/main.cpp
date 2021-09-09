/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-arcade-mathis.fayet
** File description:
** main
*/

#include "../include/OneForAll.hpp"

/*
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class MainComponent
{
 public:
    void init();
    ~MainComponent();

 private:
    SDL_Window *window;
    SDL_Renderer* renderer;
};

MainComponent::~MainComponent()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void MainComponent::init() {
    SDL_Init(SDL_INIT_EVERYTHING);

    int screenWidth = 400;
    int screenHeight = 300;

    window = SDL_CreateWindow("My Game Window", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    cout << screenWidth << " " << screenHeight << endl;

    if(window == nullptr) {
        cout << "Error could not create window" << SDL_GetError() << endl;
    }

    //change the background color
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Clear the entire screen to our selected color.
    SDL_RenderClear(renderer);

    // Up until now everything was drawn behind the scenes.
    // This will show the new, red contents of the window.
    SDL_RenderPresent(renderer);


    SDL_Delay(5000);

}


int main(int argc, const char * argv[]) {

    MainComponent mainComponent;
    mainComponent.init();

    char myVar;

    cout << "Enter any key to quit...";
    cin >> myVar;

    SDL_Quit();
    return 0;
}
*/

int main()
{
    /*
   if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Window* pWindow{ nullptr };
    SDL_Renderer* pRenderer{ nullptr };
    pWindow = SDL_CreateWindow("SDL Programme", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);   
    if (pWindow == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (pRenderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    SDL_DestroyRenderer(pRenderer);     SDL_DestroyWindow(pWindow);
    SDL_Quit();
    return EXIT_SUCCESS;
    *
    */

    LIB::SDL2Graph sdl2;

    sdl2.initStart();

    while (sdl2.getExit() != 1) {
        auto a = sdl2.getInput();
        sdl2.drawMainMenu();
    }
    sdl2.destroyWindow();
}
