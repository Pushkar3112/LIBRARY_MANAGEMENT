#pragma once
#include <string>

class Book {
private:
    int bookId;
    std::string title;
    std::string author;
    int quantity;
public:
    Book();
    Book(int id, const std::string& t, const std::string& a, int q);

    int getBookId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getQuantity() const;

    void setQuantity(int q);

    void display() const;
};