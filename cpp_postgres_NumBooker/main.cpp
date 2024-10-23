#include <iostream>
#include <cstring>

#include "src/numbooker.h"
#include "INIReader.h"

const char* getUserName(char* envp[]) {
    const char* userVar = "USER=";
    for (int i = 0; envp[i] != nullptr; ++i) {
        if (std::strncmp(envp[i], userVar, std::strlen(userVar)) == 0) {
            return envp[i] + std::strlen(userVar);
        }
    }
    return nullptr;
}

DatabaseConfig getDataINI(const std::string& filename) {
    INIReader reader(filename);

    DatabaseConfig data;
    data.dbname = reader.GetString("DataBase", "dbname", "unknown");
    data.host = reader.GetString("DataBase", "host", "unknown");
    data.port = reader.GetString("DataBase", "port", "unknown");
    data.username = reader.GetString("DataBase", "username", "unknown");
    data.password = reader.GetString("DataBase", "password", "unknown");

    return data;
}

int main(int argc, char* argv[], char* envp[]) {

    const char* userName = getUserName(envp);
    DatabaseConfig dbConfig = getDataINI("settings/config.ini");

    NumBooker book(userName, dbConfig);
    book.run();
    
    return 0;
}