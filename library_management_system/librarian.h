#pragma once
#include "user.h"
#include "book.h"
#include <map>
using namespace std;

class librarian : public user {
public:
    librarian(string, string);
    bool login(const string&, const string&) override;
    string get_id() override;
    void add_book(string, string, string, int, map<string, book>&);
};