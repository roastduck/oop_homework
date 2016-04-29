ifeq ($(DEBUG), true)
	CPPFLAG = -std=c++11 -g -Wall
else
	CPPFLAG = -std=c++11 -O2 -DNDEBUG
endif

lSOURCES=$(wildcard *.cxx)
sSOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
lOBJECTS=$(lSOURCES:%.cxx=%.o)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
LIB=maze.a

all: $(TARGET) $(LIB)
$(LIB): $(lOBJECTS) $(HEADERS)
	@echo "Now Generating $(LIB) ..."
	ar -rv $(LIB) $(lOBJECTS)
	ranlib $(LIB)
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -c $< -o $@ $(CPPFLAG)
%.o: %.cxx $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -c $< -o $@ $(CPPFLAG)
clean:
	del *.o *.exe *.bak *.gch
explain:
	@echo "Lib Sources: $(lSOURCES)"
	@echo "User Sources: $(sSOURCES)"
	@echo "Lib Objects: $(lOBJECTS)"
	@echo "User Objects: $(sOBJECTS)"
	@echo "Lib: $(LIB)"
	@echo "Target: $(TARGET)"
