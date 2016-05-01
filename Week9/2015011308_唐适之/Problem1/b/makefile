ifeq ($(DEBUG), true)
	CPPFLAG = -std=c++11 -g -Wall
else
	CPPFLAG = -std=c++11 -O2 -DNDEBUG
endif

sSOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
TARGET=maze.exe
LIB=maze.a

all: $(TARGET) $(LIB)
$(TARGET): $(sOBJECTS) $(HEADERS) $(LIB)
	@echo "Now Generating $(TARGET) ..."
	g++ $(sOBJECTS) $(LIB) -o $(TARGET) $(CPPFLAG)
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -c $< -o $@ $(CPPFLAG)
clean:
	del *.o *.exe *.bak *.gch
explain:
	@echo "Lib Sources: $(lSOURCES)"
	@echo "User Sources: $(sSOURCES)"
	@echo "User Objects: $(sOBJECTS)"
	@echo "Lib: $(LIB)"
	@echo "Target: $(TARGET)"
