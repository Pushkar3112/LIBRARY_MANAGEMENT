#include "LibraryOperations.h"
#include "AuthSystem.h"
#include <iostream>

void librarianMenu(LibraryOperations& library) {
    int choice;
    do {
        std::cout << "\n--- Librarian Menu ---\n";
        std::cout << "1. View Books\n2. Add Book\n3. Remove Book\n4. Exit\n";
        std::cout << "Choice: "; std::cin >> choice;
        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2: {
                int id, qty;
                std::string title, author;
                std::cout << "Book ID: "; std::cin >> id;
                std::cin.ignore();
                std::cout << "Title: "; std::getline(std::cin, title);
                std::cout << "Author: "; std::getline(std::cin, author);
                std::cout << "Quantity: "; std::cin >> qty;
                library.addBook(Book(id, title, author, qty));
                break;
            }
            case 3: {
                int id;
                std::cout << "Book ID to remove: "; std::cin >> id;
                try {
                    library.removeBook(id);
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 4: break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}

void studentMenu(LibraryOperations& library, Student& student) {
    int choice;
    do {
        std::cout << "\n--- Student Menu ---\n";
        std::cout << "1. View Books\n2. Issue Book\n3. Return Book\n4. Exit\n";
        std::cout << "Choice: "; std::cin >> choice;
        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2: {
                int id;
                std::cout << "Book ID to issue: "; std::cin >> id;
                try {
                    library.issueBook(student, id);
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                int id;
                std::cout << "Book ID to return: "; std::cin >> id;
                try {
                    library.returnBook(student, id);
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}

int main() {
    LibraryOperations library;
    AuthSystem auth(library);

    std::cout << "Welcome to Library Management System\n";
    try {
        User* user = auth.login();
        if (user->getRole() == "Librarian") {
            librarianMenu(library);
        } else if (user->getRole() == "Student") {
            Student* s = dynamic_cast<Student*>(user);
            if (s) studentMenu(library, *s);
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}