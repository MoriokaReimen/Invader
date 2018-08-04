/*!
 * \file Window.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Windowクラスの宣言
 */
#pragma once

typedef struct _win_st WINDOW;

/*!
 * \class Window
 * \brief cursesのwindowポインタ保持クラス
 */
class Window
{
    WINDOW* win_;
    Window& operator=(const Window& other);
    Window(const Window& other);
public:
    Window();
    ~Window();
    WINDOW* get_raw() const;
};
