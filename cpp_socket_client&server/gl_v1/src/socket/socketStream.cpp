#include "../../include/socket/socketStream.h"


SocketStream::SocketStream(/* args */) {}

SocketStream::~SocketStream(){}

int SocketStream::getSocket() {
    return socket(AF_INET, SOCK_STREAM, 0);
}

int SocketStream::getBind(int socket_fd, int port, sockaddr_in &addr) {
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    return bind(socket_fd, (sockaddr*)&addr, sizeof(addr));
}

int SocketStream::getConnect(int socket_fd, std::string ip, int port, sockaddr_in &addr) {
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &addr.sin_addr.s_addr);
    return connect(socket_fd, (sockaddr*)&addr, sizeof(addr));
}

int SocketStream::getListen(int socket_fd) {
    return listen(socket_fd, 5);
}

int SocketStream::getAccept(int socket_fd, sockaddr_in &client_addr) {
    socklen_t client_addr_size = sizeof(client_addr);
    return accept(socket_fd, (sockaddr*)&client_addr, (socklen_t*)&client_addr_size);
}

Package SocketStream::recvPkg(int socket_fd) {
    Package pkg;
    ssize_t data = recv(socket_fd, &pkg, sizeof(Package), 0);

    if (data == -1) {
        pkg.status_pkg = Package::StatusPkg::ERROR;
        strcpy(pkg.data.error.msg, std::strerror(errno));
        return pkg;
    }
    else if (data == 0) {
        pkg.status_pkg = Package::StatusPkg::DISCONNECT;
        strcpy(pkg.data.error.msg, "Disconnect");
        return pkg;
    }
    else {
        pkg.status_pkg = Package::StatusPkg::SUCCESS;
        return pkg;
    }
}

Package SocketStream::sendPkg(int socket_fd, std::string message) {
    Package pkg;
    strcpy(pkg.data.text.msg, message.c_str());
    ssize_t data = send(socket_fd, &pkg, sizeof(Package), 0);

    if (data == -1) {
        pkg.status_pkg = Package::StatusPkg::ERROR;
        strcpy(pkg.data.error.msg, std::strerror(errno));
        return pkg;
    }
    else if (data == 0) {
        pkg.status_pkg = Package::StatusPkg::DISCONNECT;
        strcpy(pkg.data.error.msg, "Disconnect");
        return pkg;
    }
    else {
        pkg.status_pkg = Package::StatusPkg::SUCCESS;
        return pkg;
    }
}
