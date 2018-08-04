/*!
 * \file Screen.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Screenクラスの宣言
 */
#pragma once

#include<string>

typedef struct _win_st WINDOW;
class Window;

enum COLOR
{
    PLAYER_COLOR,
    ENEMY_COLOR,
    BULLET_COLOR,
    MESSAGE_COLOR,
};

/*!
 * \class Screen
 * \brief 画面表示クラス
 */
class Screen
{
    WINDOW* win_; //!< cursesのwindowポインタ
    int max_x_; //!< 画面横幅サイズ
    int max_y_; //!< 画面縦幅サイズ

    Screen() = delete;
    Screen(const Screen& other) = delete;
    Screen& operator=(const Screen& other) = delete;
public:
    Screen(const Window& win);
    ~Screen();
    void clear();
    void update();
    bool print(const char* const str, const int& x, const int& y);
    bool print(const std::string& str, const int& x, const int& y);
    bool print(const char& ch, const int& x, const int& y);
    bool print(const char* const str, const int& x, const int& y, const COLOR& color);
    bool print(const std::string& str, const int& x, const int& y, const COLOR& color);
    bool print(const char& ch, const int& x, const int& y, const COLOR& color);
    void printBorder(const int& x_size, const int& y_size);
    void printBorder();
    void getSize(int& x, int& y);
    void drawObjects();
    void printGameOver();
    void printPlayerWin();
    void printScore();
};
