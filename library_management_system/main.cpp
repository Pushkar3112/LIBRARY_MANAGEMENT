#include "user.h"
#include "student.h"
#include "librarian.h"
#include "book.h"
#include "login_system.h"

int main() {
    system("clear");
    system("cls");

    login_system system;
    system.run();

    return 0;
}