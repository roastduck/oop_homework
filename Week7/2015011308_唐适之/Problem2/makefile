ifeq ($(DEBUG), true)
	PARAM = -g -Wall
else
	PARAM = -O2 -DNDEBUG
endif

main : Matrix.o main.o
	g++ $^ -o $@ $(PARAM) -std=c++11

main.o : main.cpp Matrix.h
	g++ $^ -c $(PARAM) -std=c++11

Matrix.o : Matrix.cpp Matrix.h
	g++ $^ -c $(PARAM) -std=c++11


clean :
	@$(RM) *.o *.gch main
