#include "student.h"

student::student(string i, string p) {
    id = i;
    password = p;
}

bool student::login(const string& i, const string& p) {
    return id == i && password == p;
}

string student::get_id() {
    return id;
}

void student::borrow_book(string bid, map<string, book>& books) {
    if (books.find(bid) == books.end()) throw runtime_error("book not found");
    if (!books[bid].available()) throw runtime_error("book not available");
    books[bid].decrease();
    borrowed[bid] = time(0);
}

void student::return_book(string bid, map<string, book>& books) {
    if (borrowed.find(bid) == borrowed.end()) throw runtime_error("not borrowed");
    time_t now = time(0);
    int days = (now - borrowed[bid]) / 86400;
    if (days > 14) cout << "fine: " << (days - 14) * 5 << endl;
    books[bid].increase();
    borrowed.erase(bid);
}