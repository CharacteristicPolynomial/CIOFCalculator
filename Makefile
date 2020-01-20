test: test.cpp list.h config.h compute.h
	g++ test.cpp -o test -lgmp -pthread

minimal: minimal.cpp
	g++ minimal.cpp -std=c++11 -I/usr/include/python2.7 -lpython2.7

clean:
	rm out test minimal a.out