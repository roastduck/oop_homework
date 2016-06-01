ifeq ($(DEBUG), true)
	PARAM = -g -Wall -std=c++11
else
	PARAM = -O2 -DNDEBUG -std=c++11
endif

main : main.o KMP.a KMPProxy.o MyKMP.o MyKMPProxy.o
	g++ $^ -o $@ $(PARAM)

main.o : main.cpp MyKMP.h KMP.h KMPProxy.h Timer.h
	g++ main.cpp -c $(PARAM)

KMPProxy.o : KMPProxy.cpp KMPProxy.h KMP.h
	g++ KMPProxy.cpp -c $(PARAM)

MyKMP.o : MyKMP.cpp MyKMP.h
	g++ MyKMP.cpp -c $(PARAM)

MyKMPProxy.o : MyKMPProxy.cpp MyKMPProxy.h MyKMP.h
	g++ MyKMPProxy.cpp -c $(PARAM)

clean :
	@del *.o *.gch main *.txt

.PHONY : clean
