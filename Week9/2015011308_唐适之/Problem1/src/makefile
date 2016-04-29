ifeq ($(DEBUG),)
	DEBUG = false
endif

all : a b
	
a : a.makefile BaseRouter.cxx BaseRouter.h main.cpp OptRouter.cxx OptRouter.h
	-del /Q ..\\a\\*
	copy BaseRouter.cxx ..\\a
	copy BaseRouter.h ..\\a
	copy main.cpp ..\\a
	copy OptRouter.cxx ..\\a
	copy OptRouter.h ..\\a
	copy a.makefile ..\\a\\makefile
	make -C ..\\a DEBUG=$(DEBUG)

b : b.makefile BaseRouter.h main.cpp OptRouter.cxx OptRouter.h
	-del /Q ..\\b\\*
	copy BaseRouter.h ..\\b
	copy main.cpp ..\\b
	copy OptRouter.cxx ..\\b
	copy OptRouter.h ..\\b
	copy b.makefile ..\\b\\makefile
	make -C ..\\b DEBUG=$(DEBUG)

clean :
	-make -C ..\\a clean
	-make -C ..\\b clean

.PHONY: a b all clean
