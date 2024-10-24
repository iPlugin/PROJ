#include <iostream>
#include <string>

#include "client.h"
#include "../network/NetworkValidator.h"

int main(int argc, char* argv[], char* envp[]) {
    if (argc < 3) {
        std::cerr << "username@pcname:~/PROJ/cpp_socket_FileFinder$ ./runClient 127.0.0.1 1234" << std::endl;
        return 1;
    }
    
    NetworkValidator validator;
    std::string ip = argv[1];
    std::string port = argv[2];

    if (validator.isValidIP(ip) && validator.isValidPort(port)) {
        Client client(ip, port);
        if (client.connect_to_server()) {
            // Надсилаємо дані і отримуємо відповідь
            client.send_message("Hello, Server!");  // Заміна send_data на send_message
            std::string response = client.receive_message();  // Заміна recv_data на receive_message
            std::cout << "Server response: " << response << std::endl;

            client.close_connection();  // Закриття з'єднання
        }
    }
    else {
        std::cout << "Invalid data:\nIP addr: 0-255.0-255.0-255.0-255\nPort: 1-65535" << std::endl;
    }

    return 0;
}
