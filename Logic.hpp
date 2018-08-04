/*!
 * \file Logic.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Logicクラスの宣言
 */
#pragma once
#include<GameObject.hpp>

#include<vector>
#include<memory>

/*!
 * \class Logic
 * \brief ゲームフィールドの管理クラス
 */
class Logic
{
    int x_; //!< フィールドの横幅
    int y_; //!< フィールドの縦幅
    std::vector<std::shared_ptr<GameObject>> objects_; //!< フィールド上のオブジェクト
    std::vector<std::shared_ptr<GameObject>> new_objects_; //!< 追加されたオブジェクトの一時置き場
public:
    Logic();

    void update();
    void draw();
    void draw(Screen& screen);
    void reap();

    int get_x() const;
    int get_y() const;
    bool is_on_field(const int& x, const int& y) const;
    void addObject(std::shared_ptr<GameObject>&& object);
    std::shared_ptr<GameObject> getObject(const int& x, const int& y);
    bool checkPosition(const int& x, const int& y) const;
    int countEnemy() const;

};
