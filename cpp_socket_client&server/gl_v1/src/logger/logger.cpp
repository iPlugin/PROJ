#include "../../include/logger/logger.h"


Logger::Logger(const std::string& filename)
    : log_file(filename, std::ios::app) {
    if (!log_file.is_open()) {
        std::cerr << "[ LOGS ] Error opening log file!" << std::endl;
    }
}

Logger::~Logger() {
    if (log_file.is_open()) {
        log_file.close();
    }
}

void Logger::write(const std::string& type, const std::string& msg, LogLevel level) {
    std::string line, message;
    switch (level) {
    case DEBUG:
        message = type + " " + msg + "\n";
        std::cout << BOLDGREEN << message << RESET;
        // line = getCurrentTime() + " [ DEBG ] " + message;
        // push(line);
        break;
    case INFO:
        message = type + " " + msg + "\n";
        std::cout << BOLDBLUE << message << RESET;
        line = getCurrentTime() + " [ INFO ] " + message;
        push(line);
        break;
    case WARNING:
        message = type + " " + msg + "\n";
        std::cout << BOLDYELLOW << message << RESET;
        line = getCurrentTime() + " [ WARN ] " + message;
        push(line);
        break;
    case ERROR:
        message = type + " " + msg + "\n";
        std::cout << BOLDRED << message << RESET;
        line = getCurrentTime() + " [ ERRO ] " + message;
        push(line);
        break;
    case CRITICAL:
        message = type + " " + msg + "\n";
        std::cout << BOLDBLACK << message << RESET;
        line = getCurrentTime() + " [ CRTL ] " + message;
        push(line);
        break;
    }
}

void Logger::push(const std::string& line) {
    if (log_file.is_open()) {
        log_file << line;
        log_file.flush();
    }
}

std::string Logger::getCurrentTime() {
    std::time_t now = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buf);
}