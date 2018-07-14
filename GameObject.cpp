#include<GameObject.hpp>
#include<Screen.hpp>

GameObject::GameObject(const int& x, const int& y )
    : x_(x), y_(y), is_alive_(true)
{
    return;
}

GameObject::~GameObject()
{
    return;
}

void GameObject::draw(Screen& screen)
{

}

OBJECT_TYPE GameObject::getType()
{
    return this->type_;

}

void GameObject::getPosition(int& x, int& y)
{
    x = this->x_;
    y = this->y_;

    return;
}

bool GameObject::isAlive()
{
    return this->is_alive_;

}

