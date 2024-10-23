# NumBooker
**NumBooker** is a command-line application that allows you to manage contacts in your phonebook efficiently using PostgreSQL as the database. The program offers functionality to add, edit, delete, and search for contacts through a convenient terminal-based interface. It uses the powerful libpqxx library to interact with the database at the C++ level.

## Features:
- Create new contacts with name, surname, age, and phone number.
- View all contacts.
- Edit or delete existing contacts.
- Search contacts by different parameters (name, surname, age, phone number).
- PostgreSQL database integration using libpqxx.
- Support for containerization via Docker.

## Dependencies
To install the necessary dependencies for running the project, use the following commands:
### System Update:
``` Bash script
$ sudo apt update && sudo apt upgrade
```

### Docker:
**Docker** is an open platform for developing, shipping, and running applications. It allows you to separate your applications from your infrastructure, delivering software faster.
``` Bash script
$ sudo apt install docker.io
```

### libpqxx:
**libpqxx** is a convenient C++ library that simplifies interactions with PostgreSQL using standard C++ constructs.
``` Bash script
$ sudo apt-get install libpqxx-dev
```

### DBeaver:
**DBeaver** is a SQL client and database management tool. For relational databases, it uses the JDBC API to interact with databases via a JDBC driver.
``` Bash script
$ sudo apt install default-jre
$ sudo snap install dbeaver-ce
```

## Configuration
A configuration file named settings/config.ini is already created. You need to fill in the following parameters:
``` ini
[DataBase]
dbname = numbooker
host = localhost
port = 5432
username = your_username
password = your_password

```

## How to Run the Project
### Start:
1) Create a Database:
Once DBeaver is installed, connect to PostgreSQL and create a database for the project using the following SQL command:
``` SQL
CREATE DATABASE numbooker;
```
2) Run the Project Using Docker:
``` Bash script
$ sudo docker run --name numbooker -e POSTGRES_PASSWORD=25051958 -d -p 5432:5432 postgres
```
3) Compile and Run the Project:
``` Bash script
$ make
$ ./project
```

## Restarting the Project
To restart the container and project after exiting:
``` Bash script
$ sudo docker restart numbooker
$ make restart
```

## Stopping the Project:
To stop the Docker container and clean up the project files:
``` Bash script
$ sudo docker stop numbooker
$ make clean
```