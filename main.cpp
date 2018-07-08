#include <Screen.hpp>

#include<unistd.h>

const int DELAY(35000);

int main(int argc, char *argv[]) {
    Window win;
  int x = 0,
      y = 0;
  int max_x, max_y;
  int direction = 1;
  int next_x = x;
  Screen screen(win);

  while (1) {
    screen.getSize(max_x, max_y);
    y = max_y / 2;
    screen.clear();
    screen.print("p", x, y);
    screen.update();

    usleep(DELAY);

    next_x = x + direction;

    if (next_x >= max_x || next_x < 0) {
      direction*= -1;
    } else {
      x+= direction;
    }

  }

  return 0;
}
