#pragma once

#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Screen.hpp>

class Player : public GameObject
{
public:
    Player(const int& x, const int& y);
    void update();
    ~Player();
    void draw(Screen& screen);
    void shoot(const int& x, const int& y);
};
