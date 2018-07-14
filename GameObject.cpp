#include<GameObject.hpp>
#include<Screen.hpp>

GameObject::GameObject(const int& x, const int& y ) : x_(x), y_(y)
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
