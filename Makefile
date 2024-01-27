CXX = g++

UNAME := $(shell uname)
ifeq ($(UNAME),Linux)
    CXXFLAGS = -I./include/linux -I./include/shared -DSFML_STATIC
    LDFLAGS = -L./lib/linux
    LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lfreetype
else
    CXXFLAGS = -I./include/windows -I./include/shared -DSFML_STATIC
    LDFLAGS = -L./lib/windows
    LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32
endif

all: compile link run

compile:
	$(CXX) -c ./src/main.cpp $(CXXFLAGS) -o ./out/main.o
	$(CXX) -c ./src/engine/functions.cpp $(CXXFLAGS) -o ./out/functions.o

link:
	$(CXX) ./out/main.o ./out/functions.o -o ./out/main $(LDFLAGS) $(LIBS)

run:
	./out/main

clean:
	rm -f ./out/main ./out/*.o
