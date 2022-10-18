CC = g++ -std=c++17 -g

all: Main

Main: Main.cpp
	$(CC) Main.cpp -o Main

#UI: UI.cpp
#	$(CC) UI.cpp -o UI

#IS: IS.cpp
#	$(CC) IS.cpp -o IS


clean:
	rm -f main