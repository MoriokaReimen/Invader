#pragma once
#include <string>
#include <iostream>
#include <SDL2/SDL.h>

void logSDLError(std::ostream &os, const std::string &msg);

class Window
{
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    SDL_Window* window_;
    Window(const Window& other) = delete;
    Window& operator=(const Window& other) = delete;
public:
    Window();
    ~Window();
    SDL_Window* get();

};
