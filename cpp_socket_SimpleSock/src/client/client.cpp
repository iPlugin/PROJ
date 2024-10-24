#include "client.h"
#include <iostream>
#include <cstring>  // Для використання memset
#include <charconv>

Client::Client(const std::string& ip, const std::string& port)
    : server_ip(ip) {
    auto [ptr, ec] = std::from_chars(port.data(), port.data() + port.size(), server_port);

    if (ec == std::errc::invalid_argument) {
        std::cout << "This is not a number.\n";
    } else if (ec == std::errc::result_out_of_range) {
        std::cout << "This number is larger than an int.\n";
    }
}

bool Client::connect_to_server() {
    if (!client_socket.socket_create()) {
        std::cerr << "Failed to create socket.\n";
        return false;
    }

    if (!client_socket.connect_to_server(server_ip, server_port)) {
        std::cerr << "Failed to connect to server at " << server_ip << ":" << server_port << ".\n";
        return false;
    }

    std::cout << "Connected to server at " << server_ip << ":" << server_port << ".\n";
    return true;
}

bool Client::send_message(const std::string& message) {
    if (!client_socket.send_data(message)) { // Використовуємо send_data з класу Socket
        std::cerr << "Failed to send message.\n";
        return false;
    }
    return true;
}

std::string Client::receive_message() {
    std::string response = client_socket.recv_data(); // Використовуємо recv_data з класу Socket
    if (response.empty()) {
        std::cerr << "Failed to receive response or server closed connection.\n";
    }
    return response;
}


void Client::close_connection() {
    client_socket.close_socket();
    std::cout << "Connection closed.\n";
}
