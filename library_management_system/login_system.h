#pragma once
#include "student.h"
#include "librarian.h"
#include <map>
#include <fstream>
using namespace std;

class login_system {
    map<string, student> students;
    map<string, librarian> librarians;
    map<string, book> books;
public:
    login_system();
    void run();
};