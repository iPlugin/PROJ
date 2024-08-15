# ============= Makefile ============= #

# [ Configuration variables ]
CXX = g++ # Компілятор
CXXFLAGS = -std=c++17 -pthread -Iinclude # Прапори компілятора
LDFLAGS = -lcurl # Прапори бібліотек

# Folders
DIROBJS = obj
DIRLOGS = log

# Компіляція liboai файлів
LIBOAI_OBJS = $(DIROBJS)/chat.o \
              $(DIROBJS)/authorization.o \
              $(DIROBJS)/netimpl.o \
              $(DIROBJS)/response.o

# [ Compilation rules ]
$(shell mkdir -p $(DIROBJS) $(DIRLOGS))

all: runServer runClient

runServer: server/runServer.cpp $(DIROBJS)/server.o $(LIBOAI_OBJS) logger process
	$(CXX) $(CXXFLAGS) server/runServer.cpp \
		$(DIROBJS)/server.o $(DIROBJS)/logger.o \
		$(DIROBJS)/process.o \
		$(LIBOAI_OBJS) $(LDFLAGS) -o runServer

runClient: client/runClient.cpp $(DIROBJS)/client.o
	$(CXX) $(CXXFLAGS) client/runClient.cpp \
		$(DIROBJS)/client.o \
		-o runClient

logger: src/logger/logger.cpp
	$(CXX) $(CXXFLAGS) -c src/logger/logger.cpp \
		-o $(DIROBJS)/logger.o

process: src/process/process.cpp
	$(CXX) $(CXXFLAGS) -c src/process/process.cpp \
		-o $(DIROBJS)/process.o

$(DIROBJS)/server.o: server/server.cpp
	$(CXX) $(CXXFLAGS) -c server/server.cpp \
		-o $(DIROBJS)/server.o

$(DIROBJS)/client.o: client/client.cpp
	$(CXX) $(CXXFLAGS) -c client/client.cpp \
		-o $(DIROBJS)/client.o


$(DIROBJS)/chat.o: src/liboai/components/chat.cpp
	$(CXX) $(CXXFLAGS) -c src/liboai/components/chat.cpp \
		-o $(DIROBJS)/chat.o

$(DIROBJS)/authorization.o: src/liboai/core/authorization.cpp
	$(CXX) $(CXXFLAGS) -c src/liboai/core/authorization.cpp \
		-o $(DIROBJS)/authorization.o

$(DIROBJS)/netimpl.o: src/liboai/core/netimpl.cpp
	$(CXX) $(CXXFLAGS) -c src/liboai/core/netimpl.cpp \
		-o $(DIROBJS)/netimpl.o

$(DIROBJS)/response.o: src/liboai/core/response.cpp
	$(CXX) $(CXXFLAGS) -c src/liboai/core/response.cpp \
		-o $(DIROBJS)/response.o



clean:
	rm -f runServer runClient
	if [ -d $(DIROBJS) ]; then rm -r $(DIROBJS); fi