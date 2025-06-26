#include "AuthSystem.h"
#include <iostream>
#include <stdexcept>

AuthSystem::AuthSystem(LibraryOperations& lib) : library(lib) {}

User* AuthSystem::login() {
    std::string username, password;
    std::cout << "Username: "; std::cin >> username;
    std::cout << "Password: "; std::cin >> password;

    Librarian* l = library.findLibrarian(username);
    if (l && l->checkPassword(password)) return l;

    Student* s = library.findStudent(username);
    if (s && s->checkPassword(password)) return s;

    throw std::runtime_error("Invalid username or password!");
}