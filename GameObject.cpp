/*!
 * \file Bullet.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Bulletクラスの実装
 */
#include<GameObject.hpp>

/*!
 * @brief GameObjectクラスのコンストラクタ
 * @param[in] x X座標
 * @param[in] y Y座標
 * @param[in] type オブジェクトのタイプ
 */
GameObject::GameObject(const int& hp, const Eigen::Vector2f& pos, const Eigen::Vector2f& vel,
                       const OBJECT_TYPE& type)
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
 * @return オブジェクトの位置
 */
Eigen::Vector2f GameObject::getPosition()
{
    return this->pos_;
}

/*!
 * @brief オブジェクトのHPを返す
 * @return オブジェクトのHP
 */
int GameObject::getHP()
{
    return this->hp_;
}

/*!
 * @brief オブジェクトのタイプを返す
 * @return オブジェクトのタイプ
 */
OBJECT_TYPE GameObject::getType()
{
    return this->type_;
}

