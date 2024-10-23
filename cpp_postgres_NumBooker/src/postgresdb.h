#ifndef DATABASE_H
#define DATABASE_H

#include <pqxx/pqxx>
#include <string>
#include <tuple>
#include <vector>

struct DatabaseConfig {
    std::string dbname;
    std::string host;
    std::string port;
    std::string username;
    std::string password;
};

class Database {
private:
    pqxx::connection conn;

    void createTableIfNotExists();

public:
    Database(const DatabaseConfig& config);

    // Повертає всіх людей з таблиці
    std::vector<std::tuple<int, std::string, std::string, int, std::string >> getAllPeople();

    // Додає нового користувача
    void addPerson(const std::string& name, const std::string& surname, int age, const std::string& phone_number);

    // Видаляє користувача за ID
    void deletePerson(int id);

    // Оновлює інформацію про користувача
    void updatePerson(int id, const std::string& name, const std::string& surname, int age, const std::string& phone_number);

    // Пошук за одним з полів
    std::vector<std::tuple<int, std::string, std::string, int, std::string >> searchPeople(
        const std::string& name = "", const std::string& surname = "",
        int age = -1, const std::string& phone_number = "");
};

#endif // DATABASE_H
