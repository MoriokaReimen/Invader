/*!
 * \file GameStatus.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief GameStatusクラスの宣言
 */
#pragma once

class GameStatus
{
    GameStatus(const GameStatus& other);
    GameStatus& operator=(const GameStatus& other);

    bool is_game_over_;
    bool is_player_win_;
    int score_;
public:
    GameStatus();
    ~GameStatus();
    bool isGameOver() const;
    bool isPlayerWin() const;
    void setGameOver();
    void setPlayerWin();
    void addScore(const int& score);
    int getScore();
};
