#include <string>
#include <iostream>

#include "../include/client/client.h"


int main(int argc, char *argv[]) {
    if (argc == 3) {
        std::string ip = argv[1];
        std::string port = argv[2];
        try {
            Client client(ip, port, "logs/logClient.log");
            if (!client.run()) {
                std::cout << "Error when client starting ..." << std::endl;
            }
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    else {
        std::cout << "Start: $ ./runClient <ip> <port>" << std::endl;
    }
    
    return 0;
}