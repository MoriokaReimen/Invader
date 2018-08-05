/*!
 * \file Screen.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Screenクラスの実装
 */
#include<Screen.hpp>

#include<Window.hpp>
#include<GameSystem.hpp>

#include<ncurses.h>
#include<string>

const int SCREEN_X(250);
const int SCREEN_Y(150);


/*!
 * @brief Screenクラスのコンストラクタ
 * @param[in] win Windowクラス
 * @warning winのライフタイムに注意
 */
Screen::Screen(const Window& win) : win_(NULL), max_x_(0), max_y_(0)
{
    /*!windowポインタのアタッチ*/
    win_ = win.get_raw();

    /*!ウィンドウのサイズの初期化*/
    getmaxyx(win_, max_y_, max_x_);

    /*!カラー表示機能の初期化*/
    start_color();
    init_pair(PLAYER_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(ENEMY_COLOR, COLOR_RED, COLOR_BLACK);
    init_pair(BULLET_COLOR, COLOR_BLUE, COLOR_BLACK);
    init_pair(MESSAGE_COLOR, COLOR_BLACK, COLOR_WHITE);
    return;
}

/*!
 * @brief Screenクラスのデストラクタ
 * @param[in] win Windowクラス
 */
Screen::~Screen()
{
    return;
}

/*!
 * @brief 表示をクリアする
 */
void Screen::clear()
{
    wclear(win_);
    return;
}

/*!
 * @brief 画面表示を更新する
 */
void Screen::update() {
    this->clear(); //!< 画面表示をクリア
    this->printBorder(); //!< 枠を表示
    this->drawObjects(); //!< ゲームオブジェクトを描画

    GameStatus* status = GameSystem::getStatus();
    if(status->isGameOver())
        this->printGameOver();

    if(status->isPlayerWin())
        this->printPlayerWin();

    printScore();

    wrefresh(win_);
    return;
}

/*!
 * @brief 画面に文字列を表示する
 * @param[in] str 表示する文字列
 * @param[in] x 表示位置のX座標
 * @param[in] y 表示位置のX座標
 * @retval true 成功
 * @retval false 失敗
 */
bool Screen::print(const char* const str, const int& x, const int& y)
{
    int err = mvwprintw(win_, y, x, str);
    return err == OK;
}

/*!
 * @brief 画面に文字列を色付きで表示する
 * @param[in] str 表示する文字列
 * @param[in] x 表示位置のX座標
 * @param[in] y 表示位置のX座標
 * @param[in] color 色
 * @retval true 成功
 * @retval false 失敗
 */
bool Screen::print(const char* const str, const int& x, const int& y, const COLOR& color)
{
    attron(COLOR_PAIR(color));
    int err = mvwprintw(win_, y, x, str);
    attroff(COLOR_PAIR(color));
    return err == OK;
}

/*!
 * @brief 画面に文字列を表示する
 * @param[in] str 表示する文字列
 * @param[in] x 表示位置のX座標
 * @param[in] y 表示位置のX座標
 * @retval true 成功
 * @retval false 失敗
 */
bool Screen::print(const std::string& str, const int& x, const int& y)
{
    return this->print(str.c_str(), x, y);
}

/*!
 * @brief 画面に文字列を表示する
 * @param[in] str 表示する文字列
 * @param[in] x 表示位置のX座標
 * @param[in] y 表示位置のX座標
 * @param[in] color 色
 * @retval true 成功
 * @retval false 失敗
 */
bool Screen::print(const std::string& str, const int& x, const int& y, const COLOR& color)
{
    bool err = this->print(str.c_str(), x, y, color);
    return err;
}

/*!
 * @brief 画面に文字を表示する
 * @param[in] ch 表示する文字列
 * @param[in] x 表示位置のX座標
 * @param[in] y 表示位置のX座標
 * @param[in] color 色
 * @retval true 成功
 * @retval false 失敗
 */
bool Screen::print(const char& ch, const int& x, const int& y)
{
    return mvwaddch(win_, y, x, ch);
}

/*!
 * @brief 画面に文字を色付きで表示する
 * @param[in] ch 表示する文字列
 * @param[in] x 表示位置のX座標
 * @param[in] y 表示位置のX座標
 * @param[in] color 色
 * @retval true 成功
 * @retval false 失敗
 */
bool Screen::print(const char& ch, const int& x, const int& y, const COLOR& color)
{
    bool ret(false);
    attron(COLOR_PAIR(color));
    ret = mvwaddch(win_, y, x, ch);
    attroff(COLOR_PAIR(color));
    return ret;
}

/*!
 * @brief Game枠を描画する
 * @param[in] x_size 横幅
 * @param[in] y_size 縦幅
 */
void Screen::printBorder()
{
    GameField* field = GameSystem::getField();

    field->get_size(max_x_, max_y_);
    /*四隅を描画*/
    this->print("+", 0, 0);
    this->print("+", 0, max_y_ - 1);
    this->print("+", max_x_ - 1, max_y_ - 1);
    this->print("+", max_x_ - 1, 0);

    /*縦を描画*/
    for(int col = 1; col < max_x_ - 1; col++) {
        this->print("-", col, 0);
        this->print("-", col, max_y_ - 1);
    }

    /*横を描画*/
    for(int row = 1; row < max_y_ - 1; row++) {
        this->print("|", 0, row);
        this->print("|", max_x_ - 1, row);
    }

    return;
}

/*!
 * @brief Screenのサイズを取得する
 * @param[out] x 横幅
 * @param[out] y 縦幅
 */
void Screen::getSize(int& x, int& y)
{
    getmaxyx(win_, max_y_, max_x_);
    x = this->max_x_;
    y = this->max_y_;
    return;
}

/*!
 * @brief GameObjectを描画する
 */
void Screen::drawObjects()
{
    GameField* field = GameSystem::getField();
    for(auto it = field->begin(); it != field->end(); it++)
        (*it)->draw(*this);

    return;
}

/*!
 * @brief GAME OVER表示
 */
void Screen::printGameOver()
{
    std::string message("GAME OVER");
    this->print(message, 30, 18, MESSAGE_COLOR);

}

/*!
 * @brief プレイヤー勝利表示
 */
void Screen::printPlayerWin()
{
    std::string message("PLAYER WIN");
    this->print(message, 30, 18, MESSAGE_COLOR);

}

/*!
 * @brief スコアを表示する
 */
void Screen::printScore()
{
    char msg[100];
    GameStatus* status = GameSystem::getStatus();
    const int score = status->getScore();
    std::snprintf(msg, sizeof(msg), "Score: %d", score);
    this->print(msg, 90, 3);

}
