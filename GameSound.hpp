#pragma once
#include<SDL2/SDL_mixer.h>
#include<iostream>

class GameSound
{

    GameSound(const GameSound& other) = delete;
    GameSound& operator=(const GameSound& other) = delete;
public:
    GameSound();
    ~GameSound();
};
