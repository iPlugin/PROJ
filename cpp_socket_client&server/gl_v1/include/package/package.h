#ifndef PACKAGES_H
#define PACKAGES_H

#pragma pack(push, 1)

struct Package{
    enum StatusPkg { SUCCESS, ERROR, DISCONNECT } status_pkg;
    // enum TypePkg { INTRODUCE, REQUEST, ANSWER} type_pkg;
    
    union Data {
        struct TEXT_MSG { char msg[1016]; } text;
        struct ERROR_MSG { char msg[50]; } error;
        char padding[1024 - sizeof(StatusPkg)]; // - sizeof(TypePkg)
    } data;
};
static_assert(sizeof(Package) == 1024, "Package != 1024 bytes");

#pragma pack(pop)

#endif // PACKAGES_H