#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <iostream>
#include <charconv>
#include <unistd.h>

#include "../socket/socketStream.h"
#include "../logger/logger.h"


class Server {
private:
    SocketStream sock_steam;
    Logger logger;

    int connect_port;
    
    int server_fd;
    int client_fd;

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

public:
    Server(const std::string tmp_port, const std::string &logFilePath);
    ~Server();

    bool run();
};


#endif // SERVER_H