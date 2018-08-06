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

const int FIELD_X(80); //!< フィールド横幅
const int FIELD_Y(40); //!< フィールド縦幅

/*!
 * @brief GameFieldクラスのコンストラクタ
 * フィールドサイズとフィールド上のオブジェクトの初期化
 *
 */
GameField::GameField() : x_(FIELD_X), y_(FIELD_Y)
{
    this->objects_.emplace_back(std::shared_ptr<GameObject>(new Player(40, 38)));

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
 * @retval true フィールド上
 * @retval false フィールド外
 */
bool GameField::is_on_field(const int& x, const int& y) const
{
    if(x >= this->x_ - 1) return false;
    if(x < 1) return false;
    if(y >= this->y_ - 1) return false;
    if(y < 1) return false;
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
 * @param[in] x 位置のX座標
 * @param[in] y 位置のY座標
 * @return オブジェクトへのポインタ
 * @warning オブジェクトがなければNULLポインタを返す
 */
std::shared_ptr<GameObject> GameField::getObject(const int& x, const int& y)
{
    int pos_x(0);
    int pos_y(0);

    for(auto it = this->objects_.begin();
            it != this->objects_.end();
            it++) {
        (*it)->getPosition(pos_x, pos_y);
        if(pos_x == x && pos_y == y)
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
