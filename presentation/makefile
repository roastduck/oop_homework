all : pthread c11thread omp ompfor

pthread : pthread.cpp
	g++ pthread.cpp -o pthread -pthread -Wall

c11thread : c11thread.cpp
	g++ c11thread.cpp -o c11thread -std=c++11 -pthread -Wall

omp : omp.cpp
	g++ omp.cpp -o omp -fopenmp -Wall

ompfor : ompfor.cpp
	g++ ompfor.cpp -o ompfor -fopenmp -Wall

clean :
	rm pthread c11thread omp ompfor
