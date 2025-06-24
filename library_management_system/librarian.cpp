#include "librarian.h"

librarian::librarian(string i, string p) {
    id = i;
    password = p;
}

bool librarian::login(const string& i, const string& p) {
    return id == i && password == p;
}

string librarian::get_id() {
    return id;
}

void librarian::add_book(string bid, string title, string author, int copies, map<string, book>& books) {
    books[bid] = book(bid, title, author, copies);
}