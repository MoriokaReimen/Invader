#include<GameStatus.hpp>

GameStatus::GameStatus() : is_game_over_(false), is_player_win_(false), score_(0)
{
    return;
}

GameStatus::~GameStatus()
{
    return;
}

bool GameStatus::isGameOver() const
{
    return is_game_over_;
}

bool GameStatus::isPlayerWin() const
{
    return is_player_win_;
}

void GameStatus::setGameOver()
{
    is_game_over_ = true;
    return;
}

void GameStatus::setPlayerWin()
{
    is_player_win_ = true;
    return;
}
