/*!
 * \file GameObject.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief GameObjectクラスの宣言
 */
#pragma once
#include"Render.hpp"
#include<eigen3/Eigen/Eigen>

#include<memory>

enum OBJECT_TYPE {
    PLAYER,
    ENEMY,
    BULLET,
    ENEMY_BULLET,
    LIFE_PACK,
    MISSILE
};

/*!
 * \class GameObject
 * \brief 画面上で動くオブジェクトの抽象基底クラス
 */
class GameObject
{
protected:
    int hp_; //!< HP
    Eigen::Vector2f pos_; //!< 位置
    Eigen::Vector2f vel_; //!< 速度
    OBJECT_TYPE type_; //!< オブジェクトのタイプ;

public:
    GameObject(const int& hp, const Eigen::Vector2f& pos, const Eigen::Vector2f& vel, const OBJECT_TYPE& type);
    virtual ~GameObject() = 0;
    virtual void update() = 0;
    virtual void draw(Render& screen) = 0;
    virtual void on_collide(std::shared_ptr<GameObject> other) = 0;

    Eigen::Vector2f getPosition() const;
    bool isAlive() const;
    OBJECT_TYPE getType() const;
    int getHP() const;
};
