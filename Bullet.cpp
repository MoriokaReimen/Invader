#include<Bullet.hpp>
#include<GameObject.hpp>
#include<GameSystem.hpp>

Bullet::Bullet(const int& x, const int& y, const int& direction) : GameObject(x, y, BULLET), direction_(direction)
{
}

void Bullet::update()
{
    Field* field = GameSystem::getField();
    this->y_ += direction_ * 0.1;

    if(!field->is_on_field(this->x_, this->y_)) {
        this->is_alive_ = false;
    }

    return;
}

Bullet::~Bullet()
{}

void Bullet::draw(Screen& screen)
{
    screen.print("|", this->x_, this->y_);

    return;
}

