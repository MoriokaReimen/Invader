/*!
 * \file GameField.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief GameFieldクラスの実装
 */
#include<GameField.hpp>
#include<Player.hpp>
#include<GameObject.hpp>

#include<algorithm>
#include<memory>
#include<vector>
#include<eigen3/Eigen/Eigen>

const int FIELD_X(80); //!< フィールド横幅
const int FIELD_Y(40); //!< フィールド縦幅

/*!
 * @brief GameFieldクラスのコンストラクタ
 * フィールドサイズとフィールド上のオブジェクトの初期化
 *
 */
GameField::GameField() : x_(FIELD_X), y_(FIELD_Y)
{
    Eigen::Vector2f pos(40, 38);
    this->objects_.emplace_back(std::shared_ptr<GameObject>(new Player(pos)));

    return;
}

/*!
 * @brief フィールドのサイズを取得する
 * @param[out] x 横幅のサイズ
 * @param[out] y 縦幅のサイズ
 */
void GameField::get_size(int& x, int& y) const
{
    x = this->x_;
    y = this->y_;

    return;
}

/*!
 * @brief 指定された座標がフィールド上かどうかを判定する
 * @param[in] pos 位置
 * @retval true フィールド上
 * @retval false フィールド外
 */
bool GameField::is_on_field(const Eigen::Vector2f& pos) const
{
    if(pos[0] >= this->x_ - 1) return false;
    if(pos[0] < 1) return false;
    if(pos[1] >= this->y_ - 1) return false;
    if(pos[1] < 1) return false;
    return true;
}

/*!
 * @brief 管理下のオブジェクトを追加・除去を行う
 */
void GameField::update_objects()
{
    /*!更新中に増えたオブジェクトを追加*/
    this->objects_.insert(this->objects_.end(),
                          this->new_objects_.begin(),
                          this->new_objects_.end());
    this->new_objects_.clear();

    /*!死んだオブジェクトを除去*/
    typedef std::shared_ptr<GameObject> Elem;
    this->objects_.erase(
        std::remove_if(
            this->objects_.begin(),
            this->objects_.end(),
    [](const Elem& elem) {
        return ! elem->isAlive();
    }),
    this->objects_.end());

    return;
}

/*!
 * @brief フィールドにオブジェクトを追加する
 * @param[in] 追加するオブジェクトへの追加
 */
void GameField::addObject(std::shared_ptr<GameObject>&& object)
{
    this->new_objects_.emplace_back(object);
    return;
}

/*!
 * @brief 指定された位置のオブジェクトのポインタを取得する
 * @param center 位置のX座標
 * @return オブジェクトへのポインタ
 * @warning オブジェクトがなければNULLポインタを返す
 */
std::shared_ptr<GameObject> GameField::getObject(const Eigen::Vector2f& center)
{
    for(auto it = this->objects_.begin(); it != this->objects_.end(); it++) {
        Eigen::Vector2f pos = (*it)->getPosition();
        Eigen::Vector2f diff = center - pos;
        double distance = diff.cwiseAbs2().sum();
        if(distance < 1.0)
            return *it;
    }

    return std::shared_ptr<GameObject>();
}

/*!
 * @brief フィールド上のオブジェクトへの始点イテレータを取得する
 * @return オブジェクトへのイテレータ
 */
std::vector<std::shared_ptr<GameObject>>::iterator GameField::begin()
{
    return this->objects_.begin();
}

/*!
 * @brief フィールド上のオブジェクトへの終点イテレータを取得する
 * @return オブジェクトへのイテレータ
 */
std::vector<std::shared_ptr<GameObject>>::iterator GameField::end()
{
    return this->objects_.end();
}
