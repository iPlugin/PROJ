
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./libraries/inih
LDFLAGS = -lpqxx -lpq

OBJ = build/main.o build/numbooker.o build/INIReader.o build/ini.o build/postgresdb.o

TARGET = project

all: build $(TARGET)

build:
	mkdir -p build

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

build/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

build/numbooker.o: src/numbooker.cpp src/numbooker.h
	$(CXX) $(CXXFLAGS) -c src/numbooker.cpp -o build/numbooker.o

build/postgresdb.o: src/postgresdb.cpp src/postgresdb.h
	$(CXX) $(CXXFLAGS) -c src/postgresdb.cpp -o build/postgresdb.o

build/INIReader.o: libraries/inih/INIReader.cpp libraries/inih/INIReader.h
	$(CXX) $(CXXFLAGS) -c libraries/inih/INIReader.cpp -o build/INIReader.o

build/ini.o: libraries/inih/ini.c libraries/inih/ini.h
	$(CXX) $(CXXFLAGS) -c libraries/inih/ini.c -o build/ini.o


restart: clean all

clean:
	rm -rf build $(TARGET)
