/*!
 * \file GameSystem.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief GameSystemクラスの宣言
 */
#pragma once
#include<GameStatus.hpp>
#include<InputKeep.hpp>
#include<Field.hpp>

/*!
 * \class GameSystem
 * \brief ゲームを管理するクラスへのポインタを保持する
 */
class GameSystem
{
    static InputKeep* input_keep; //!< 入力の一時置き場
    static Field* field; //!< ゲームオブジェクトとフィールドの管理クラス
    static GameStatus* status; //!< ゲームの状態クラス

    GameSystem();
    GameSystem(const GameSystem& other);
    ~GameSystem();
    GameSystem& operator=(const GameSystem& other);

public:
    static void init();
    static InputKeep* getInputKeep();
    static Field* getField();
    static GameStatus* getStatus();
    static void cleanup();
};
