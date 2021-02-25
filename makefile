all: main genrand genrandu main2

CXXFLAGS = -g -O3 -std=c++17

main: main.cpp readdata.cpp readsched.cpp sim.cpp world.h
	g++ $(CXXFLAGS) -o main main.cpp readdata.cpp readsched.cpp sim.cpp

main2: main2.cpp readdata.cpp sim2.cpp world.h writesched.cpp
	g++ $(CXXFLAGS) -o main2 main2.cpp readdata.cpp sim2.cpp writesched.cpp

genrand: genrand.cpp readdata.cpp world.h
	g++ $(CXXFLAGS) -o genrand genrand.cpp readdata.cpp

genrandu: genrandu.cpp readdata.cpp world.h
	g++ $(CXXFLAGS) -o genrandu genrandu.cpp readdata.cpp

clean:
	rm -f main genrand
