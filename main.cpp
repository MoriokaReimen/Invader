#include <Window.hpp>
#include <Screen.hpp>
#include <UserInput.hpp>

#include<algorithm>

#include<unistd.h>

const int DELAY(15000);
const int MAX_X(70);
const int MAX_Y(50);

int main(int argc, char *argv[])
{
    Window win;
    int x = 1,
        y = 1;
    int max_x, max_y;
    char ch = 'p';
    Screen screen(win);
    UserInput input(win);

    while (1) {
        ch = input.get();
        screen.getSize(max_x, max_y);
        switch(ch) {
        case 'k':
            y--;
            break;
        case 'h':
            x--;
            break;
        case 'j':
            y++;
            break;
        case 'l':
            x++;
            break;
        default:
            break;
        }
        y = std::max(1, std::min(y, MAX_Y));
        x = std::max(1, std::min(x, MAX_X));
        screen.clear();
        screen.print('@', x, y);
        screen.printBorder(100, 50);
        screen.update();

        usleep(DELAY);

        if(ch == 'q') break;

    }

    return 0;
}
