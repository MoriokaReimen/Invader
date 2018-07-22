#include<GameObject.hpp>

GameObject::GameObject() : x_(0), y_(0), is_alive_(true)
{
    return;
}

GameObject::~GameObject()
{
    return;
}

void GameObject::getPosition(int& x, int& y)
{
    this->x_ = x;
    this->y_ = y;
    return;
}

bool GameObject::isAlive()
{
    return is_alive_;
}
