#pragma once
#include "Book.h"
#include "User.h"
#include <vector>
#include <string>

class LibraryOperations {
private:
    std::vector<Book> books;
    std::vector<Student> students;
    std::vector<Librarian> librarians;

    void loadBooksFromFile();
    void saveBooksToFile();
    void loadUsersFromFile();
    void saveUsersToFile();

public:
    LibraryOperations();
    ~LibraryOperations();

    // Book operations
    void addBook(const Book& b);
    void displayBooks() const;
    Book* searchBook(int bookId);
    void issueBook(Student& s, int bookId);
    void returnBook(Student& s, int bookId);
    void removeBook(int bookId);

    // User operations
    Student* findStudent(const std::string& username);
    Librarian* findLibrarian(const std::string& username);

    // File persistence
    void sync();
};