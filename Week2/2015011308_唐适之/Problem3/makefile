ifeq ($(DEBUG), true)
	PARAM = -g -Wall
else
	PARAM = -O2
endif

main : video.h video.o main.cpp
	g++ $^ -o $@ -std=c++11 $(PARAM)

video.o : video.h video.cpp
	g++ $^ -c -std=c++11 $(PARAM)

clean :
	rm *.o *.gch main 
