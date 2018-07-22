#include<Player.hpp>
#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Screen.hpp>

void Player::update()
{
    InputKeep* input = GameSystem::get_InputKeep();
    const KEY_INPUT key = input->pop();
    switch(key) {
    case UP:
        this->y_--;
        break;
    case DOWN:
        this->x_--;
        break;
    case RIGHT:
        this->y_++;
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
