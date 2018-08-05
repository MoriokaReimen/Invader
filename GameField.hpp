/*!
 * \file GameField.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief GameFieldクラスの宣言
 */
#pragma once
#include<GameObject.hpp>

#include<vector>
#include<memory>

/*!
 * \class GameField
 * \brief ゲームフィールドの管理クラス
 */
class GameField
{
    int x_; //!< フィールドの横幅
    int y_; //!< フィールドの縦幅
    std::vector<std::shared_ptr<GameObject>> objects_; //!< フィールド上のオブジェクト
    std::vector<std::shared_ptr<GameObject>> new_objects_; //!< 追加されたオブジェクトの一時置き場
public:
    GameField();

    void update_objects();

    void get_size(int& x, int& y) const;
    bool is_on_field(const int& x, const int& y) const;
    void addObject(std::shared_ptr<GameObject>&& object);
    std::shared_ptr<GameObject> getObject(const int& x, const int& y);
    std::vector<std::shared_ptr<GameObject>>::iterator begin();
    std::vector<std::shared_ptr<GameObject>>::iterator end();
};
