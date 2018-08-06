/*!
 * \file Player.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Playerクラスの宣言
 */
#pragma once

#include<GameObject.hpp>

/*!
 * \class Player
 * \brief プレイヤーのクラス
 */
class Player : public GameObject
{
public:
    Player(const Eigen::Vector2f& pos);
    void update() override;
    ~Player() override;
    void draw(Screen& screen) override;
    void shoot(const Eigen::Vector2f& pos);
    void on_collide(std::shared_ptr<GameObject> other) override;
};
