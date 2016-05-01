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
TARGET=maze.exe
LIB=maze.a

all: $(TARGET) $(LIB)
	
$(TARGET): $(sOBJECTS) $(HEADERS) $(LIB)
	@echo "Now Generating $(TARGET) ..."
	g++ $(sOBJECTS) $(LIB) -o $(TARGET) $(CPPFLAG)
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
	del *.o *.exe *.bak *.a *.gch
explain:
	@echo "Lib Sources: $(lSOURCES)"
	@echo "User Sources: $(sSOURCES)"
	@echo "Lib Objects: $(lOBJECTS)"
	@echo "User Objects: $(sOBJECTS)"
	@echo "Lib: $(LIB)"
	@echo "Target: $(TARGET)"

install : a b
	

a : a.makefile BaseRouter.cxx BaseRouter.h main.cpp OptRouter.cpp OptRouter.h
	-del /Q ..\\a\\*
	copy BaseRouter.cxx ..\\a
	copy BaseRouter.h ..\\a
	copy main.cpp ..\\a
	copy OptRouter.cpp ..\\a
	copy OptRouter.h ..\\a
	copy a.makefile ..\\a\\makefile

b : b.makefile BaseRouter.h main.cpp OptRouter.cpp OptRouter.h maze.a
	-del /Q ..\\b\\*
	copy BaseRouter.h ..\\b
	copy main.cpp ..\\b
	copy OptRouter.cpp ..\\b
	copy OptRouter.h ..\\b
	copy b.makefile ..\\b\\makefile
	copy maze.a ..\\b

cleanall : clean
	-make -C ..\\a clean
	-make -C ..\\b clean

.PHONY: a b all clean install cleanall
