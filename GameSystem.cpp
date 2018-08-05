/*!
 * \file Bullet.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Bulletクラスの実装
 */
#include<GameSystem.hpp>

#include<InputKeep.hpp>
#include<GameStatus.hpp>
#include<GameField.hpp>
#include<GameStatus.hpp>

InputKeep* GameSystem::input_keep;
GameField* GameSystem::field;
GameStatus* GameSystem::status;

/*!
 * @brief GameSystemを初期化する
 */
void GameSystem::init()
{
    input_keep = new InputKeep();
    field = new GameField();
    status = new GameStatus();

    return;
}

/*!
 * @brief InputKeepクラスへのポインタを返す
 * @return InputKeepへのポインタ
 * @warning GameSystem::initが先に呼ばれている必要があります
 */
InputKeep* GameSystem::getInputKeep()
{
    return input_keep;
}

/*!
 * @brief Fieldクラスへのポインタを返す
 * @return Fieldへのポインタ
 * @warning GameSystem::initが先に呼ばれている必要があります
 */
GameField* GameSystem::getField()
{
    return field;
}

/*!
 * @brief cleanup
 * @return ポインタを解放する
 * @warning GameSystem::initが先に呼ばれている必要があります
 */
void GameSystem::cleanup()
{
    delete input_keep;
    delete field;
    delete status;
}

/*!
 * @brief GameStatusクラスへのポインタを返す
 * @return GameStatusへのポインタ
 * @warning GameSystem::initが先に呼ばれている必要があります
 */
GameStatus* GameSystem::getStatus()
{
    return status;
}
