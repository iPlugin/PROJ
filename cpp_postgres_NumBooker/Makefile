# ============= Makefile ============= #

TARGET = project

# Folders
BUILD_DIR = build
SRC_DIR = src
# INCLUDE_DIR = include

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET):
	$(CXX) $(CXXFLAGS) main.cpp -o project


restart: clean all

clean:
	rm -rf $(BUILD_DIR) $(TARGET)