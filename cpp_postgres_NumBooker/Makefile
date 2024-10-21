# Визначення компілятора та параметрів компіляції
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./libraries/inih

# Визначення об'єктів
OBJ = build/main.o build/numbooker.o build/INIReader.o build/ini.o

# Визначення цільового виконуваного файлу
TARGET = project

# Правило за замовчуванням
all: build $(TARGET)

# Правило для створення каталогу build
build:
	mkdir -p build

# Правило для створення виконуваного файлу
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Правила для створення об'єктних файлів
build/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

build/numbooker.o: src/numbooker.cpp src/numbooker.h
	$(CXX) $(CXXFLAGS) -c src/numbooker.cpp -o build/numbooker.o

build/INIReader.o: libraries/inih/INIReader.cpp libraries/inih/INIReader.h
	$(CXX) $(CXXFLAGS) -c libraries/inih/INIReader.cpp -o build/INIReader.o

build/ini.o: libraries/inih/ini.c libraries/inih/ini.h
	$(CXX) $(CXXFLAGS) -c libraries/inih/ini.c -o build/ini.o

restart: clean all

clean:
	rm -rf build $(TARGET)
