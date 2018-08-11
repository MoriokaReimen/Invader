/*!
 * \file main.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief main関数の実装
 */
#include<Window.hpp>
#include<Screen.hpp>
#include<UserInput.hpp>
#include<GameSystem.hpp>
#include<Logic.hpp>

#include<unistd.h>

const int DELAY(100);
const int MAX_X(70);
const int MAX_Y(50);

int main(int argc, char *argv[])
{
    GameSystem::init();
    Window win;
    Screen screen(win);
    UserInput input(win);
    Logic logic;

    GameStatus* status = GameSystem::getStatus();

    while (1) {
        input.store();
        logic.update();

        screen.update();

        usleep(DELAY);

        if(status->isGameEnd()) break;
    }

    GameSystem::cleanup();

    return 0;
}
