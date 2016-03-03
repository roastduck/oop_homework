main : posynomial.o polynomial.o func.h main.cpp
	g++ $^ -o $@ -O2

polynomial.o : polynomial.cpp
	g++ $^ -c -O2

posynomial.o : posynomial.cpp
	g++ $^ -c -O2

clean :
	rm posynomial.o polynomial.o main
