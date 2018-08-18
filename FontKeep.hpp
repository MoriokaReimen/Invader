#pragma once

#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL.h>
#include<map>
#include<string>

enum FontID
{
    NORMAL_FONT,
    BOLD_FONT
};

class Render;

class FontKeep
{
    SDL_Renderer* render_;
    std::map<FontID, TTF_Font*> fonts_;

    FontKeep(const FontKeep& other) = delete;
    FontKeep& operator=(const FontKeep& other) = delete;

public:
    FontKeep();
    void init(Render& render);
    ~FontKeep();

    bool registerFont(const FontID& id, const std::string& path);
    TTF_Font* getFont(const FontID& id);
};

