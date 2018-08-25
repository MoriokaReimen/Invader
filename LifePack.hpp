/*!
 * \file LifePack.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief LifePackクラスの宣言
 */
#pragma once
#include<GameObject.hpp>

/*!
 * \class LifePack
 * \brief 弾丸クラス
 */
class LifePack : public GameObject
{

public:
    LifePack(const Eigen::Vector2f& pos, const Eigen::Vector2f& vel);
    void update() override;
    ~LifePack() override;
    void draw(Render& render) override;
    void on_collide(std::shared_ptr<GameObject> other) override;
};
