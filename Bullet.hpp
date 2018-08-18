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

public:
    Bullet(const Eigen::Vector2f& pos, const Eigen::Vector2f& vel);
    void update() override;
    ~Bullet() override;
    void draw(Render& render) override;
    void on_collide(std::shared_ptr<GameObject> other) override;
};
