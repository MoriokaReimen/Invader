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
	GameStatus.cpp \
	Logic.cpp \
	main.cpp
OBJ = $(SRC:.cpp=.o)


main: $(OBJ)
	g++ $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

.PHONY: clean astyle

clean:
	rm -rf main *.o *.orig

astyle:
	astyle *.hpp *.cpp

doxygen:
	doxygen doxygen.config .
