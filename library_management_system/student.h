#pragma once
#include "user.h"
#include "book.h"
#include <map>
#include <vector>
#include <ctime>
using namespace std;

class student : public user {
public:
    map<string, time_t> borrowed;
    student(string, string);
    bool login(const string&, const string&) override;
    string get_id() override;
    void borrow_book(string, map<string, book>&);
    void return_book(string, map<string, book>&);
};