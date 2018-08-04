/*!
 * \file GameObject.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief GameObjectクラスの宣言
 */
#pragma once
#include<Screen.hpp>

enum OBJECT_TYPE {
    PLAYER,
    ENEMY,
    BULLET
};

/*!
 * \class GameObject
 * \brief 画面上で動くオブジェクトの抽象基底クラス
 */
class GameObject
{
protected:
    double x_; //!< X座標
    double y_; //!< Y座標
    bool is_alive_; //!< 生死のフラグ
    OBJECT_TYPE type_; //!< オブジェクトのタイプ;

public:
    GameObject(const int& x, const int& y, const OBJECT_TYPE& type);
    virtual ~GameObject() = 0;
    virtual void update() = 0;
    virtual void draw(Screen& screen) = 0;
    virtual void kill();

    void getPosition(int& x, int& y);
    bool isAlive();
    OBJECT_TYPE getType();
};
