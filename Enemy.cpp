#include<Enemy.hpp>
#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Screen.hpp>
#include<Bullet.hpp>

#include<memory>
#include<random>

Enemy::Enemy(const int& x, const int& y) :
    GameObject(x, y), generator_(), distribution_(0, 100)
{
}

void Enemy::update()
{
    const Field* field = GameSystem::getField();
    int next_x(x_), next_y(y_);
    const int next_action = distribution_(generator_) % 200;
    switch(next_action) {
    case 1:
        next_x++;
        break;
    case 2:
        next_x--;
        break;
    case 3:
        next_y++;
        break;
    case 4:
        shoot(x_, y_ + 1);
    default:
        break;
    }

    if(field->is_on_field(next_x, next_y)) {
        x_ = next_x;
        y_ = next_y;
    }

    return;
}

Enemy::~Enemy()
{}

void Enemy::draw(Screen& screen)
{
    screen.print("M", this->x_, this->y_);
    return;
}

void Enemy::shoot(const  int&x, const int& y)
{
    Field* field = GameSystem::getField();
    field->addObject(std::shared_ptr<GameObject>(new Bullet(x, y, 1)));

    return;
}
