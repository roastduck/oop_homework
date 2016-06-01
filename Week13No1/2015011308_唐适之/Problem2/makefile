ifeq ($(DEBUG), true)
	PARAM = -g -Wall -std=c++11
else
	PARAM = -O2 -DNDEBUG -std=c++11
endif

main : main.o KMP.a PrivateInheritanceMatch.o Force.o
	g++ $^ -o $@ $(PARAM)

main.o : main.cpp Force.h KMP.h PrivateInheritanceMatch.h Timer.h
	g++ main.cpp -c $(PARAM)

PrivateInheritanceMatch.o : PrivateInheritanceMatch.cpp PrivateInheritanceMatch.h KMP.h
	g++ PrivateInheritanceMatch.cpp -c $(PARAM)

Force.o : Force.cpp Force.h
	g++ Force.cpp -c $(PARAM)

clean :
	@del *.o *.gch main *.txt

.PHONY : clean
