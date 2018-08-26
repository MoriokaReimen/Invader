/*!
 * \file Missile.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Missileクラスの実装
 */
#include<Missile.hpp>

#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<EnemyBullet.hpp>
#include<eigen3/Eigen/Eigen>
#include<memory>

/*!
 * @brief Missileクラスのコンストラクタ
 * @param[in] pos 位置
 * @param[in] vel 速度
 */
Missile::Missile(const Eigen::Vector2f& pos, const Eigen::Vector2f& vel) : GameObject(50, pos, vel, BULLET)
{
}

/*!
 * @brief 弾の状態の更新
 */
void Missile::update()
{
    /*!位置を更新*/
    trackPlayer();

    /*!フィールド外に出たら消滅する*/
    GameField* field = GameSystem::getField();
    if(!field->is_on_field(pos_)) {
        this->hp_ = 0;
    }

    return;
}

/*!
 * @brief Missileクラスのデストラクタ
 */
Missile::~Missile()
{}

/*!
 * @brief 弾を描画する
 * @param[in,out] screen 描画するスクリーンのクラス
 */
void Missile::draw(Render& render)
{
    render.renderImage(MISSILE_IMAGE, 20, 20, pos_);

    return;
}

void Missile::on_collide(std::shared_ptr<GameObject> other)
{
    GameField* field = GameSystem::getField();
    if( other->getType() == BULLET) {
        this->hp_ -= 10;
        if(this->hp_ <= 0.0) {
            this->explode();
        }
    }

    return;
}

/*!
 * @brief 爆発して弾を撒き散らす
 */
void Missile::explode()
{
    this->hp_ = 0;

    const int FRAGMENT_COUNT(20);
    Eigen::Vector2f offset(20,0);
    for(int i = 0; i < FRAGMENT_COUNT; ++i) {
        Eigen::Rotation2D<float> rot(i * 2 * M_PI / FRAGMENT_COUNT);
        Eigen::Vector2f init_pos = pos_ + rot * offset;
        Eigen::Vector2f bullet_vel = init_pos - pos_;
        bullet_vel = bullet_vel.normalized() * 10.0;
        GameField* field = GameSystem::getField();
        field->addObject(std::shared_ptr<GameObject>(new EnemyBullet(init_pos, bullet_vel)));

    }

    GameSound* sound = GameSystem::getSound();
    sound->stopSound();
    sound->playSound(EXPLODE_SOUND);

    return;

}

/*!
 * @brief プレイヤーを追跡する
 */
void Missile::trackPlayer()
{
    GameField* field = GameSystem::getField();
    auto player = field->find(PLAYER);
    if(player) {
        auto player_pos = player->getPosition();
        Eigen::Vector2f dist;
        dist = player_pos - pos_;
        if(dist.norm() < 200) {
            this->explode();
        } else {
            auto v = dist + Eigen::Vector2f(0, 10);
            pos_ += v.normalized() * 10;
        }
    } else {
        pos_ += Eigen::Vector2f(0, 10);
    }

    return;
}
