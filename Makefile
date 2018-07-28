CFLAGS = -g -Wall -std=c++11 -I.
LDFLAGS = -lncurses

SRC = \
	Field.cpp \
	InputKeep.cpp \
	Player.cpp \
	Screen.cpp \
	GameObject.cpp \
	UserInput.cpp \
	Window.cpp \
	GameSystem.cpp \
	Bullet.cpp \
	Enemy.cpp \
	main.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY:
	clean

main: $(OBJ)
	g++ $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -rf main *.o *.orig
