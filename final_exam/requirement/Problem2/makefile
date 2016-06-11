sSOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
TARGET=kdtree.exe

all: $(TARGET)
$(TARGET): $(sOBJECTS) $(HEADERS)
	@echo "Now Generating $(TARGET) ..."
	g++ $(sOBJECTS) -o $(TARGET)
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -I. -c -g $< -o $@
clean:
	#del *.o *.exe *.bak
	rm *.o *.exe *.bak
explain:
	@echo "Headers: $(HEADERS)"
	@echo "User Sources: $(sSOURCES)"
	@echo "User Objects: $(sOBJECTS)"
	@echo "Target: $(TARGET)"
