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
#include<Screen.hpp>
#include<Bullet.hpp>

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
        next_pos[1] -= 1;
        break;
    case DOWN:
        next_pos[1] += 1;
        break;
    case RIGHT:
        next_pos[0] -= 1;
        break;
    case LEFT:
        next_pos[0] += 1;
        break;
    case SHOOT:
        this->shoot(pos_);
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
void Player::draw(Screen& screen)
{
    screen.print("@", pos_, PLAYER_COLOR);
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
    Eigen::Vector2f bullet_vel(0.0, -0.2);
    bullet_pos[1] -= 1.0;
    GameField* field = GameSystem::getField();
    field->addObject(std::shared_ptr<GameObject>(new Bullet(bullet_pos, bullet_vel)));

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
