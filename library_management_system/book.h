#pragma once
#include <string>
using namespace std;

class book {
    string id, title, author;
    int copies;
public:
    book();
    book(string, string, string, int);
    bool available();
    void decrease();
    void increase();
};