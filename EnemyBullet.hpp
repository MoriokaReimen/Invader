/*!
 * \file EnemyBullet.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief EnemyBulletクラスの宣言
 */
#pragma once
#include<GameObject.hpp>

/*!
 * \class EnemyBullet
 * \brief 弾丸クラス
 */
class EnemyBullet : public GameObject
{

public:
    EnemyBullet(const Eigen::Vector2f& pos, const Eigen::Vector2f& vel);
    void update() override;
    ~EnemyBullet() override;
    void draw(Render& render) override;
    void on_collide(std::shared_ptr<GameObject> other) override;
};
