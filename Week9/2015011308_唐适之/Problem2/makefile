ifeq (DEBUG, true)
	CPPFLAG = -g -Wall
else
	CPPFLAG = -O2 -DNDEBUG
endif

main.exe : main.cpp
	g++ main.cpp -o main $(CPPFLAG)

clean :
	-del main.exe *.o *.gch

.PHONY : clean
