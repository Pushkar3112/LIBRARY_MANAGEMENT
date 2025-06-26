#include "User.h"

User::User(const std::string& u, const std::string& p) : username(u), password(p) {}
std::string User::getUsername() const { return username; }
bool User::checkPassword(const std::string& p) const { return password == p; }

Student::Student(const std::string& u, const std::string& p, const std::string& r)
    : User(u, p), rollNumber(r) {}
std::string Student::getRole() const { return "Student"; }
std::string Student::getRollNumber() const { return rollNumber; }

Librarian::Librarian(const std::string& u, const std::string& p, const std::string& e)
    : User(u, p), employeeId(e) {}
std::string Librarian::getRole() const { return "Librarian"; }
std::string Librarian::getEmployeeId() const { return employeeId; }