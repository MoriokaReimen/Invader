/*!
 * \file Logic.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Logicクラスの実装
 */
#include<Logic.hpp>
#include<Player.hpp>
#include<Enemy.hpp>
#include<GameObject.hpp>

#include<algorithm>
#include<memory>
#include<vector>

const int FIELD_X(80); //!< フィールド横幅
const int FIELD_Y(40); //!< フィールド縦幅

/*!
 * @brief Logicクラスのコンストラクタ
 * フィールドサイズとフィールド上のオブジェクトの初期化
 *
 */
Logic::Logic() : x_(FIELD_X), y_(FIELD_Y)
{
    this->objects_.emplace_back(std::shared_ptr<GameObject>(new Player(40, 38)));

    for(int i = 15; i < 75; ++i)
        for(int j = 1; j < 6; ++j)
            this->objects_.emplace_back(std::shared_ptr<GameObject>(new Enemy(i, j)));

    return;
}

/*!
 * @brief Logicの状態を更新する
 *
 */
void Logic::update()
{
    /*!敵がいなくなればプレイヤーの勝利フラグを設定*/
    GameStatus* status = GameSystem::getStatus();
    if(0 == this->countEnemy())
    {
        status -> setPlayerWin();
    }

    /*!フィールド上のオブジェクトの更新*/
    int object_num = this->objects_.size();
    for(int c = 0; c < object_num; c++)
        this->objects_[c]->update();

    /*!死んだオブジェクトを除去*/
    this->reap();

    /*!更新中に増えたオブジェクトを追加*/
    this->objects_.insert(this->objects_.end(),
                          this->new_objects_.begin(),
                          this->new_objects_.end());
    this->new_objects_.clear();

    return;
}

/*!
 * @brief Logic上のオブジェクトを描画する
 * @param[in,out] screen Screenクラス
 */
void Logic::draw(Screen& screen)
{
    for(auto it = this->objects_.begin();
            it != this->objects_.end();
            it++) {
        (*it)->draw(screen);
    }
    return;
}

/*!
 * @brief フィールドの横幅を取得する
 * @return 横幅のサイズ
 */
int Logic::get_x() const
{
    return this->x_;
}

/*!
 * @brief フィールドの縦幅を取得する
 * @return 縦幅のサイズ
 */
int Logic::get_y() const
{
    return this->y_;
}

/*!
 * @brief 指定された座標がフィールド上かどうかを判定する
 * @retval true フィールド上
 * @retval false フィールド外
 */
bool Logic::is_on_field(const int& x, const int& y) const
{
    if(x >= this->x_ - 1) return false;
    if(x < 1) return false;
    if(y >= this->y_ - 1) return false;
    if(y < 1) return false;
    return true;
}

/*!
 * @brief 死んだオブジェクトを除去する
 */
void Logic::reap()
{
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
void Logic::addObject(std::shared_ptr<GameObject>&& object)
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
std::shared_ptr<GameObject> Logic::getObject(const int& x, const int& y)
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
 * @brief 指定された位置にオブジェクトがあるかを判定する
 * @param[in] x 位置のX座標
 * @param[in] y 位置のY座標
 * @retval true オブジェクトが存在
 * @retval false オブジェクトが不在
 */
bool Logic::checkPosition(const int& x, const int& y) const
{
    int pos_x(0);
    int pos_y(0);

    for(auto it = this->objects_.begin();
            it != this->objects_.end();
            it++) {
        (*it)->getPosition(pos_x, pos_y);
        if(pos_x == x && pos_y == y)
            return true;
    }

    return false;
}

/*!
 * @brief Logic上の敵の数を取得する
 * @return Logic上の敵の数
 */
int Logic::countEnemy() const
{
    int count(0);
    OBJECT_TYPE type;

    for(auto it = this->objects_.begin();
            it != this->objects_.end();
            it++) {
        type = (*it)->getType();
        if(type == ENEMY) count++;
    }

    return count;
}

