ifeq ($(DEBUG), true)
	PARAM = -g -Wall
else
	PARAM = -O2
endif

main : posynomial.o polynomial.o measure.h func.h main.cpp
	g++ $^ -o $@ $(PARAM)

polynomial.o : polynomial.cpp
	g++ $^ -c $(PARAM)

posynomial.o : posynomial.cpp
	g++ $^ -c $(PARAM)

clean :
	rm posynomial.o polynomial.o main
