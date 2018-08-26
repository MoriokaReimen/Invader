/*!
 * \file LifePack.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief LifePackクラスの実装
 */
#include<LifePack.hpp>

#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<eigen3/Eigen/Eigen>

/*!
 * @brief LifePackクラスのコンストラクタ
 * @param[in] pos 位置
 * @param[in] vel 速度
 */
LifePack::LifePack(const Eigen::Vector2f& pos, const Eigen::Vector2f& vel) : GameObject(10, pos, vel, LIFE_PACK)
{
}

/*!
 * @brief 弾の状態の更新
 */
void LifePack::update()
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
 * @brief LifePackクラスのデストラクタ
 */
LifePack::~LifePack()
{}

/*!
 * @brief 弾を描画する
 * @param[in,out] screen 描画するスクリーンのクラス
 */
void LifePack::draw(Render& render)
{
    render.renderImage(LIFE_PACK_IMAGE, 20, 20, pos_);

    return;
}

void LifePack::on_collide(std::shared_ptr<GameObject> other)
{
    if(other->getType() == PLAYER) {
        this->hp_ = 0;
    }
    return;
}
