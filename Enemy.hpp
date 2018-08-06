/*!
 * \file Enemy.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Enemyクラスの実装
 */
#pragma once
#include<GameObject.hpp>
#include<GameSystem.hpp>

#include<random>

/*!
 * \class Enemy
 * \brief 敵クラス
 */
class Enemy : public GameObject
{
    std::random_device generator_; //!< 乱数ジェネレータ
    std::uniform_int_distribution<int> distribution_; //!< 一様分布

public:
    Enemy(const Eigen::Vector2f& pos);
    void update() override;
    ~Enemy() override;
    void draw(Screen& screen) override;
    void shoot(const Eigen::Vector2f& pos);
    void on_collide(std::shared_ptr<GameObject> other) override;
};
