#include "postgresdb.h"
#include <iostream>

void Database::createTableIfNotExists() {
    pqxx::work txn(conn);
    txn.exec("CREATE TABLE IF NOT EXISTS people ("
              "id SERIAL PRIMARY KEY, "
              "name VARCHAR(50), "
              "surname VARCHAR(50), "
              "age INT, "
              "phone_number VARCHAR(15));");
    txn.commit();
}

Database::Database(const DatabaseConfig& config)
    : conn("dbname=" + config.dbname + " host=" + config.host +
           " port=" + config.port + " user=" + config.username +
           " password=" + config.password) {
    createTableIfNotExists();
}

std::vector<std::tuple<int, std::string, std::string, int, std::string>> Database::getAllPeople() {
    pqxx::work txn(conn);
    pqxx::result result = txn.exec("SELECT * FROM people;");
    std::vector<std::tuple<int, std::string, std::string, int, std::string>> people;

    for (const auto& row : result) {
        people.emplace_back(row[0].as<int>(), row[1].as<std::string>(),
                             row[2].as<std::string>(), row[3].as<int>(),
                             row[4].as<std::string>());
    }

    return people;
}

void Database::addPerson(const std::string& name, const std::string& surname, int age, const std::string& phone_number) {
    pqxx::work txn(conn);
    txn.exec("INSERT INTO people (name, surname, age, phone_number) VALUES (" +
             txn.quote(name) + ", " + txn.quote(surname) + ", " +
             txn.quote(age) + ", " + txn.quote(phone_number) + ");");
    txn.commit();
}

void Database::deletePerson(int id) {
    pqxx::work txn(conn);
    txn.exec("DELETE FROM people WHERE id = " + txn.quote(id) + ";");
    txn.commit();
}

void Database::updatePerson(int id, const std::string& name, const std::string& surname, int age, const std::string& phone_number) {
    pqxx::work txn(conn);
    txn.exec("UPDATE people SET name = " + txn.quote(name) +
             ", surname = " + txn.quote(surname) +
             ", age = " + txn.quote(age) +
             ", phone_number = " + txn.quote(phone_number) +
             " WHERE id = " + txn.quote(id) + ";");
    txn.commit();
}

std::vector<std::tuple<int, std::string, std::string, int, std::string>> Database::searchPeople(
    const std::string& name, const std::string& surname,
    int age, const std::string& phone_number) {

    pqxx::work txn(conn);
    std::string query = "SELECT * FROM people WHERE 1=1"; // Задаємо базовий запит

    if (!name.empty()) query += " AND name = " + txn.quote(name);
    if (!surname.empty()) query += " AND surname = " + txn.quote(surname);
    if (age != -1) query += " AND age = " + txn.quote(age);
    if (!phone_number.empty()) query += " AND phone_number = " + txn.quote(phone_number);

    pqxx::result result = txn.exec(query);
    std::vector<std::tuple<int, std::string, std::string, int, std::string>> people;

    for (const auto& row : result) {
        people.emplace_back(row[0].as<int>(), row[1].as<std::string>(),
                             row[2].as<std::string>(), row[3].as<int>(),
                             row[4].as<std::string>());
    }

    return people;
}
