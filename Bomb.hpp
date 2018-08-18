/*!
 * \file Bomb.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Bombクラスの宣言
 */
#pragma once
#include<GameObject.hpp>

/*!
 * \class Bomb
 * \brief 弾丸クラス
 */
class Bomb : public GameObject
{

public:
    Bomb(const Eigen::Vector2f& pos, const Eigen::Vector2f& vel);
    void update() override;
    ~Bomb() override;
    void draw(Render& render) override;
    void on_collide(std::shared_ptr<GameObject> other) override;
};
