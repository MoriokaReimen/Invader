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

/*!
 * \class InputKeep
 * \brief ユーザ入力の一時保持クラス
 */
class InputKeep
{
    std::vector<KEY_INPUT> keep; //!< キー入力を保持
    InputKeep(const InputKeep& other) = delete;
    InputKeep& operator=(const InputKeep& other) = delete;
public:
    InputKeep();
    ~InputKeep();
    void store(const KEY_INPUT& input);
    KEY_INPUT get();
    void clear();
};

