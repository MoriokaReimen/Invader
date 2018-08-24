/*!
 * \file Gunner.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Gunnerクラスの実装
 */
#pragma once
#include<GameObject.hpp>
#include<GameSystem.hpp>

#include<random>

/*!
 * \class Gunner
 * \brief 敵クラス
 */
class Gunner : public GameObject
{
    std::random_device generator_; //!< 乱数ジェネレータ
    std::uniform_int_distribution<int> distribution_; //!< 一様分布

public:
    Gunner(const Eigen::Vector2f& pos);
    void update() override;
    ~Gunner() override;
    void draw(Render& render) override;
    void shoot(const Eigen::Vector2f& pos);
    void on_collide(std::shared_ptr<GameObject> other) override;
};
