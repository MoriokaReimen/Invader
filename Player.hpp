#pragma once

#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Screen.hpp>

class Player : public GameObject
{
public:
    void update();
    ~Player();
    void draw();
};
