/*!
 * \file InputKeep.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief InputKeepクラスの宣言
 */
#pragma once
#include<vector>

enum KEY_INPUT {
    NONE,
    UP,
    DOWN,
    RIGHT,
    LEFT,
    SHOOT
};

class InputKeep
{
    std::vector<KEY_INPUT> keep;
    InputKeep(const InputKeep& other);
    InputKeep& operator=(const InputKeep& other);
public:
    InputKeep();
    ~InputKeep();
    void store(const KEY_INPUT& input);
    KEY_INPUT get();
    void clear();
};

