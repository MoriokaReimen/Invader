#pragma once
#include<SDL2/SDL_mixer.h>
#include<iostream>
#include"SoundKeep.hpp"

class GameSound
{

    GameSound(const GameSound& other) = delete;
    GameSound& operator=(const GameSound& other) = delete;
    SoundKeep sounds_;
public:
    GameSound();
    ~GameSound();
    void playSound(const SoundID& id);
};
