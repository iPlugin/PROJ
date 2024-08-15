#include "../../include/client/client.h"


Client::Client(const std::string ip, const std::string tmp_port, const std::string &logFilePath)
    : logger(logFilePath) {
    int port;
    auto [ ptr, ec ] = std::from_chars(tmp_port.data(), tmp_port.data() + tmp_port.size(), port);
    if (ec != std::errc()) {
        throw std::invalid_argument("Start: $ ./runClient <str> <int>");
    }
    connect_ip = ip;
    connect_port = port;
}

Client::~Client() {
    close(client_fd);
}


bool Client::run() {
    std::string type_CLNT = "[ CLNT ]";
    std::string type_SOCK = "[ SOCK ]";
    std::string type_CONT = "[ CONT ]";
    std::string type_RECV = "[ RECV ]";
    std::string type_SEND = "[ SEND ]";

    logger.write(type_CLNT, "Client starting...", Logger::INFO);

    client_fd = sock_steam.getSocket();
    if (SUCCESS(client_fd)) {
        logger.write(type_SOCK, "Socket succesfully", Logger::INFO);
    }
    else {
        logger.write(type_SOCK, "Socket failed", Logger::ERROR);
        return false;
    }

    int connectRes = sock_steam.getConnect(client_fd, connect_ip, connect_port, server_addr);
    if (SUCCESS(connectRes)) {
        logger.write(type_CONT, "Connect succesfully", Logger::WARNING);
    }
    else {
        logger.write(type_CONT, "Connect faild", Logger::ERROR);
        return false;
    }


    while (true) {

        Package recv_pkg = sock_steam.recvPkg(client_fd);
        if (recv_pkg.status_pkg == Package::StatusPkg::ERROR) {
            logger.write(type_RECV, recv_pkg.data.error.msg, Logger::ERROR);
            break;
        }
        else if (recv_pkg.status_pkg == Package::StatusPkg::DISCONNECT) {
            logger.write(type_CONT, recv_pkg.data.error.msg, Logger::WARNING);
            break;
        }
        else {
            logger.write(type_RECV, recv_pkg.data.text.msg, Logger::DEBUG);
        }


        Package send_pkg = sock_steam.sendPkg(client_fd, "Hello"); 
        if (send_pkg.status_pkg == Package::StatusPkg::ERROR) {
            logger.write(type_SEND, send_pkg.data.error.msg, Logger::ERROR);
            break;
        }
        else if (send_pkg.status_pkg == Package::StatusPkg::DISCONNECT) {
            logger.write(type_CONT, send_pkg.data.error.msg, Logger::WARNING);
            break;
        }
        else {
            logger.write(type_SEND, send_pkg.data.text.msg, Logger::DEBUG);
        }

    }

    logger.write(type_CLNT, "Client finished...", Logger::INFO);
    
    return true;
}
