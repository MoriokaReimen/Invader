#include"Render.hpp"
#include"ImageKeep.hpp"

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<string>
#include<map>

ImageKeep::ImageKeep()
{
    return;
}

void ImageKeep::init(Render& render)
{
    render_ = render.get();
    return;
}

ImageKeep::~ImageKeep()
{
    for(auto elem : images_) {
        SDL_DestroyTexture(elem.second);
    }

    return;
}

bool ImageKeep::registerImage(const ImageID& id, const std::string& path)
{
    ImageID temp(id);
    SDL_Texture* image = IMG_LoadTexture(render_, path.c_str());
    if(image != nullptr) {
        images_.emplace(temp, image);
        return true;
    } else {
        std::cout << "Image Load Error: " << path << std::endl;
    }

    return false;
}

SDL_Texture* ImageKeep::getImage(const ImageID& id)
{
    SDL_Texture* ret(nullptr);
    if(images_.count(id)) {
        ret = images_.at(id);
    }
    return ret;
}

