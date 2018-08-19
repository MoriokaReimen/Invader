#include"FontKeep.hpp"
#include"Render.hpp"

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string>
#include<map>

FontKeep::FontKeep()
{
    TTF_Init();
    return;
}

void FontKeep::init(Render& render)
{
    render_ = render.get();
    return;
}

FontKeep::~FontKeep()
{
    for(auto elem : fonts_) {
        TTF_CloseFont(elem.second);
    }

    TTF_Quit();

    return;
}

bool FontKeep::registerFont(const FontID& id, const std::string& path)
{
    FontID temp(id);
    TTF_Font* font = TTF_OpenFont(path.c_str(), 24);
    if(font != nullptr) {
        fonts_.emplace(temp, font);
        return true;
    } else {
        std::cout << "Font Load Error: " << path << std::endl;
    }

    return false;
}

TTF_Font* FontKeep::getFont(const FontID& id)
{
    TTF_Font* ret(nullptr);
    if(fonts_.count(id)) {
        ret = fonts_.at(id);
    }
    return ret;
}

