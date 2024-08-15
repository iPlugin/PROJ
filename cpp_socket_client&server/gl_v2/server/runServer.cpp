#include "server.h"

int main()
{
    Server server("log/logServer.log");

    if (!server.run())
        std::cout << "[ SERV ] Finished own work" << std::endl;

    return 0;
}