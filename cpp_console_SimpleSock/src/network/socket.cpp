#include "socket.h"

// Конструктор
Socket::Socket() : sockfd(-1) {
    memset(&socket_address, 0, sizeof(socket_address));
}

// Деструктор
Socket::~Socket() {
    if (sockfd != -1) {
        close_socket();
    }
}

// Створення сокета
bool Socket::socket_create() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Failed to create socket.\n";
        return false;
    }
    return true;
}

// Прив'язка сокета до порту (для сервера)
bool Socket::bind_socket(int port) {
    socket_address.sin_family = AF_INET;
    socket_address.sin_addr.s_addr = INADDR_ANY;  // Прив'язка до всіх доступних IP-адрес
    socket_address.sin_port = htons(port);  // Конвертація порту в мережевий формат

    if (bind(sockfd, (struct sockaddr*)&socket_address, sizeof(socket_address)) == -1) {
        std::cerr << "Failed to bind socket.\n";
        return false;
    }
    return true;
}

// Перехід у режим прослуховування
bool Socket::listen_socket(int backlog) {
    if (listen(sockfd, backlog) == -1) {
        std::cerr << "Failed to listen on socket.\n";
        return false;
    }
    return true;
}

// Прийняття підключення від клієнта
bool Socket::accept_connection(Socket& client_socket) {
    socklen_t addr_len = sizeof(client_socket.socket_address);
    client_socket.sockfd = accept(sockfd, (struct sockaddr*)&client_socket.socket_address, &addr_len);
    if (client_socket.sockfd == -1) {
        std::cerr << "Failed to accept client connection.\n";
        return false;
    }
    return true;
}

// Підключення до сервера (для клієнта)
bool Socket::connect_to_server(const std::string& server_ip, int server_port) {
    socket_address.sin_family = AF_INET;
    socket_address.sin_port = htons(server_port);

    // Конвертація IP-адреси
    if (inet_pton(AF_INET, server_ip.c_str(), &socket_address.sin_addr) <= 0) {
        std::cerr << "Invalid IP address.\n";
        return false;
    }

    // Підключення до сервера
    if (connect(sockfd, (struct sockaddr*)&socket_address, sizeof(socket_address)) < 0) {
        std::cerr << "Connection to server failed.\n";
        return false;
    }
    return true;
}

// Відправка даних
bool Socket::send_data(const std::string& data) {
    if (send(sockfd, data.c_str(), data.size(), 0) == -1) {
        std::cerr << "Failed to send data.\n";
        return false;
    }
    return true;
}

// Отримання даних
std::string Socket::recv_data() {
    char buffer[1024] = {0};  // Буфер для отримання даних
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        std::cerr << "Failed to receive data.\n";
        return "";
    }
    return std::string(buffer, bytes_received);
}

// Закриття сокета
void Socket::close_socket() {
    close(sockfd);
    sockfd = -1;
}
