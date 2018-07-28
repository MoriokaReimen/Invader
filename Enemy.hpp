#pragma once
#include<random>
#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Screen.hpp>


class Enemy : public GameObject
{
    std::random_device generator_;
    std::uniform_int_distribution<int> distribution_;

public:
    Enemy(const int& x, const int& y);
    void update();
    ~Enemy();
    void draw(Screen& screen);
    void shoot(const int&x, const int& y);

};
