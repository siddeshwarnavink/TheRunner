CXX = g++
UNAME := $(shell uname)

ifeq ($(UNAME),Linux)
	CXXFLAGS = -I./include/linux -I./src -DSFML_STATIC
	LDFLAGS = -L./lib/linux
	LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lfreetype
else
	CXXFLAGS = -I./include/windows -I./src -DSFML_STATIC
	LDFLAGS = -L./lib/windows
	LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32
endif

SRC_DIR = ./src
OBJ_DIR = ./out
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
SUBDIRS := $(wildcard $(SRC_DIR)/*/)

ALL_SOURCES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(ALL_SOURCES))

all: clean compile link run

print-objects: $(OBJECTS)
	@echo "OBJECTS: $(OBJECTS)"

compile: $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

link: $(OBJECTS)
	$(CXX) $^ -o $(OBJ_DIR)/main $(LDFLAGS) $(LIBS)

run:
	./$(OBJ_DIR)/main


clean:
	find $(OBJ_DIR) -name '*.o' -exec rm -f {} +
	rm -f $(OBJ_DIR)/main

.PHONY: all