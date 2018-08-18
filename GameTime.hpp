#pragma once
#include<chrono>

class GameTime
{
    const double target_tpf_;
    double tpf_;
    std::chrono::system_clock::time_point start_time_;
    std::chrono::system_clock::time_point game_time_;

    GameTime(const GameTime& other) = delete;
    const GameTime& operator=(const GameTime& other) = delete;
public:
    explicit GameTime(const double& target_tpf);
    ~GameTime();
    void update();
    double getTPF();
    void onLoopEnd();

};
