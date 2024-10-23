#include "numbooker.h"

void NumBooker::skip() {
    char skip;
    std::cout << "\nPress the button 'q' and Enter: "; std::cin >> skip;
}

void NumBooker::clearConsole() {
    std::system("clear");
}

NumBooker::NumBooker(const char* name, DatabaseConfig dbConfig)
    : userName(name ? name : ""), database(dbConfig) {

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
    clearConsole();

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
    clearConsole();

    auto people = database.getAllPeople();
    if (people.empty()) {
        std::cout << "The contact list is empty" << std::endl;
    }
    else {
        for (const auto& person : people) {
            std::cout << "ID: " << std::get<0>(person) <<
            ", Name: " << std::get<1>(person) <<
            ", Surname: " << std::get<2>(person) <<
            ", Age: " << std::get<3>(person) <<
            ", Phone: " << std::get<4>(person) << std::endl; 
        }   
    }
    // skip();
}
void NumBooker::optionAdd() {
    clearConsole();

    std::string name, surname, phone_number;
    int age;
    
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter surname: ";
    std::cin >> surname;
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Enter phone number: ";
    std::cin >> phone_number;
    
    database.addPerson(name, surname, age, phone_number);
    std::cout << "Contact added successfully." << std::endl;
}
void NumBooker::optionDel() {
    clearConsole();

    int id;
    std::cout << "Enter the ID of the contact to delete: ";
    std::cin >> id;
    
    database.deletePerson(id);
    std::cout << "Contact deleted successfully." << std::endl;
}
void NumBooker::optionEdit() {
    clearConsole();

    int id, age;
    std::string name, surname, phone_number;
    
    std::cout << "Enter the ID of the contact to edit: ";
    std::cin >> id;
    std::cout << "Enter new name: ";
    std::cin >> name;
    std::cout << "Enter new surname: ";
    std::cin >> surname;
    std::cout << "Enter new age: ";
    std::cin >> age;
    std::cout << "Enter new phone number: ";
    std::cin >> phone_number;
    
    database.updatePerson(id, name, surname, age, phone_number);
    std::cout << "Contact updated successfully." << std::endl;
}
void NumBooker::optionSearch() {
    clearConsole();

    std::string name, surname, phone_number;
    int age = -1;
    
    std::cout << "Enter name to search (leave empty if not applicable): ";
    std::cin.ignore(); // Очищуємо буфер перед getline
    std::getline(std::cin, name);
    std::cout << "Enter surname to search (leave empty if not applicable): ";
    std::getline(std::cin, surname);
    std::cout << "Enter phone number to search (leave empty if not applicable): ";
    std::getline(std::cin, phone_number);
    std::cout << "Enter age to search (enter -1 if not applicable): ";
    std::cin >> age;

    auto results = database.searchPeople(name, surname, age, phone_number);
    
    if (results.empty()) {
        std::cout << "No contacts found." << std::endl;
    } else {
        for (const auto& person : results) {
            std::cout << "ID: " << std::get<0>(person)
                      << ", Name: " << std::get<1>(person)
                      << ", Surname: " << std::get<2>(person)
                      << ", Age: " << std::get<3>(person)
                      << ", Phone: " << std::get<4>(person) << std::endl;
        }
    }
}

void NumBooker::bye() {
    std::cout << R"(
        Bye )" << userName + "!" << R"(
    
    Closing the NumBooker application...
    )" << std::endl;
}