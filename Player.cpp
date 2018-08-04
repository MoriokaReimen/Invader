/*!
 * \file Bullet.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Bulletクラスの実装
 */
#include<Player.hpp>

#include<GameObject.hpp>
#include<GameSystem.hpp>
#include<Screen.hpp>
#include<Bullet.hpp>

#include<memory>

/*!
 * @brief Playerクラスのコンストラクタ
 * @param[in] x 位置のX座標
 * @param[in] y 位置のY座標
 */
Player::Player(const int& x, const int& y) : GameObject(x, y, PLAYER)
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
    int next_x(x_), next_y(y_);
    switch(key) {
    case UP:
        next_y--;
        break;
    case DOWN:
        next_y++;
        break;
    case RIGHT:
        next_x--;
        break;
    case LEFT:
        next_x++;
        break;
    case SHOOT:
        this->shoot(x_, y_);
        break;
    default:
        break;
    }

    /*!移動範囲をフィールド上に制限*/
    Field* field = GameSystem::getField();
    if(field->is_on_field(next_x, next_y)) {
        x_ = next_x;
        y_ = next_y;
    }

    return;
}

/*!
 * @brief Playerクラスのデストラクタ
 */
Player::~Player()
{}

/*!
 * @brief Player描画する
 * @param[in,out] screen 描画するスクリーンのクラス
 */
void Player::draw(Screen& screen)
{
    screen.print("@", this->x_, this->y_, PLAYER_COLOR);
    return;
}

/*!
 * @brief 弾を発射する
 * @param[in] x 弾の生成位置
 * @param[in] y 弾の生成位置
 */
void Player::shoot(const  int&x, const int& y)
{
    Field* field = GameSystem::getField();
    field->addObject(std::shared_ptr<GameObject>(new Bullet(x, y - 1, -1)));

    return;
}

/*!
 * @brief 死亡フラグを設定する
 */
void Player::kill()
{
    GameObject::kill();

    /*! ゲームオーバフラグをGameSystemに設定する*/
    GameStatus* status = GameSystem::getStatus();
    status->setGameOver();

    return;
}
