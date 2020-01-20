test: test.cpp
	g++ test.cpp -o test -lgmp

clean:
	rm out test