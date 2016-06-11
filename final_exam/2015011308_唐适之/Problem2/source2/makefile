sSOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
TARGET=kdtree.exe

all: $(TARGET)
$(TARGET): $(sOBJECTS) $(HEADERS)
#	@echo "Now Generating $(TARGET) ..."
	g++ $(sOBJECTS) -o $(TARGET) -std=c++11 -Wall
%.o: %.cpp $(HEADERS)
#	@echo "Now Compiling $< ..."
	g++ -I. -c -g $< -o $@ -std=c++11 -Wall
clean:
	#del *.o *.exe *.bak
	rm *.o *.exe *.bak
explain:
	@echo "Headers: $(HEADERS)"
	@echo "User Sources: $(sSOURCES)"
	@echo "User Objects: $(sOBJECTS)"
	@echo "Target: $(TARGET)"
