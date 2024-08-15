#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include <charconv>
#include <unistd.h>

#include "../socket/socketStream.h"
#include "../logger/logger.h"


class Client {
private:
    SocketStream sock_steam;
    Logger logger;

    std::string connect_ip;
    int connect_port;

    int client_fd;

    struct sockaddr_in server_addr;

public:
    Client(const std::string ip, const std::string tmp_port, const std::string &logFilePath);
    ~Client();

    bool run();
};





#endif // CLIENT_H