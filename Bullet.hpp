/*!
 * \file Bullet.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Bulletクラスの宣言
 */
#pragma once
#include<GameObject.hpp>

/*!
 * \class Bullet
 * \brief 弾丸クラス
 */
class Bullet : public GameObject
{
    const  int direction_; //!< 進行方向

public:
    Bullet(const int& x, const int& y, const int& direction);
    void update();
    ~Bullet();
    void draw(Screen& screen);
};
