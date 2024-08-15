#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <sstream> // для нарізання по слову

#include "../include/liboai/liboai.h"
#include "../include/process/process.h"
#include "../include/logger/logger.h"

struct Message {
    int status;
    std::string data;
};

class Server
{
private:
    Logger logger;

    int server_fd;
    std::string server_ip = "127.0.0.1";
    int server_port = 2001;
    std::string OPENAI_API_KEY = "OPENAI_API_KEY";
    struct sockaddr_in server_addr;

    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;

    bool bindServer();
    bool listenServer();
    bool acceptServer();

    bool sendMessage(const std::string message);
    Message recvMessage();

    void command_recognition(std::string recv_str);

    std::string chatgpt(std::string message);

public:
    Server(const std::string &logFilePath);
    ~Server();
    
    bool run();
//   |-> bool bindServer();
//   |-> bool listenServer();
//   |-> bool acceptServer();
//        |-> bool sendMessage();
//        |-> bool recvMessage();
//             |-> void command_recognition();
};

#endif // SERVER_H
