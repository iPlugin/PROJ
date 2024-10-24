#include "NetworkValidator.h"
#include <cstdlib>
#include <cctype>

bool NetworkValidator::isValidPart(const std::string& part) {
    if (part.empty()) return false;

    for (char ch : part) {
        if (!isdigit(ch)) {
            return false;
        }
    }

    int num = std::atoi(part.c_str());
    return (num >= 0 && num <= 255);
}

bool NetworkValidator::isValidIP(const std::string& ip) {
    size_t start = 0, end = 0;
    int count = 0;

    while ((end = ip.find('.', start)) != std::string::npos) {
        std::string part = ip.substr(start, end - start);
        if (!isValidPart(part)) {
            return false;
        }
        start = end + 1;
        count++;
    }

    std::string lastPart = ip.substr(start);
    if (!isValidPart(lastPart)) {
        return false;
    }
    count++;

    return (count == 4);
}

bool NetworkValidator::isValidPort(const std::string& port) {
    if (port.empty()) return false;

    for (char ch : port) {
        if (!isdigit(ch)) {
            return false;
        }
    }

    int portNum = std::atoi(port.c_str());
    return (portNum > 0 && portNum <= 65535);
}
