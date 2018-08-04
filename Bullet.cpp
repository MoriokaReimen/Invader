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

/*!
 * @brief Bulletクラスのコンストラクタ
 * @param[in] x 位置のX座標
 * @param[in] y 位置のY座標
 * @param[in] direction 進行方向
 */
Bullet::Bullet(const int& x, const int& y, const int& direction) : GameObject(x, y, BULLET), direction_(direction)
{
}

/*!
 * @brief 弾の状態の更新
 */
void Bullet::update()
{
    /*!位置を更新*/
    this->y_ += direction_ * 0.1;

    /*!弾の命中処理*/
    Field* field = GameSystem::getField();
    auto hit_object = field->getObject(this->x_, this->y_);
    if(hit_object != nullptr && hit_object.get() != this) {
        hit_object->kill();
    }

    /*!フィールド外に出たら消滅する*/
    if(!field->is_on_field(this->x_, this->y_)) {
        this->is_alive_ = false;
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
void Bullet::draw(Screen& screen)
{
    screen.print("|", this->x_, this->y_, BULLET_COLOR);

    return;
}

