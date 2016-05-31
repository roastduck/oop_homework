sSOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
TARGET=match.exe
LIB=KMP.a

all: $(TARGET) $(LIB)

$(TARGET): $(sOBJECTS) $(HEADERS) $(LIB)
	g++ $(sOBJECTS) $(LIB) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	g++ -I. -c $< -o $@

clean:
	del *.o *.exe *.bak *.gch
