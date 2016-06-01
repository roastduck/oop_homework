ifeq ($(DEBUG), true)
	PARAM = -g -Wall -std=c++11 -I.
else
	PARAM = -O2 -DNDEBUG -std=c++11 -I.
endif

main : main.o MyKMP.o KMPBase.o KMPQuery.o
	g++ $^ -o $@ $(PARAM)

main.o : main.cpp MyKMP.h KMPBase.h KMPQuery.h
	g++ main.cpp -c $(PARAM)

MyKMP.o : MyKMP.cpp MyKMP.h
	g++ MyKMP.cpp -c $(PARAM)

KMPBase.o : KMPBase.cpp MyKMP.h KMPBase.h
	g++ KMPBase.cpp -c $(PARAM)

KMPQuery.o : KMPQuery.cpp MyKMP.h KMPBase.h KMPQuery.h
	g++ KMPQuery.cpp -c $(PARAM)

clean :
	@del *.o *.gch main

.PHONY : clean
