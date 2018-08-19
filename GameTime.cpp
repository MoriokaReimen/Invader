/*!
 * \file GameTime.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief GameTimeクラスの実装
 */
#include"GameTime.hpp"
#include<chrono>
#include<thread>

/*!
 * @brief GameTimeクラスのコンストラクタ
 * @param[in] target_tpf 目標TPF
 */
GameTime::GameTime(const int& target_tpf)
    : target_tpf_(target_tpf)
{
    start_time_ = std::chrono::system_clock::now();
    game_time_ = std::chrono::system_clock::now();

    return;
}

/*!
 * @brief GameTimeクラスのデストラクタ
 */
GameTime::~GameTime()
{
    return;
}

/*!
 * @brief ゲーム時間を更新する
 */
void GameTime::update()
{
    start_time_ = std::chrono::system_clock::now();
    game_time_ += std::chrono::milliseconds(target_tpf_);

    return;
}

/*!
 * @brief TPFを取得する
 * @return 現在のTPF
 */
int GameTime::getTPF()
{
    return tpf_;
}

/*!
 * @brief 全てのループ終了時に実行されるルーティン
 */
void GameTime::onLoopEnd()
{
    /*! target_tpf_になるようsleepする */
    auto end_time = std::chrono::system_clock::now();
    auto sleep_time = game_time_ - end_time;
    if(sleep_time.count() > 0) {
        std::this_thread::sleep_for(sleep_time);
    }

    /*! tpfを更新 */
    auto tpf = std::chrono::system_clock::now() - start_time_;
    tpf_ = std::chrono::duration_cast<std::chrono::milliseconds>(tpf).count();

    return;
}

