ifeq ($(DEBUG), true)
	PARAM = -g -Wall
else
	PARAM = -O2
endif

main : hen.h hen.o egg.h egg.o main.cpp
	g++ $^ -o $@ $(PARAM)

hen.o : hen.h hen.cpp egg.h
	g++ $^ -c $(PARAM)

egg.o : egg.h egg.cpp
	g++ $^ -c $(PARAM)

clean :
	rm *.o *.gch main 
