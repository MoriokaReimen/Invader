#include"Render.hpp"
#include"ImageKeep.hpp"
#include"GameSystem.hpp"

#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<eigen3/Eigen/Eigen>

Render::Render(Window& window)
{
    render_ = SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (render_ == nullptr) {
        logSDLError(std::cout, "CreateRenderer");
    }

    images_.init(*this);
    images_.registerImage(PLAYER_IMAGE, "./asset/Player.png");
    images_.registerImage(BULLET_IMAGE, "./asset/Bullet.png");
    images_.registerImage(ENEMY_IMAGE, "./asset/Enemy.png");
    images_.registerImage(BOMB_IMAGE, "./asset/Bomb.png");

    fonts_.init(*this);
    fonts_.registerFont(NORMAL_FONT, "./asset/Roboto-Regular.ttf");
    fonts_.registerFont(NORMAL_FONT, "./asset/Roboto-Bold.ttf");

    return;
}

Render::~Render()
{
    SDL_DestroyRenderer(render_);

    return;
}

void Render::clear()
{
    SDL_RenderClear(render_);
}

void Render::refresh()
{
    SDL_RenderPresent(render_);
}

SDL_Renderer* Render::get()
{
    return this->render_;
}

void Render::renderImage(const ImageID& id, const Eigen::Vector2f& pos)
{
    int width, height;
    auto tex = images_.getImage(id);
    SDL_QueryTexture(tex, NULL, NULL, &width, &height);
    renderImage(id, width, height, pos);
}

void Render::renderImage(const ImageID& id, const int& width, const int& height, const Eigen::Vector2f& pos)
{
    auto tex = images_.getImage(id);
    SDL_Rect dst;
    dst.x = static_cast<int>(pos[0]);
    dst.y = static_cast<int>(pos[1]);
    dst.w = width;
    dst.h = height;
    SDL_RenderCopy(render_, tex, NULL, &dst);

}

void Render::renderText(const FontID& id, const Eigen::Vector2f& pos, const std::string msg)
{
    auto font = fonts_.getFont(id);
    SDL_Color white = {255, 255, 255};
    auto surface = TTF_RenderUTF8_Solid(font, msg.c_str(), white);
    auto texture = SDL_CreateTextureFromSurface(render_, surface);
    SDL_Rect dst;
    dst.x = static_cast<int>(pos[0]);
    dst.y = static_cast<int>(pos[1]);
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);

    SDL_RenderCopy(render_, texture, NULL, &dst);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Render::update()
{
    this->clear();
    GameField* field = GameSystem::getField();
    for(auto it = field->begin(); it != field->end(); ++it)
    {
        (*it)->draw(*this);
    }

    this->refresh();

    return;
}
