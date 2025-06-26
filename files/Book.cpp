#include "Book.h"
#include <iostream>

Book::Book() : bookId(0), title(""), author(""), quantity(0) {}

Book::Book(int id, const std::string& t, const std::string& a, int q)
    : bookId(id), title(t), author(a), quantity(q) {}

int Book::getBookId() const { return bookId; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getQuantity() const { return quantity; }

void Book::setQuantity(int q) { quantity = q; }

void Book::display() const {
    std::cout << "Book ID: " << bookId 
              << ", Title: " << title 
              << ", Author: " << author 
              << ", Quantity: " << quantity << std::endl;
}