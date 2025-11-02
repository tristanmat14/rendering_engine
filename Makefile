# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++17 -Iinclude
CC := gcc
CFLAGS := -Iinclude

# Linking flags
LDFLAGS := -Llib -Llib/GLFW -lglfw3 -lGL -lX11 -lXrandr -lpthread -ldl

# Source Files
SRC_CXX := src/main.cpp
SRC_C := src/glad.c

# Object Files
OBJ_CXX := $(SRC_CXX:src/%.cpp=build/%.o)
OBJ_C := $(SRC_C:src/%.c=build/%.o)

OBJS := $(OBJ_CXX) $(OBJ_C)

TARGET := build/app.exe

# Build rules
all: create_build_dir $(TARGET)

# Create build dir before compilation
create_build_dir:
	mkdir -p build

# Rule for linking object files together into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to compile C++ source files to object files
build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile C source files to object files
build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean: 
	rm -rf build

