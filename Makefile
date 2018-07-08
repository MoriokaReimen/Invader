CFLAGS = -g -Wall
LDFLAGS = -lncurses

.PHONY: clean

main: main.o Screen.o Window.o
	g++ main.o Screen.o Window.o -o main $(LDFLAGS)

main.o: main.cpp
	g++ -c -I. $(CFLAGS) main.cpp -o main.o $(LDFLAGS)

Screen.o: Screen.cpp
	g++ -c -I. $(CFLAGS) Screen.cpp -o Screen.o $(LDFLAGS)

Window.o: Window.cpp
	g++ -c -I. $(CFLAGS) Window.cpp -o Window.o $(LDFLAGS)

clean:
	rm -rf main *.o
