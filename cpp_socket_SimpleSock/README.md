# SimpleSock

**SimpleSock** is a simple C++ project that implements a server and client for data exchange over sockets. The project demonstrates the basics of socket programming in networking and includes IP address and port validation.

## Contents

- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)

## Requirements

- C++ compiler (e.g., g++)
- C++ standard 11 or newer
- Platform with socket support (Linux, macOS)

## Installation

1. Clone the repository:
``` Bash
git clone https://github.com/iPlugin/PROJ.git
cd cpp_socket_SimpleSock
```
2. Compile the project using the Makefile:
``` Bash
make
```

## Usage
### Running the Server
Open a terminal and start the server:
``` Bash
./runServer 8000
```

### Running the Client
Open another terminal and run the client, passing the server's IP address and port:
``` Bash
./runClient 127.0.0.1 8000
```

## Project Structure
The project has the following structure:
``` Bash
cpp_socket_SimpleSock/
├── Makefile                 # File for build automation
├── build/                   # Directory for object files and executables
│   ├── runClient            # Executable for the client
│   └── runServer            # Executable for the server
├── src/                     # Directory with source files
│   ├── client/              # Client code
│   │   ├── client.cpp
│   │   └── runClient.cpp
│   ├── server/              # Server code
│   │   ├── server.cpp
│   │   └── runServer.cpp
│   ├── network/             # Networking code
│   │   ├── NetworkValidator.cpp
│   │   ├── NetworkValidator.h
│   │   ├── socket.cpp
│   │   └── socket.h
└── README.md                # Project documentation
```