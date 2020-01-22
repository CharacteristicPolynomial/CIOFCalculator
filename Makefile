all: gen compute estimate hyper

gen: genLambda.cpp list.h config.h
	g++ genLambda.cpp -o gen

compute: compute.cpp list.h config.h compute.h
	g++ compute.cpp -o compute -lgmp -pthread

estimate: estimate.cpp list.h config.h
	g++ estimate.cpp -o estimate

hyper: hyper.cpp list.h config.h
	g++ hyper.cpp -o hyper

clean:
	rm compute estimate gen hyper