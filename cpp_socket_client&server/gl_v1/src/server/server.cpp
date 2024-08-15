#include "../../include/server/server.h"


Server::Server(const std::string tmp_port, const std::string &logFilePath)
    : logger(logFilePath) {
    int port;
    auto [ ptr, ec ] = std::from_chars(tmp_port.data(), tmp_port.data() + tmp_port.size(), port);
    if (ec != std::errc()) {
        throw std::invalid_argument("Start: $ ./runServer <int>");
    }
    connect_port = port;
}

Server::~Server() {
    close(server_fd);
    if (client_fd != -1) {
        close(client_fd);
    }
}


bool Server::run() {
    std::string type_SEVR = "[ SEVR ]";
    std::string type_SOCK = "[ SOCK ]";
    std::string type_BIND = "[ BIND ]";
    std::string type_LISN = "[ LISN ]";
    std::string type_ACPT = "[ ACPT ]";
    std::string type_RECV = "[ RECV ]";
    std::string type_SEND = "[ SEND ]";

    logger.write(type_SEVR, "Server starting...", Logger::INFO);

    server_fd = sock_steam.getSocket();
    if (SUCCESS(server_fd)) {
        logger.write(type_SOCK, "Socket succesfully", Logger::INFO);   
    }
    else {
        logger.write(type_SOCK, "Socket failed", Logger::ERROR);
        return false;
    }

    int bindRes = sock_steam.getBind(server_fd, connect_port, server_addr);
    if (SUCCESS(bindRes)) {
        logger.write(type_BIND, "Bind succesfully", Logger::INFO);
    }
    else {
        logger.write(type_BIND, "Bind failed", Logger::ERROR);
        return false;
    }

    int listenRes = sock_steam.getListen(server_fd);
    if (SUCCESS(listenRes)) {
        logger.write(type_LISN, "Listen succesfully", Logger::INFO);
    }
    else {
        logger.write(type_LISN, "Listen failed", Logger::ERROR);
        return false;
    }    


    while (true) {

        client_fd = sock_steam.getAccept(server_fd, client_addr);
        if (SUCCESS(client_fd)) {
            logger.write(type_ACPT, "New client", Logger::WARNING);
        }
        else {
            logger.write(type_ACPT, "Connect faild", Logger::ERROR);
            return false;
        }


        std::string info = // Тут треба використати extern
            "\n|\t\tServer can:\n"
            "|\t[1] File search\n"
            "|\t\t- search <path>\n"
            "|\n"
            "|\tCorect request:\n"
            "|\t<num> <action> <arg>";

        Package send_pkg = sock_steam.sendPkg(client_fd, info);
        if (send_pkg.status_pkg == Package::StatusPkg::ERROR) {
            logger.write(type_SEND, send_pkg.data.error.msg, Logger::ERROR);
            break;
        }
        else if (send_pkg.status_pkg == Package::StatusPkg::DISCONNECT) {
            logger.write(type_ACPT, send_pkg.data.error.msg, Logger::WARNING);
            continue;
        }
        else {
            logger.write(type_SEND, send_pkg.data.text.msg, Logger::DEBUG);
        }


        while (true) {

            Package recv_pkg = sock_steam.recvPkg(client_fd);
            if (recv_pkg.status_pkg == Package::StatusPkg::ERROR) {
                logger.write(type_RECV, recv_pkg.data.error.msg, Logger::ERROR);
                break;
            }
            else if (recv_pkg.status_pkg == Package::StatusPkg::DISCONNECT) {
                logger.write(type_ACPT, recv_pkg.data.error.msg, Logger::WARNING);
                break;
            }
            else {
                logger.write(type_RECV, recv_pkg.data.text.msg, Logger::DEBUG);
            }
        }
    }

    logger.write(type_SEVR, "Server finished...", Logger::INFO);

    return true;
}