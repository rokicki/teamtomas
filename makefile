all: main genrand

main: main.cpp readdata.cpp world.h
	g++ -O3 -std=c++17 -o main main.cpp readdata.cpp readsched.cpp

genrand: genrand.cpp readdata.cpp world.h
	g++ -O3 -std=c++17 -o genrand genrand.cpp readdata.cpp
