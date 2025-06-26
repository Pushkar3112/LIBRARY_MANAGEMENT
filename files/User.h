#pragma once
#include <string>

class User {
protected:
    std::string username;
    std::string password;
public:
    User(const std::string& u, const std::string& p);
    virtual ~User() {}
    std::string getUsername() const;
    bool checkPassword(const std::string& p) const;
    virtual std::string getRole() const = 0;
};

class Student : public User {
    std::string rollNumber;
public:
    Student(const std::string&, const std::string&, const std::string&);
    std::string getRole() const override;
    std::string getRollNumber() const;
};

class Librarian : public User {
    std::string employeeId;
public:
    Librarian(const std::string&, const std::string&, const std::string&);
    std::string getRole() const override;
    std::string getEmployeeId() const;
};