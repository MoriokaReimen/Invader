/*!
 * \file UserInput.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief UserInputクラスの宣言
 */
#pragma once
#include<Window.hpp>

/*!
 * \class UserInput
 * \brief キー入力の取得クラス
 */
class UserInput
{
    UserInput& operator=(const UserInput& other) = delete;
public:
    UserInput();
    ~UserInput();
    char store();
};
