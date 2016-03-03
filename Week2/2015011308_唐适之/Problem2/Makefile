ifeq ($(DEBUG), true)
	PARAM = -g -Wall
else
	PARAM = -O2
endif

main : main.cpp reviewer_assigner.h reviewer_assigner.o team_assigner.h team_assigner.o loader.o
	g++ $^ -o $@ $(PARAM)

reviewer_assigner.o : reviewer_assigner.h reviewer_assigner.cpp loader.h const.h
	g++ $^ -c $(PARAM)

team_assigner.o : team_assigner.h team_assigner.cpp loader.h const.h
	g++ $^ -c $(PARAM)

loader.o : loader.h loader.cpp
	g++ $^ -c $(PARAM)

clean :
	rm *.o *.gch main
