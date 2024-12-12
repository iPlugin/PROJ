#ifndef SERVER_H
#define SERVER_H

#include "../network/socket.h"
#include <string>

class Server {
public:
    Server(std::string port);
    bool start();
    void stop();

private:
    int port;
    Socket server_socket;

    void handle_client(Socket& client_socket);
};

#endif // SERVER_H
