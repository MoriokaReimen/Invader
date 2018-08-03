#include<Enemy.hpp>
#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Screen.hpp>
#include<Bullet.hpp>

#include<memory>
#include<random>

Enemy::Enemy(const int& x, const int& y) :
    GameObject(x, y, ENEMY), generator_(), distribution_(0, 100)
{
}

void Enemy::update()
{
    const Field* field = GameSystem::getField();
    int next_x(x_), next_y(y_);

    GameStatus* status = GameSystem::getStatus();
    if(this->y_ > (field->get_y() - 5))
        status->setGameOver();

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

    if(field->is_on_field(next_x, next_y) && !field->checkPosition(next_x, next_y)) {
        x_ = next_x;
        y_ = next_y;
    }

    return;
}

Enemy::~Enemy()
{}

void Enemy::draw(Screen& screen)
{
    screen.print("M", this->x_, this->y_, ENEMY_COLOR);
    return;
}

void Enemy::shoot(const  int&x, const int& y)
{
    Field* field = GameSystem::getField();
    field->addObject(std::shared_ptr<GameObject>(new Bullet(x, y+1, 1)));

    return;
}

void Enemy::kill()
{
    GameStatus* status = GameSystem::getStatus();
    GameObject::kill();
    status->addScore(30);

    return;

}
