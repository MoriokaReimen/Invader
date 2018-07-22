#include <Window.hpp>
#include <Screen.hpp>
#include <UserInput.hpp>
#include<GameSystem.hpp>

#include<algorithm>

#include<unistd.h>

const int DELAY(15000);
const int MAX_X(70);
const int MAX_Y(50);

int main(int argc, char *argv[])
{
    Window win;
    char ch = 'p';
    Screen screen(win);
    UserInput input(win);
    GameSystem::init();
    Field* field = GameSystem::getField();
    InputKeep* keep = GameSystem::getInputKeep();

    while (1) {
        ch = input.store();
        field->update();

        screen.clear();
        screen.printBorder(100, 50);
        screen.drawObjects();
        screen.update();
        keep->clear();

        usleep(DELAY);

        if(ch == 'q') break;

    }

    GameSystem::cleanup();

    return 0;
}
