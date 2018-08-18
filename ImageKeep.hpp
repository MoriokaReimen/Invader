#pragma once
#include"Render.hpp"

#include<SDL2/SDL.h>
#include<map>
#include<string>

enum ImageID
{
    PLAYER_IMAGE,
    ENEMY_IMAGE,
    BULLET_IMAGE,
    BOMB_IMAGE
};

class Render;

class ImageKeep
{
    SDL_Renderer* render_;
    std::map<ImageID, SDL_Texture*> images_;

    ImageKeep(const ImageKeep& other) = delete;
    ImageKeep& operator=(const ImageKeep& other) = delete;

public:
    ImageKeep();
    void init(Render& render);
    ~ImageKeep();

    bool registerImage(const ImageID& id, const std::string& path);
    SDL_Texture* getImage(const ImageID& id);
};

extern ImageKeep image;
