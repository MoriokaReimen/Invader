/*!
 * \file EnemyBullet.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief EnemyBulletクラスの実装
 */
#include<EnemyBullet.hpp>

#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<eigen3/Eigen/Eigen>

/*!
 * @brief EnemyBulletクラスのコンストラクタ
 * @param[in] pos 位置
 * @param[in] vel 速度
 */
EnemyBullet::EnemyBullet(const Eigen::Vector2f& pos, const Eigen::Vector2f& vel) : GameObject(10, pos, vel, ENEMY_BULLET)
{
}

/*!
 * @brief 弾の状態の更新
 */
void EnemyBullet::update()
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
 * @brief EnemyBulletクラスのデストラクタ
 */
EnemyBullet::~EnemyBullet()
{}

/*!
 * @brief 弾を描画する
 * @param[in,out] screen 描画するスクリーンのクラス
 */
void EnemyBullet::draw(Render& render)
{
    render.renderImage(BULLET_IMAGE, 10, 10, pos_);

    return;
}

void EnemyBullet::on_collide(std::shared_ptr<GameObject> other)
{
    if(other->getType() == PLAYER)
        this->hp_ = 0;
    return;
}
