flags = -Wall -g -std=c++14

all: chen_p2

run: chen_p2
	./chen_p2 LLLL 10101010

chen_p2: chen_p2.o
	g++ $(flags) chen_p2.o -o chen_p2

chen_p2.o: chen_p2.cpp
	g++ -c $(flags) chen_p2.cpp -o chen_p2.o

clean:
	rm *.o chen_p2
