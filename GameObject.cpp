#include<GameObject.hpp>

GameObject::GameObject(const int& x, const int& y, const OBJECT_TYPE& type) :
    x_(x), y_(y), is_alive_(true), type_(type)
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

OBJECT_TYPE GameObject::getType()
{
    return this->type_;
}
