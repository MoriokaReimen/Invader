CFLAGS = -g -Wall
LDFLAGS = -lncurses

.PHONY: clean

main: main.o Screen.o
	g++ main.o Screen.o -o main $(LDFLAGS)

main.o: main.cpp
	g++ -c -I. $(CFLAGS) main.cpp -o main.o $(LDFLAGS)

Screen.o: Screen.cpp
	g++ -c -I. $(CFLAGS) Screen.cpp -o Screen.o $(LDFLAGS)

clean:
	rm -rf main *.o
