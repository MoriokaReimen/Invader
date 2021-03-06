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
    images_.registerImage(GUNNER_IMAGE, "./asset/Gunner.png");
    images_.registerImage(BOMB_IMAGE, "./asset/Bomb.png");
    images_.registerImage(LIFE_PACK_IMAGE, "./asset/LifePack.png");
    images_.registerImage(MISSILE_IMAGE, "./asset/Missile.png");

    images_.registerImage(BACK_GROUND_IMAGE, "./asset/Space.jpg");

    fonts_.init(*this);
    fonts_.registerFont(NORMAL_FONT, "./asset/Roboto-Regular.ttf");
    fonts_.registerFont(BOLD_FONT, "./asset/Roboto-Bold.ttf");

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
    this->renderBackGround();
    GameField* field = GameSystem::getField();
    for(auto it = field->begin(); it != field->end(); ++it) {
        (*it)->draw(*this);
    }
    this->printHP();
    this->printScore();
    this->printTPF();
    this->printObjectCount();
    this->printGameOver();
    this->printPlayerWin();

    this->refresh();

    return;
}

void Render::printHP()
{
    GameField* field = GameSystem::getField();
    int hp(0);
    for(auto it = field->begin(); it != field->end(); ++it) {
        if((*it)->getType() == PLAYER) {
            hp = (*it)->getHP();
        }
    }

    char buff[125];
    sprintf(buff, "HP:%d%%", hp);
    std::string msg(buff);
    this->renderText(NORMAL_FONT, Eigen::Vector2f(0, 0), msg);

    return;
}

void Render::printScore()
{
    GameStatus* status = GameSystem::getStatus();
    int score = status->getScore();

    char buff[125];
    sprintf(buff, "Score:%4d", score);
    std::string msg(buff);
    this->renderText(NORMAL_FONT, Eigen::Vector2f(460, 0), msg);

    return;
}

void Render::printGameOver()
{
    GameStatus* status = GameSystem::getStatus();
    if(status->isGameOver()) {
        std::string msg("GAME OVER");
        this->renderText(BOLD_FONT, Eigen::Vector2f(250, 500), msg);
    }

    return;
}

void Render::printPlayerWin()
{
    GameStatus* status = GameSystem::getStatus();
    if(status->isPlayerWin()) {
        std::string msg("YOU WIN");
        this->renderText(BOLD_FONT, Eigen::Vector2f(250, 500), msg);
    }

    return;
}

void Render::renderBackGround()
{
    this->renderImage(BACK_GROUND_IMAGE, 600, 1000, Eigen::Vector2f(0.0, 0.0));

    return;
}

void Render::printTPF()
{
    GameTime* time = GameSystem::getTime();
    int tpf = time->getTPF();

    char buff[125];
    sprintf(buff, "TPF:%4d[ms]", tpf);
    std::string msg(buff);
    this->renderText(NORMAL_FONT, Eigen::Vector2f(460, 30), msg);

    return;
}

void Render::printObjectCount()
{
    GameField* field = GameSystem::getField();
    char buff[125];
    sprintf(buff, "Object:%4d", field->countObjects());
    std::string msg(buff);
    this->renderText(NORMAL_FONT, Eigen::Vector2f(460, 60), msg);
    return;
}
