#include <iostream>
#include <cstring>

#include "server.h"
#include "../network/NetworkValidator.h"



int main(int argc, char* argv[], char* envp[]) {
    if (argc < 2) {
        std::cerr << "username@pcname:~/PROJ/cpp_socket_FileFinder$ ./runServer 1234" << std::endl;
        return 1;
    }
    
    NetworkValidator validator;
    std::string port = argv[1];

    if (validator.isValidPort(port)) {
        Server server(port);
        server.start();
    }
    else {
        std::cout << "Invalid data:\nPort: 1-65535" << std::endl;
    }

    return 0;
}

