all: main genrand

CXXFLAGS = -g -O3 -std=c++17

main: main.cpp readdata.cpp readsched.cpp sim.cpp world.h
	g++ $(CXXFLAGS) -o main main.cpp readdata.cpp readsched.cpp sim.cpp

genrand: genrand.cpp readdata.cpp world.h
	g++ $(CXXFLAGS) -o genrand genrand.cpp readdata.cpp

clean:
	rm -f main genrand
