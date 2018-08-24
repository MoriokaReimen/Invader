/*!
 * \file Bullet.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Bulletクラスの実装
 */
#include<Bullet.hpp>

#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<eigen3/Eigen/Eigen>

/*!
 * @brief Bulletクラスのコンストラクタ
 * @param[in] pos 位置
 * @param[in] vel 速度
 */
Bullet::Bullet(const Eigen::Vector2f& pos, const Eigen::Vector2f& vel) : GameObject(10, pos, vel, BULLET)
{
}

/*!
 * @brief 弾の状態の更新
 */
void Bullet::update()
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
 * @brief Bulletクラスのデストラクタ
 */
Bullet::~Bullet()
{}

/*!
 * @brief 弾を描画する
 * @param[in,out] screen 描画するスクリーンのクラス
 */
void Bullet::draw(Render& render)
{
    render.renderImage(BULLET_IMAGE, 10, 10, pos_);

    return;
}

void Bullet::on_collide(std::shared_ptr<GameObject> other)
{
    if(other->getType() != BULLET && other->getType() != ENEMY_BULLET)
        this->hp_ = 0;
    return;
}
