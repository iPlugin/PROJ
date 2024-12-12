#ifndef NETWORKVALIDATOR_H
#define NETWORKVALIDATOR_H

#include <string>

class NetworkValidator {
public:
    bool isValidIP(const std::string& ip);
    
    bool isValidPort(const std::string& port);

private:
    bool isValidPart(const std::string& part);
};

#endif // NETWORKVALIDATOR_H
