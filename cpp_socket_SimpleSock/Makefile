# Компилятор та флаги
CC = g++
CFLAGS = -std=c++17 -Wall

# Папки
SRC_DIR = src
CLIENT_DIR = $(SRC_DIR)/client
SERVER_DIR = $(SRC_DIR)/server
NETWORK_DIR = $(SRC_DIR)/network

# Виконавчі файли
CLIENT_EXEC = runClient
SERVER_EXEC = runServer

# Джерела
CLIENT_SOURCES = $(CLIENT_DIR)/runClient.cpp $(CLIENT_DIR)/client.cpp
SERVER_SOURCES = $(SERVER_DIR)/runServer.cpp $(SERVER_DIR)/server.cpp
NETWORK_SOURCES = $(NETWORK_DIR)/NetworkValidator.cpp $(NETWORK_DIR)/socket.cpp

# Об'єктні файли
OBJECTS = $(CLIENT_SOURCES:.cpp=.o) $(SERVER_SOURCES:.cpp=.o) $(NETWORK_SOURCES:.cpp=.o)

# Цілі за замовчуванням
all: $(CLIENT_EXEC) $(SERVER_EXEC)

# Компіляція клієнта
$(CLIENT_EXEC): $(CLIENT_SOURCES:.cpp=.o) $(NETWORK_SOURCES:.cpp=.o)
	$(CC) $(CFLAGS) -o $@ $^

# Компіляція сервера
$(SERVER_EXEC): $(SERVER_SOURCES:.cpp=.o) $(NETWORK_SOURCES:.cpp=.o)
	$(CC) $(CFLAGS) -o $@ $^

# Правило для створення об'єктних файлів
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Очищення об'єктних та виконуваних файлів
clean:
	rm -f $(OBJECTS) $(CLIENT_EXEC) $(SERVER_EXEC)

# Перезапуск
restart: clean all

.PHONY: all clean restart
