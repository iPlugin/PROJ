#include "server.h"

using namespace std;
using namespace liboai;

Server::Server(const string &logFilePath): logger(logFilePath) {
    logger.write("[ SERV ]", "Starting...", Logger::INFO);
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd != -1)
        logger.write("[ SOCK ]", "Successfully", Logger::INFO);
    else
        logger.write("[ SOCK ]", "Failed", Logger::ERROR);
}

Server::~Server() {
    close(server_fd);
    logger.write("[ SOCK ]", "Close", Logger::INFO);
}


bool Server::run() {
    if (bindServer())
        logger.write("[ BIND ]", "Successfully", Logger::INFO);
    else {
        logger.write("[ BIND ]", "Failed", Logger::ERROR);
        return false;
    }

    if (listenServer())
        logger.write("[ LISN ]", "Successfully", Logger::INFO);
    else {
        logger.write("[ LISN ]", "Failed", Logger::ERROR);
        return false;
    }

    while (true) {    
        if (acceptServer()) {
            logger.write("[ ACET ]", "New client", Logger::INFO);
        }
        else {
            logger.write("[ ACET ]", "Failed", Logger::ERROR);
            return false;
        }

        while (true) {
            Message msg = recvMessage();

            if (msg.status == 0) {
                command_recognition(msg.data);
            }
            else {
                break;
            }
        }
    }
    return true;
}

// ##################################################

bool Server::bindServer()
{
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // inet_addr(server_ip.c_str())
    server_addr.sin_port = htons(server_port);
    return bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)) == 0;
}

bool Server::listenServer()
{
    return listen(server_fd, 10) == 0;
}

bool Server::acceptServer()
{   
    client_addr_len = sizeof(client_addr);
    client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_addr_len);
    return client_fd != -1;
}

bool Server::sendMessage(const string message)
{
    ssize_t bytes_sent = send(client_fd, message.c_str(), message.size(), 0);
    if (bytes_sent > 0) 
        logger.write("[ SEND ]", message, Logger::DEBUG); 
    else
        logger.write("[ SEND ]", "Failed", Logger::WARNING);
}

Message Server::recvMessage()
{
    char recv_buf[1024];
    ssize_t bytes_recv = recv(client_fd, recv_buf, sizeof(recv_buf), 0);
    Message message;

    if (bytes_recv > 0) {
        recv_buf[bytes_recv] = '\0';
        string recv_str(recv_buf);
        message.status = 0;
        message.data = recv_str;

        logger.write("[ RECV ]", recv_str, Logger::DEBUG);
    }
    else if (bytes_recv == 0) {
        logger.write("[ RECV ]", "Client left", Logger::INFO);
        Message message;
        message.status = 1;
    }
    else {
        logger.write("[ RECV ]", "Failed", Logger::WARNING);
        Message message;
        message.status = 1;
    }
    return message;
}

void Server::command_recognition(std::string recv_str) {
    string command, action, object, response;
    istringstream iss(recv_str);
    iss >> command >> action >> object;

    if (command == "processes") {
        ProcessManager processManager;
        if (action == "show") {
            processManager.printProcesses();
        }
        else if (action == "kill") {
            if (object.empty()) {
                response = "processes kill <PID>";
                sendMessage(response);
            }
            else {
                response = "processes kill " + object;
                sendMessage(response);
            }
        }
        else {
            response = "processes <action>";
            sendMessage(response);
        }
    }
    
    else {
        if (!OPENAI_API_KEY.empty()) {
            string response = chatgpt(recv_str);
            sendMessage(response);
        }
        else {
            string response = "We cannot provide such information";
            sendMessage(response);
        }
    }
}

// ##################################################


string Server::chatgpt(string message) {
    OpenAI oai;

    Conversation convo;
    string server_info =
    "You received a message from the C++ Client/Server application\n"
    "The server can:\n"
    "1) Return all currently running processes to the client\n"
    "2) Also provide an opportunity to complete them\n"
    "When the server cannot process the user's request, "
    "it forwards the message to you.\n"
    "You must give short and meaningful answers to the client";

    // convo.AddUserData(server_info + message);
    if (!convo.AddUserData(server_info + message)) {
        std::cerr << "Failed to add user data to the conversation" << std::endl;
        return "Error: Failed to add user data";
    }

    if (oai.auth.SetKey(OPENAI_API_KEY)) {
        try {
            Response response = oai.ChatCompletion->create("gpt-3.5-turbo", convo);
            // convo.Update(response);
            if (!convo.Update(response)) {
                std::cerr << "Failed to update the conversation with the response" << std::endl;
                return "Error: Failed to update conversation";
            }

            // Print the response
            // std::cout << "Response from OpenAI: " << convo.GetLastResponse() << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return convo.GetLastResponse();
}