# ============= Makefile ============= #

TARGET = project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I$(LIB_DIR)

# Folders
BUILD_DIR = build


all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): src/main.cpp
	$(CXX) $(CXXFLAGS)
	src/main.cpp
	
	-o $(TARGET)



restart: clean all

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
