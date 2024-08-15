#include <string>
#include <iostream>

#include "../include/server/server.h"


int main(int argc, char *argv[]) {
    if (argc == 2) {
        std::string port = argv[1];
        try {
            Server server(port, "logs/logServer.log");
            if (!server.run()) {
                std::cout << "Error when server starting ..." << std::endl;
            }
        }
        catch(const std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        }
    }
    else {
        std::cout << "Start: $ ./runServer <port>" << std::endl;
    }
    
    return 0;
}