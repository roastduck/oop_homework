ifeq ($(DEBUG), true)
	CPPFLAG = -std=c++11 -g -Wall
else
	CPPFLAG = -std=c++11 -O2 -DNDEBUG
endif

main : main.o kmp.o rk.o
	g++ $^ -o $@ $(CPPFLAG)

main.o : main.cpp patternmatch.h kmp.h rk.h
	g++ main.cpp -c $(CPPFLAG)

kmp.o : kmp.cpp patternmatch.h kmp.h
	g++ kmp.cpp -c $(CPPFLAG)

rk.o : rk.cpp patternmatch.h rk.h
	g++ rk.cpp -c $(CPPFLAG)

clean :
	-rm main *.o *.gch

.PHONY : clean
