#include <iostream>
#include "login_system.h"


using namespace std;
login_system::login_system() {
    ifstream sin("students.txt"), lin("librarians.txt"), bin("books.txt");
    string id, pass, bid, title, author;
    int copies;

    while (sin >> id >> pass) students[id] = student(id, pass);
    while (lin >> id >> pass) librarians[id] = librarian(id, pass);
    while (bin >> bid >> title >> author >> copies)
        books[bid] = book(bid, title, author, copies);
}

void login_system::run() {
    string role, id, pass;
    cin >> role >> id >> pass;

    try {
        if (role == "student" && students[id].login(id, pass)) {
            string cmd, bid;
            while (cin >> cmd >> bid) {
                if (cmd == "borrow") students[id].borrow_book(bid, books);
                if (cmd == "return") students[id].return_book(bid, books);
            }
        } else if (role == "librarian" && librarians[id].login(id, pass)) {
            string bid, title, author;
            int copies;
            while (cin >> bid >> title >> author >> copies)
                librarians[id].add_book(bid, title, author, copies, books);
        } else throw runtime_error("invalid login");
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}