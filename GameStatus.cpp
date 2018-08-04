/*!
 * \file Bullet.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief GameStatusクラスの実装
 */
#include<GameStatus.hpp>

/*!
 * @brief GameStatusのコンストラクタ
 */
GameStatus::GameStatus() : is_game_over_(false), is_player_win_(false), score_(0)
{
    return;
}

/*!
 * @brief GameStatusのデストラクタ
 */
GameStatus::~GameStatus()
{
    return;
}

/*!
 * @brief ゲームオーバかどうかを返す
 * @retval true ゲームオーバ
 * @retval false ゲームオーバでない
 */
bool GameStatus::isGameOver() const
{
    return is_game_over_;
}

/*!
 * @brief プレイヤーの勝利かどうかを返す
 * @retval true プレイヤーの勝利
 * @retval false プレイヤーの勝利でない
 */
bool GameStatus::isPlayerWin() const
{
    return is_player_win_;
}

/*!
 * @brief ゲームオーバフラグをセットする
 */
void GameStatus::setGameOver()
{
    is_game_over_ = true;
    return;
}

/*!
 * @brief プレイヤー勝利フラグをセットする
 */
void GameStatus::setPlayerWin()
{
    is_player_win_ = true;
    return;
}

/*!
 * @brief スコアを加算する
 * @param[in] score 加算するスコア
 */
void GameStatus::addScore(const int& score)
{
    this->score_ += score;

    return;
}

/*!
 * @brief スコアを取得する
 * @return スコア
 */
int GameStatus::getScore()
{
    return this->score_;
}
