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
    render.renderImage(BOMB_IMAGE, 20, 20, pos_);

    return;
}

void Bomb::on_collide(std::shared_ptr<GameObject> other)
{
    const int FRAGMENT_COUNT(20);
    GameField* field = GameSystem::getField();
    if(other->getType() != ENEMY_BULLET &&
       other->getType() != BULLET
    ) {
        this->hp_ = 0;

        Eigen::Vector2f offset(20,0);
        for(int i = 0; i < FRAGMENT_COUNT; ++i) {
            Eigen::Rotation2D<float> rot(i * 2 * M_PI / FRAGMENT_COUNT);
            Eigen::Vector2f init_pos = pos_ + rot * offset;
            Eigen::Vector2f bullet_vel = init_pos - pos_;
            bullet_vel = bullet_vel.normalized() * 10.0;
            field->addObject(std::shared_ptr<GameObject>(new Bullet(init_pos, bullet_vel)));

        }

        GameSound* sound = GameSystem::getSound();
        sound->stopSound();
        sound->playSound(EXPLODE_SOUND);
    }

    return;
}
