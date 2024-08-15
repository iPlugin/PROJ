#ifndef SOCKETSTREAM_H
#define SOCKETSTREAM_H

#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>

#include "../package/package.h"

#define SUCCESS(number) ((number) != -1)


class SocketStream {
private:
    // struct sockaddr_in address;
public:
    SocketStream();
    ~SocketStream();

    int getSocket();
    int getBind(int socket_fd, int port, sockaddr_in &addr); // for server
    int getConnect(int socket_fd, std::string ip, int port, sockaddr_in &addr); // for client
    int getListen(int socket_fd);
    int getAccept(int socket_fd, sockaddr_in &client_addr);

    Package recvPkg(int socket_fd);
    Package sendPkg(int socket_fd, std::string message);
};

#endif // SOCKETSTREAM_H