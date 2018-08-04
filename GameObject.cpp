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
GameObject::GameObject(const int& x, const int& y, const OBJECT_TYPE& type) :
    x_(x), y_(y), is_alive_(true), type_(type)
{
    return;
}

GameObject::~GameObject()
{
    return;
}

/*!
 * @brief オブジェクトの位置を返す
 * @param[out] x X座標
 * @param[out] y Y座標
 */
void GameObject::getPosition(int& x, int& y)
{
    x = this->x_;
    y = this->y_;
    return;
}

/*!
 * @brief オブジェクトの生死を返す
 * @retval true 生存
 * @retval false 死亡
 */
bool GameObject::isAlive()
{
    return is_alive_;
}

/*!
 * @brief オブジェクトのタイプを返す
 * @return オブジェクトのタイプ
 */
OBJECT_TYPE GameObject::getType()
{
    return this->type_;
}

/*!
 * @brief 死亡フラグをセットする
 */
void GameObject::kill()
{
    this->is_alive_ = false;

    return;
}
