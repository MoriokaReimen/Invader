/*!
 * \file Bullet.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Bulletクラスの実装
 */
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
    x = this->x_;
    y = this->y_;
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

void GameObject::kill()
{
    this->is_alive_ = false;

    return;
}
