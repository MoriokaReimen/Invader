/*!
 * \file Missile.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Missileクラスの宣言
 */
#pragma once
#include<GameObject.hpp>

/*!
 * \class Missile
 * \brief 弾丸クラス
 */
class Missile : public GameObject
{

    void explode();
    void trackPlayer();
public:
    Missile(const Eigen::Vector2f& pos, const Eigen::Vector2f& vel);
    void update() override;
    ~Missile() override;
    void draw(Render& render) override;
    void on_collide(std::shared_ptr<GameObject> other) override;
};
