/*!
 * \file Logic.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Logicクラスの実装
 */
#include<Logic.hpp>

#include<GameField.hpp>
#include<Player.hpp>
#include<Enemy.hpp>
#include<GameObject.hpp>

#include<algorithm>
#include<memory>
#include<vector>

/*!
 * @brief Logicクラスのコンストラクタ
 */
Logic::Logic() : field_(GameSystem::getField())
{
    return;
}

/*!
 * @brief Logicクラスのデストラクタ
 *
 */
Logic::~Logic()
{
    return;
}

/*!
 * @brief Logicの状態を更新する
 *
 */
void Logic::update()
{
    GameStatus* status = GameSystem::getStatus();

    /*!qが入力されたゲーム終了*/
    InputKeep* input = GameSystem::getInputKeep();
    const KEY_INPUT key = input->get();
    if(key == GAME_END)
        status->setGameEnd();

    /*!敵がいなくなればプレイヤーの勝利フラグを設定*/
    if(0 == this->countEnemy())
    {
        status -> setPlayerWin();
    }

    resolveCollision();

    /*!フィールド上のオブジェクトの更新*/
    for(auto it = this->field_->begin();
            it != this->field_->end();
            it++) {
        (*it)->update();
    }


    /*!死んだオブジェクトを除去*/
    field_->update_objects();

    /*!キー入力のバッファをクリア*/
    input->clear();

    return;
}

/*!
 * @brief Logic上の敵の数を取得する
 * @return Logic上の敵の数
 */
int Logic::countEnemy() const
{
    int count(0);
    OBJECT_TYPE type;

    for(auto it = this->field_->begin();
            it != this->field_->end();
            it++) {
        type = (*it)->getType();
        if(type == ENEMY) count++;
    }

    return count;
}

/*!
 * @brief 衝突時の処理を行う
 */
void Logic::resolveCollision()
{
    GameField* field = GameSystem::getField();
    for(auto i = field->begin(); i != field->end(); ++i)
    {
        for(auto j = i; j != field->end(); ++j)
        {
            if(isCollide(*i, *j))
            {
                (*i)->on_collide(*j);
                (*j)->on_collide(*i);
            }
        }
    }

    return;
}

bool Logic::isCollide(std::shared_ptr<GameObject> lhs, std::shared_ptr<GameObject> rhs)
{
    if(!lhs) return false;
    if(!rhs) return false;
    if(lhs == rhs) return false;
    Eigen::Vector2f lpos = lhs->getPosition();
    Eigen::Vector2f rpos = rhs->getPosition();
    Eigen::Vector2f diff = lpos - rpos;
    double distance = diff.cwiseAbs().sum();
    if(distance < 20.0) return true;
    return false;
}
