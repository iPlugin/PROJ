#include "numbooker.h"

NumBooker::NumBooker(const char* name, DatabaseConfig dbConfig)
    : userName(name ? name : ""), db(dbConfig) {

}

NumBooker::~NumBooker() {}

bool NumBooker::run() {
    welcome();
    
    while (true) {
        char choice = option();
        if (choice == 'q') {break;}
        branching(choice);
    }

    bye();
    
    return true;
}


void NumBooker::welcome() {
    std::cout << R"(
    Starting the NumBooker application...

        Hello)" << " " + userName << R"(! We are excited to introduce our new program
    a phonebook created using C++ and PostgreSQL.
    This program allows you to conveniently store and manage contacts.
    )" << std::endl;
}

char NumBooker::option() {
    char result;
    std::cout << R"(
        Choose an option [ 0 .. 5 or q]
    [1] Show all contacts
    [2] Add a contact
    [3] Delete the contact
    [4] Edit the contact
    [5] Contact search
    [q] Exit the program
    
     :)";
    std::cin >> result;
    return result;
}

void NumBooker::branching(const char choice) {
    switch (choice) {
    case '1':
        optionShow();
        break;
    case '2':
        optionAdd();
        break;
    case '3':
        optionDel();
        break;
    case '4':
        optionEdit();
        break;
    case '5':
        optionSearch();
        break;
    
    default:
        std::cout << R"(
        Incorrect option selected. Format: number or q
        )" << std::endl;
        break;
    }
}

void NumBooker::optionShow() {
    std::cout << "optionShow" << std::endl;
}
void NumBooker::optionAdd() {
    std::cout << "optionAdd" << std::endl;
}
void NumBooker::optionDel() {
    std::cout << "optionDel" << std::endl;
}
void NumBooker::optionEdit() {
    std::cout << "optionEdit" << std::endl;
}
void NumBooker::optionSearch() {
    std::cout << "optionSearch" << std::endl;
}

void NumBooker::bye() {
    std::cout << R"(
        Bye )" << userName + "!" << R"(
    
    Closing the NumBooker application...
    )" << std::endl;
}