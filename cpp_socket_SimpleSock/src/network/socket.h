#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>  // Для std::cerr
#include <cstring>   // Для memset

class Socket {
public:
    Socket();  // Конструктор
    ~Socket(); // Деструктор

    bool socket_create();  // Створення сокета
    bool bind_socket(int port);  // Прив'язка до порту (для сервера)
    bool listen_socket(int backlog = 5);  // Перехід у режим очікування клієнтів (для сервера)
    bool accept_connection(Socket& client_socket);  // Прийняття клієнтського підключення (для сервера)

    bool connect_to_server(const std::string& server_ip, int server_port);  // Підключення до сервера

    bool send_data(const std::string& data);  // Відправка даних
    std::string recv_data();  // Отримання даних
    void close_socket();  // Закриття сокета

private:
    int sockfd;  // Дескриптор сокета
    sockaddr_in socket_address;  // Структура адреси сокета
};

#endif // SOCKET_H
