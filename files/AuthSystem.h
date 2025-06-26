#pragma once
#include "LibraryOperations.h"
#include "User.h"

class AuthSystem {
private:
    LibraryOperations& library;
public:
    AuthSystem(LibraryOperations& lib);
    User* login();
};