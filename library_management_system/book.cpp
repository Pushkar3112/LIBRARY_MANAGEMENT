#include "book.h"

book::book() {}

book::book(string i, string t, string a, int c) : id(i), title(t), author(a), copies(c) {}

bool book::available() { return copies > 0; }
void book::decrease() { if (copies <= 0) throw runtime_error("book not available"); copies--; }
void book::increase() { copies++; }