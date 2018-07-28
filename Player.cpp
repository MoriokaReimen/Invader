#include<Player.hpp>
#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Screen.hpp>
#include<Bullet.hpp>

#include<memory>

Player::Player(const int& x, const int& y) : GameObject(x, y, PLAYER)
{
}

void Player::update()
{
    InputKeep* input = GameSystem::getInputKeep();
    Field* field = GameSystem::getField();
    const KEY_INPUT key = input->get();
    int next_x(x_), next_y(y_);

    switch(key) {
    case UP:
        next_y--;
        break;
    case DOWN:
        next_y++;
        break;
    case RIGHT:
        next_x--;
        break;
    case LEFT:
        next_x++;
        break;
    case SHOOT:
        this->shoot(x_, y_);
        break;
    default:
        break;
    }

    if(field->is_on_field(next_x, next_y)) {
        x_ = next_x;
        y_ = next_y;
    }

    return;
}

Player::~Player()
{}

void Player::draw(Screen& screen)
{
    screen.print("@", this->x_, this->y_);
    return;
}

void Player::shoot(const  int&x, const int& y)
{
    Field* field = GameSystem::getField();
    field->addObject(std::shared_ptr<GameObject>(new Bullet(x, y - 1, -1)));

    return;
}
