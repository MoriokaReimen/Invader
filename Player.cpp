#include<Player.hpp>
#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Screen.hpp>

Player::Player(const int& x, const int& y) : GameObject(x, y)
{
}
void Player::update()
{
    InputKeep* input = GameSystem::getInputKeep();
    const KEY_INPUT key = input->get();
    switch(key) {
    case UP:
        this->y_--;
        break;
    case DOWN:
        this->y_++;
        break;
    case RIGHT:
        this->x_--;
        break;
    case LEFT:
        this->x_++;
        break;
    default:
        break;
    }

}

Player::~Player()
{}

void Player::draw(Screen& screen)
{
    screen.print("@", this->x_, this->y_);
    return;
}
