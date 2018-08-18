#pragma once
#include"ImageKeep.hpp"
#include"FontKeep.hpp"
#include"Window.hpp"

#include<SDL2/SDL.h>
#include<eigen3/Eigen/Eigen>
#include<string>

class Render
{
    SDL_Renderer* render_;
    ImageKeep images_;
    FontKeep fonts_;
public:
    explicit Render(Window& window);
    ~Render();
    void clear();
    void refresh();
    SDL_Renderer* get();
    void renderImage(const ImageID& id, const Eigen::Vector2f& pos);
    void renderImage(const ImageID& id, const int& width, const int& height, const Eigen::Vector2f& pos);
    void renderText(const FontID& id, const Eigen::Vector2f& pos, const std::string msg);
};
