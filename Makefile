CFLAGS = -g -Wall -std=c++11 -I.
LDFLAGS = -lncurses

SRC = \
	GameField.cpp \
	InputKeep.cpp \
	Player.cpp \
	Enemy.cpp \
	Screen.cpp \
	GameObject.cpp \
	UserInput.cpp \
	Window.cpp \
	GameSystem.cpp \
	Bullet.cpp \
	Bomb.cpp \
	GameStatus.cpp \
	Logic.cpp \
	main.cpp
OBJ = $(SRC:.cpp=.o)

main: $(OBJ)
	g++ $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

.PHONY: clean astyle

GameObject.o: GameObject.cpp
	g++ -c -I. $(CFLAGS) GameObject.cpp -o GameObject.o $(LDFLAGS)

clean:
	rm -rf main *.o *.orig

astyle:
	astyle *.hpp *.cpp

doxygen:
	doxygen doxygen.config .
