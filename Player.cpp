/*!
 * \file Player.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Playerクラスの実装
 */
#include<Player.hpp>

#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Bullet.hpp>
#include<Bomb.hpp>

#include<memory>
#include<eigen3/Eigen/Eigen>

const int PLAYER_HP(100);

/*!
 * @brief Playerクラスのコンストラクタ
 * @param[in] x 位置のX座標
 * @param[in] y 位置のY座標
 */
Player::Player(const Eigen::Vector2f& pos) : GameObject(PLAYER_HP, pos, Eigen::Vector2f::Zero(), PLAYER)
{
}

/*!
 * @brief Player状態の更新
 */
void Player::update()
{
    /*!キー入力を反映*/
    InputKeep* input = GameSystem::getInputKeep();
    const KEY_INPUT key = input->get();
    Eigen::Vector2f next_pos(pos_);

    switch(key) {
    case UP:
        next_pos[1] -= 10;
        break;
    case DOWN:
        next_pos[1] += 10;
        break;
    case RIGHT:
        next_pos[0] -= 10;
        break;
    case LEFT:
        next_pos[0] += 10;
        break;
    case SHOOT:
        this->shoot(pos_);
        break;
    case BOMB:
        this->bomb(pos_);
        break;
    default:
        break;
    }

    /*!移動範囲をフィールド上に制限*/
    GameField* field = GameSystem::getField();
    if(field->is_on_field(next_pos)) {
        pos_ = next_pos;
    }

    return;
}

/*!
 * @brief Playerクラスのデストラクタ
 */
Player::~Player()
{
    auto status = GameSystem::getStatus();
    status->setGameOver();
    return;
}

/*!
 * @brief Player描画する
 * @param[in,out] screen 描画するスクリーンのクラス
 */
void Player::draw(Render& render)
{
    render.renderImage(PLAYER_IMAGE, 20, 20,pos_);
    return;
}

/*!
 * @brief 弾を発射する
 * @param[in] x 弾の生成位置
 * @param[in] y 弾の生成位置
 */
void Player::shoot(const Eigen::Vector2f& pos)
{
    Eigen::Vector2f bullet_pos(pos);
    Eigen::Vector2f bullet_vel(0.0, -10);
    bullet_pos[1] -= 20.0;
    GameField* field = GameSystem::getField();
    field->addObject(std::shared_ptr<GameObject>(new Bullet(bullet_pos, bullet_vel)));

    return;
}

/*!
 * @brief 爆弾を発射する
 * @param[in] x 弾の生成位置
 * @param[in] y 弾の生成位置
 */
void Player::bomb(const Eigen::Vector2f& pos)
{
    Eigen::Vector2f bullet_pos(pos);
    Eigen::Vector2f bullet_vel(0.0, -10);
    bullet_pos[1] -= 20.0;
    GameField* field = GameSystem::getField();
    field->addObject(std::shared_ptr<GameObject>(new Bomb(bullet_pos, bullet_vel)));

    return;
}

void Player::on_collide(std::shared_ptr<GameObject> other)
{
    if(!other) return;
    if(other.get() == this) return;
    if(other->getType() == BULLET)
    {
        this->hp_ -= 10;
    }

    return;
}
