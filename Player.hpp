/*!
 * \file Player.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Playerクラスの宣言
 */
#pragma once

#include<GameObject.hpp>
#include<Screen.hpp>

/*!
 * \class Player
 * \brief プレイヤーのクラス
 */
class Player : public GameObject
{
public:
    Player(const int& x, const int& y);
    void update();
    ~Player();
    void draw(Screen& screen);
    void shoot(const int& x, const int& y);
    void kill();
};
