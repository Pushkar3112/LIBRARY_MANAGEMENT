#include "LibraryOperations.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <algorithm>

LibraryOperations::LibraryOperations() {
    loadBooksFromFile();
    loadUsersFromFile();
}
LibraryOperations::~LibraryOperations() {
    sync();
}

void LibraryOperations::addBook(const Book& b) {
    books.push_back(b);
    saveBooksToFile();
}

void LibraryOperations::displayBooks() const {
    for (const auto& b : books) b.display();
}

Book* LibraryOperations::searchBook(int bookId) {
    for (auto& b : books) {
        if (b.getBookId() == bookId) return &b;
    }
    return nullptr;
}

void LibraryOperations::issueBook(Student& s, int bookId) {
    Book* b = searchBook(bookId);
    if (!b) throw std::runtime_error("Book not found!");
    if (b->getQuantity() < 1) throw std::runtime_error("Book not available!");
    b->setQuantity(b->getQuantity() - 1);
    saveBooksToFile();
    std::cout << "Book issued to " << s.getUsername() << std::endl;
}

void LibraryOperations::returnBook(Student& s, int bookId) {
    Book* b = searchBook(bookId);
    if (!b) throw std::runtime_error("Book not found!");
    b->setQuantity(b->getQuantity() + 1);
    saveBooksToFile();
    std::cout << "Book returned by " << s.getUsername() << std::endl;
}

void LibraryOperations::removeBook(int bookId) {
    auto it = std::remove_if(books.begin(), books.end(), [bookId](const Book& b){ return b.getBookId() == bookId; });
    if (it != books.end()) {
        books.erase(it, books.end());
        saveBooksToFile();
        std::cout << "Book removed.\n";
    } else {
        throw std::runtime_error("Book not found!");
    }
}

Student* LibraryOperations::findStudent(const std::string& username) {
    for (auto& s : students)
        if (s.getUsername() == username)
            return &s;
    return nullptr;
}

Librarian* LibraryOperations::findLibrarian(const std::string& username) {
    for (auto& l : librarians)
        if (l.getUsername() == username)
            return &l;
    return nullptr;
}

// -- File handling (books.txt, users.txt) --

void LibraryOperations::loadBooksFromFile() {
    books.clear();
    std::ifstream file("books.txt");
    if (!file) return;
    int id, qty;
    std::string title, author;
    while (file >> id) {
        file.ignore();
        std::getline(file, title);
        std::getline(file, author);
        file >> qty;
        file.ignore();
        books.emplace_back(id, title, author, qty);
    }
    file.close();
}

void LibraryOperations::saveBooksToFile() {
    std::ofstream file("books.txt");
    for (const auto& b : books) {
        file << b.getBookId() << '\n'
             << b.getTitle() << '\n'
             << b.getAuthor() << '\n'
             << b.getQuantity() << '\n';
    }
    file.close();
}

void LibraryOperations::loadUsersFromFile() {
    students.clear();
    librarians.clear();
    std::ifstream file("users.txt");
    if (!file) return;
    std::string role, username, password, id;
    while (file >> role) {
        file >> username >> password >> id;
        if (role == "Student")
            students.emplace_back(username, password, id);
        else if (role == "Librarian")
            librarians.emplace_back(username, password, id);
    }
    file.close();
}

void LibraryOperations::saveUsersToFile() {
    std::ofstream file("users.txt");
    for (const auto& s : students)
        file << "Student " << s.getUsername() << " " << "pass " << s.getRollNumber() << '\n';
    for (const auto& l : librarians)
        file << "Librarian " << l.getUsername() << " " << "pass " << l.getEmployeeId() << '\n';
    file.close();
}

void LibraryOperations::sync() {
    saveBooksToFile();
    saveUsersToFile();
}