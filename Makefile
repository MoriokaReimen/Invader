CFLAGS = -g -Wall
LDFLAGS = -lncurses

.PHONY:
	clean

main: main.o Screen.o Window.o UserInput.o InputKeep.o GameSystem.o Field.o GameObject.o
	g++ main.o Screen.o Window.o UserInput.o -o main $(LDFLAGS)

main.o: main.cpp
	g++ -c -I. $(CFLAGS) main.cpp -o main.o $(LDFLAGS)

Screen.o: Screen.cpp
	g++ -c -I. $(CFLAGS) Screen.cpp -o Screen.o $(LDFLAGS)

Window.o: Window.cpp
	g++ -c -I. $(CFLAGS) Window.cpp -o Window.o $(LDFLAGS)

UserInput.o: UserInput.cpp
	g++ -c -I. $(CFLAGS) UserInput.cpp -o UserInput.o $(LDFLAGS)

GameSystem.o: GameSystem.cpp
	g++ -c -I. $(CFLAGS) GameSystem.cpp -o GameSystem.o $(LDFLAGS)

InputKeep.o: InputKeep.cpp
	g++ -c -I. $(CFLAGS) InputKeep.cpp -o InputKeep.o $(LDFLAGS)

Field.o: Field.cpp
	g++ -c -I. $(CFLAGS) Field.cpp -o Field.o $(LDFLAGS)

GameObject.o: GameObject.cpp
	g++ -c -I. $(CFLAGS) GameObject.cpp -o GameObject.o $(LDFLAGS)

clean:
	rm -rf main *.o
