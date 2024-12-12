#include "server.h"
#include <iostream>
#include <unistd.h> // для close
#include <charconv>


Server::Server(std::string server_port) {
    auto [ptr, ec] = std::from_chars(server_port.data(), server_port.data() + server_port.size(), port);
    
    if (ec == std::errc::invalid_argument) {
        std::cout << "This is not a number.\n";
    } else if (ec == std::errc::result_out_of_range) {
        std::cout << "This number is larger than an int.\n";
    }
}

bool Server::start() {
    if (!server_socket.socket_create()) {
        std::cerr << "Failed to create socket.\n";
        return false;
    }

    if (!server_socket.bind_socket(port)) {
        std::cerr << "Failed to bind socket to port " << port << ".\n";
        return false;
    }

    if (!server_socket.listen_socket()) {
        std::cerr << "Failed to listen on socket.\n";
        return false;
    }

    std::cout << "Server is listening on port " << port << "...\n";

    while (true) {
        Socket client_socket;  // Створюємо об'єкт для клієнтського сокета
        if (!server_socket.accept_connection(client_socket)) {
            std::cerr << "Failed to accept client connection.\n";
            continue;
        }

        std::cout << "Client connected.\n";

        handle_client(client_socket);

        client_socket.close_socket();  // Закриваємо з'єднання з клієнтом
        std::cout << "Client connection closed.\n";
    }

    return true;
}


void Server::stop() {
    server_socket.close_socket();
    std::cout << "Server stopped.\n";
}

void Server::handle_client(Socket& client_socket) {
    std::string received_data = client_socket.recv_data();
    if (!received_data.empty()) {
        std::cout << "Received from client: " << received_data << std::endl;

        std::string response = "Message received: " + received_data;
        client_socket.send_data(response);
    }
}

