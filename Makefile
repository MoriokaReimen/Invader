CFLAGS = -g -Wall
LDFLAGS = -lncurses

.PHONY: clean

all:
	g++ $(CFLAGS) main.cpp -o main $(LDFLAGS)

clean:
	rm -rf main
