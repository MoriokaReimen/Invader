#pragma once
#include<GameObject.hpp>
#include<Screen.hpp>


class Bullet : public GameObject
{
    const  int direction_;

public:
    Bullet(const int& x, const int& y, const int& direction);
    void update();
    ~Bullet();
    void draw(Screen& screen);
};
