#ifndef CLIENT_H
#define CLIENT_H

#include "../network/socket.h"
#include <string>

class Client {
public:
    Client(const std::string& server_ip, const std::string& server_port);
    bool connect_to_server();
    bool send_message(const std::string& message); // Залишити
    std::string receive_message(); // Залишити
    void close_connection();

private:
    std::string server_ip;
    int server_port;
    Socket client_socket;
};

#endif // CLIENT_H
