#pragma once
#include <string>
using namespace std;

class user {
protected:
    string id;
    string password;
public:
    virtual bool login(const string&, const string&) = 0;
    virtual string get_id() = 0;
};