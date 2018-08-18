#include"GameTime.hpp"
#include<chrono>
#include<thread>

GameTime::GameTime(const int& target_tpf)
    : target_tpf_(target_tpf)
{
    start_time_ = std::chrono::system_clock::now();
    game_time_ = std::chrono::system_clock::now();

    return;
}

GameTime::~GameTime()
{
    return;
}

void GameTime::update()
{
    start_time_ = std::chrono::system_clock::now();
    game_time_ += std::chrono::milliseconds(target_tpf_);

    return;
}

int GameTime::getTPF()
{
    return tpf_;
}

void GameTime::onLoopEnd()
{
    auto end_time = std::chrono::system_clock::now();

    auto sleep_time = game_time_ - end_time;
    if(sleep_time.count() > 0)
    {
        std::this_thread::sleep_for(sleep_time);
    }

    auto tpf = std::chrono::system_clock::now() - start_time_;
    tpf_ = std::chrono::duration_cast<std::chrono::milliseconds>(tpf).count();

    return;
}

