/*!
 * \file Bomb.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Bombクラスの実装
 */
#include<Bomb.hpp>

#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Bullet.hpp>
#include<eigen3/Eigen/Eigen>
#include<memory>

/*!
 * @brief Bombクラスのコンストラクタ
 * @param[in] pos 位置
 * @param[in] vel 速度
 */
Bomb::Bomb(const Eigen::Vector2f& pos, const Eigen::Vector2f& vel) : GameObject(10, pos, vel, BULLET)
{
}

/*!
 * @brief 弾の状態の更新
 */
void Bomb::update()
{
    /*!位置を更新*/
    pos_ += vel_;

    /*!フィールド外に出たら消滅する*/
    GameField* field = GameSystem::getField();
    if(!field->is_on_field(pos_)) {
        this->hp_ = 0;
    }

    return;
}

/*!
 * @brief Bombクラスのデストラクタ
 */
Bomb::~Bomb()
{}

/*!
 * @brief 弾を描画する
 * @param[in,out] screen 描画するスクリーンのクラス
 */
void Bomb::draw(Render& render)
{
    render.renderImage(BOMB_IMAGE, pos_);

    return;
}

void Bomb::on_collide(std::shared_ptr<GameObject> other)
{
    Eigen::Vector2f bullet_pos(pos_);
    Eigen::Vector2f bullet_vel(0.0, -0.2);
    GameField* field = GameSystem::getField();
    if(other->getType() != BULLET)
    {
        this->hp_ = 0;
        field->addObject(std::shared_ptr<GameObject>(new Bullet(Eigen::Vector2f(pos_[0] + 1, pos_[1]), Eigen::Vector2f(0.2, 0.0))));
        field->addObject(std::shared_ptr<GameObject>(new Bullet(Eigen::Vector2f(pos_[0] + 1, pos_[1]+1), Eigen::Vector2f(0.2, 0.2))));
        field->addObject(std::shared_ptr<GameObject>(new Bullet(Eigen::Vector2f(pos_[0], pos_[1]+1), Eigen::Vector2f(0.0, 0.2))));
        field->addObject(std::shared_ptr<GameObject>(new Bullet(Eigen::Vector2f(pos_[0] + 1, pos_[1]-1), Eigen::Vector2f(0.2, -0.2))));
        field->addObject(std::shared_ptr<GameObject>(new Bullet(Eigen::Vector2f(pos_[0] - 1, pos_[1]), Eigen::Vector2f(-0.2, 0.0))));
        field->addObject(std::shared_ptr<GameObject>(new Bullet(Eigen::Vector2f(pos_[0] - 1, pos_[1]-1), Eigen::Vector2f(-0.2, -0.2))));
        field->addObject(std::shared_ptr<GameObject>(new Bullet(Eigen::Vector2f(pos_[0] - 1, pos_[1]), Eigen::Vector2f(-0.2, 0.0))));
        field->addObject(std::shared_ptr<GameObject>(new Bullet(Eigen::Vector2f(pos_[0] - 1, pos_[1]+1), Eigen::Vector2f(-0.2, 0.2))));
    }

    return;
}
