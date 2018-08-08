/*!
 * \file Logic.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Logicクラスの宣言
 */
#pragma once
#include<GameField.hpp>

#include<vector>
#include<memory>

/*!
 * \class Logic
 * \brief ゲームフィールドの管理クラス
 */
class Logic
{
    GameField* field_;

    Logic(const Logic& other) = delete;
    Logic& operator=(const Logic& other) = delete;

    int countEnemy() const;
public:
    Logic();
    ~Logic();
    void update();
    void resolveCollision();
    bool isCollide(std::shared_ptr<GameObject> lhs, std::shared_ptr<GameObject> rhs);

};
