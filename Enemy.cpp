/*!
 * \file Enemy.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Enemyクラスの実装
 */
#include<Enemy.hpp>

#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Bullet.hpp>

#include<memory>
#include<random>
#include<eigen3/Eigen/Eigen>

const int ENEMY_HP(30);

/*!
 * @brief Enemyクラスのコンストラクタ
 * @param[in] x 位置のX座標
 * @param[in] y 位置のY座標
 */
Enemy::Enemy(const Eigen::Vector2f& pos)
    : GameObject(ENEMY_HP, pos, Eigen::Vector2f::Zero(), ENEMY), generator_(), distribution_(0, 100)
{
}

/*!
 * @brief Enemy状態の更新
 */
void Enemy::update()
{
    GameField* field = GameSystem::getField();

    /*!フィールドの端に到達したらプレイヤーの負け*/
    GameStatus* status = GameSystem::getStatus();
    int _, field_y;
    field->get_size(_, field_y);
    if(this->pos_[1] > (field_y - 3))
        status->setGameOver();

    /*!ランダムに動作を設定*/
    Eigen::Vector2f next_pos(pos_);
    const int next_action = distribution_(generator_) % 200;
    switch(next_action) {
    case 1:
        next_pos[0]+=10.0;
        break;
    case 2:
        next_pos[0]-=10.0;
        break;
    case 3:
        next_pos[1]+=10.0;
        break;
    case 4:
        shoot(pos_);
    default:
        break;
    }

    /*!フィールド内に動きを制限*/
    if(field->is_on_field(next_pos) && !(field->getObject(next_pos))) {
        pos_ = next_pos;
    }

    return;
}

/*!
 * @brief Enemyクラスのデストラクタ
 */
Enemy::~Enemy()
{
    auto status = GameSystem::getStatus();
    status->addScore(10);
}

/*!
 * @brief Enemyを描画する
 * @param[in,out] screen 描画するスクリーンのクラス
 */
void Enemy::draw(Render& render)
{
    render.renderImage(ENEMY_IMAGE, 20, 20, pos_);
    return;
}

/*!
 * @brief 弾を発射する
 * @param[in] x 弾の生成位置
 * @param[in] y 弾の生成位置
 */
void Enemy::shoot(const Eigen::Vector2f& pos)
{
    Eigen::Vector2f bullet_pos(pos);
    Eigen::Vector2f bullet_vel(0.0, 10);
    bullet_pos[1] += 20.0;
    GameField* field = GameSystem::getField();
    field->addObject(std::shared_ptr<GameObject>(new Bullet(bullet_pos, bullet_vel)));

    GameSound* sound = GameSystem::getSound();
    sound->playSound(SHOOT_SOUND);

    return;
}

void Enemy::on_collide(std::shared_ptr<GameObject> other)
{
    if(!other) return;
    if(other.get() == this) return;
    if(other->getType() == BULLET) {
        this->hp_ -= 10;
    }

    return;
}
