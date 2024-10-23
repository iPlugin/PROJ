#ifndef NUMBOOKER_H
#define NUMBOOKER_H

#include <string>
#include <iostream>

#include "postgresdb.h"

class NumBooker {
private:
    std::string userName;
    Database database;

    void skip();
    void clearConsole();

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
