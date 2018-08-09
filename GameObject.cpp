/*!
 * \file Bullet.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Bulletクラスの実装
 */
#include<GameObject.hpp>
#include<eigen3/Eigen/Eigen>

/*!
 * @brief GameObjectクラスのコンストラクタ
 * @param[in] x X座標
 * @param[in] y Y座標
 * @param[in] type オブジェクトのタイプ
 */
GameObject::GameObject(const int& hp, const Eigen::Vector2f& pos, const Eigen::Vector2f& vel, const OBJECT_TYPE& type)
    : hp_(hp), pos_(pos), vel_(vel), type_(type)
{
    return;
}

GameObject::~GameObject()
{
    return;
}

/*!
 * @brief オブジェクトの位置を返す
 * @retrun オブジェクとの位置
 */
Eigen::Vector2f GameObject::getPosition() const
{
    return this->pos_;
}

/*!
 * @brief オブジェクトの生死を返す
 * @retval true 生存
 * @retval false 死亡
 */
bool GameObject::isAlive() const
{
    return (this->hp_ > 0);
}

/*!
 * @brief オブジェクトのタイプを返す
 * @return オブジェクトのタイプ
 */
OBJECT_TYPE GameObject::getType() const
{
    return this->type_;
}

/*!
 * @brief オブジェクトのHPを返す
 * @return オブジェクトのHP
 */
int GameObject::getHP() const
{
    return this->hp_;
}

