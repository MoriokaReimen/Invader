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
#include<Screen.hpp>
#include<Bullet.hpp>

#include<memory>
#include<random>

/*!
 * @brief Enemyクラスのコンストラクタ
 * @param[in] x 位置のX座標
 * @param[in] y 位置のY座標
 */
Enemy::Enemy(const int& x, const int& y) :
    GameObject(x, y, ENEMY), generator_(), distribution_(0, 100)
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
    if(this->y_ > (field_y - 3))
        status->setGameOver();

    /*!ランダムに動作を設定*/
    int next_x(x_), next_y(y_);
    const int next_action = distribution_(generator_) % 200;
    switch(next_action) {
    case 1:
        next_x++;
        break;
    case 2:
        next_x--;
        break;
    case 3:
        next_y++;
        break;
    case 4:
        shoot(x_, y_ + 1);
    default:
        break;
    }

    /*!フィールド内に動きを制限*/
    if(field->is_on_field(next_x, next_y) && !(field->getObject(next_x, next_y))) {
        x_ = next_x;
        y_ = next_y;
    }

    return;
}

/*!
 * @brief Enemyクラスのデストラクタ
 */
Enemy::~Enemy()
{}

/*!
 * @brief Enemyを描画する
 * @param[in,out] screen 描画するスクリーンのクラス
 */
void Enemy::draw(Screen& screen)
{
    screen.print("M", this->x_, this->y_, ENEMY_COLOR);
    return;
}

/*!
 * @brief 弾を発射する
 * @param[in] x 弾の生成位置
 * @param[in] y 弾の生成位置
 */
void Enemy::shoot(const  int&x, const int& y)
{
    GameField* field = GameSystem::getField();
    field->addObject(std::shared_ptr<GameObject>(new Bullet(x, y+1, 1)));

    return;
}

/*!
 * @brief 死亡フラグを設定する
 */
void Enemy::kill()
{
    GameObject::kill();

    /*!スコアを加算する*/
    GameStatus* status = GameSystem::getStatus();
    status->addScore(30);

    return;

}
