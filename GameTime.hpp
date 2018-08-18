/*!
 * \file GameTime.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief GameTimeクラスの宣言
 */
#pragma once
#include<chrono>

/*!
 * \class GameTime
 * \brief ゲーム時間管理クラス
 */
class GameTime
{
    const int target_tpf_; //!< 目標TPF
    int tpf_; //!< 現在のTPF
    /*! ループ開始時刻 */
    std::chrono::system_clock::time_point start_time_;
    /*! ループ終了時刻 */
    std::chrono::system_clock::time_point game_time_;

    GameTime(const GameTime& other) = delete;
    const GameTime& operator=(const GameTime& other) = delete;
public:
    explicit GameTime(const int& target_tpf);
    ~GameTime();
    void update();
    int getTPF();
    void onLoopEnd();

};
