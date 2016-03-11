ifeq ($(DEBUG), true)
	PARAM = -g -Wall
else
	PARAM = -O2
endif

main : class.h class.o main.cpp
	g++ $^ -o $@ $(PARAM)

class.o : class.h class.cpp
	g++ $^ -c $(PARAM)

clean :
	rm *.o *.gch main 
