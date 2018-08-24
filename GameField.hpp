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
#include<eigen3/Eigen/Eigen>

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
    bool is_on_field(const Eigen::Vector2f& pos) const;
    void addObject(std::shared_ptr<GameObject>&& object);
    std::shared_ptr<GameObject> getObject(const Eigen::Vector2f& center);
    std::vector<std::shared_ptr<GameObject>>::iterator begin();
    std::vector<std::shared_ptr<GameObject>>::iterator end();
    std::shared_ptr<GameObject> find(const OBJECT_TYPE& type);
};
