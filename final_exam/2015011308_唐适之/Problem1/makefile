SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
OBJECTS=$(SOURCES:%.cpp=%.o)
TARGET=test.exe

all: $(TARGET)
$(TARGET): $(OBJECTS) $(HEADERS)
#	@echo "Now Generating $(TARGET) ..."
	g++ $(OBJECTS) $(LIB) -o $(TARGET) -std=c++11 -Wall
%.o: %.cpp $(HEADERS)
#	@echo "Now Compiling $< ..."
	g++ -I. -c $< -o $@ -std=c++11 -Wall
clean:
	rm *.o *.exe *.bak
	#del *.o *.exe *.bak
explain:
	@echo "Headers: $(HEADERS)"
	@echo "Sources: $(SOURCES)"
	@echo "Objects: $(OBJECTS)"
	@echo "Target: $(TARGET)"
