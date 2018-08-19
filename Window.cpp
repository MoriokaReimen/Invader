#include"Window.hpp"
#include <string>
#include <iostream>
#include <SDL2/SDL.h>

Window::Window() : SCREEN_WIDTH(600), SCREEN_HEIGHT(1000)
{
    /*!SDLの初期化*/
    int err = SDL_Init(SDL_INIT_VIDEO);
    if(err != 0)
    {
        logSDLError(std::cout, "SDL_Init");
    }

    /*!Windowの初期化*/
    window_ = SDL_CreateWindow("Invader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window_ == nullptr) {
        logSDLError(std::cout, "CreateWindow");
        SDL_Quit();
    }

    return;
}

Window::~Window()
{
    SDL_DestroyWindow(window_);
    SDL_Quit();

    return;
}

SDL_Window* Window::get()
{
    return this->window_;
}

void logSDLError(std::ostream &os, const std::string &msg)
{
    os << msg << " error: " << SDL_GetError() << std::endl;

    return;
}
