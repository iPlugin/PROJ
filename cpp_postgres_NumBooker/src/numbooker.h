#ifndef NUMBOOKER_H
#define NUMBOOKER_H

#include <string>
#include <iostream>

struct DatabaseConfig {
    std::string host;
    int port;
    std::string username;
    std::string password;
};

class NumBooker {
private:
    std::string userName;
    DatabaseConfig db;

public:
    NumBooker(const char* name, DatabaseConfig dbConfig);
    ~NumBooker();
    
    bool run();
    void welcome();
    char option();
    void branching(const char choice);
    void optionShow();
    void optionAdd();
    void optionDel();
    void optionEdit();
    void optionSearch();
    void bye();
};

#endif // NUMBOOKER_H
