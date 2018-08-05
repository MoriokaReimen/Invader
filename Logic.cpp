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

