ifeq ($(DEBUG), true)
	PARAM = -g -Wall
else
	PARAM = -O2 -DNDEBUG
endif

main : main.cpp graph.o graph.h mst.o mst.h
	g++ $^ -o $@ $(PARAM) -std=c++11

mst.o : mst.cpp graph.h mst.h dsu.h
	g++ $^ -c $(PARAM) -std=c++11

graph.o : graph.cpp graph.h
	g++ $^ -c $(PARAM) -std=c++11


test : test.cpp graph.cpp mst.cpp graph.h mst.h dsu.h
	g++ $^ -o $@ -std=c++11 -Wall -g

clean :
	rm *.o *.gch main test
