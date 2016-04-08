ifeq ($(DEBUG), true)
	PARAM = -g -Wall
else
	PARAM = -O2 -DNDEBUG
endif

main : main.o member.o
	g++ $^ -o $@ $(PARAM) -std=c++11

main.o : main.cpp member.h
	g++ $^ -c $(PARAM) -std=c++11

member.o : member.cpp member.h
	g++ $^ -c $(PARAM) -std=c++11


clean :
	@$(RM) *.o *.gch main
