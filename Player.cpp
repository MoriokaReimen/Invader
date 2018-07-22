#include<Player.hpp>
#include<GameObject.hpp>
#include<GameSystem.hpp>

void Player::update()
{
    InputKeep* input = GameSystem::get_InputKeep();
    const char ch = input->pop();
    switch(ch) {
    case 'k':
        this->y_--;
        break;
    case 'h':
        this->x_--;
        break;
    case 'j':
        this->y_++;
        break;
    case 'l':
        this->x_++;
        break;
    default:
        break;
    }

}

Player::~Player()
{}

void Player::draw()
{
    return;
}
