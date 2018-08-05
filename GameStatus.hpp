/*!
 * \file GameStatus.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief GameStatusクラスの宣言
 */
#pragma once

/*!
 * \class GameStatus
 * \brief ゲームの状態管理クラス
 */
class GameStatus
{
    GameStatus(const GameStatus& other) = delete;
    GameStatus& operator=(const GameStatus& other) = delete;

    bool is_game_over_; //!< ゲームオーバフラグ
    bool is_player_win_; //!< プレイヤーの勝利
    bool is_game_end_; //!< ゲームの終了
    int score_; //!< スコア
public:
    GameStatus();
    ~GameStatus();
    bool isGameOver() const;
    bool isPlayerWin() const;
    bool isGameEnd() const;
    void setGameOver();
    void setGameEnd();
    void setPlayerWin();
    void addScore(const int& score);
    int getScore();
};
