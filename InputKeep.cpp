/*!
 * \file InputKeep.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief InputKeepクラスの宣言
 */
#include<InputKeep.hpp>

/*!
 * @brief InputKeepクラスのコンストラクタ
 */
InputKeep::InputKeep() : keep(10)
{
    return;
}

/*!
 * @brief InputKeepクラスのデストラクタ
 */
InputKeep::~InputKeep()
{}

/*!
 * @brief キー入力を収納する
 * @param[in] input 入力されたキー
 */
void InputKeep::store(const KEY_INPUT& input)
{
    keep.push_back(input);
    return;
}

/*!
 * @brief キー入力を取得する
 * @return 収納されたキー
 */
KEY_INPUT InputKeep::get()
{
    KEY_INPUT key(NONE);
    if(!keep.empty()) {
        key = keep.back();
    }

    return key;
}

/*!
 * @brief 収納されたキーをクリアする
 */
void InputKeep::clear()
{
    keep.clear();

    return;
}
