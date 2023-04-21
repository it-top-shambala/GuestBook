#include "GuestBook.h"
#include "FileHelper.h"
#include "ConsoleHelper.h"

int main() {
    string path = ReadConfig();

    GuestBook book = ImportFromFile(path);

    bool exit = false;
    do {
        ShowMenu();
        string input = Input("Enter number");

        if (input == "1") { // 1. Show all
            ShowAll(book);
        } else if (input == "2") { // 2. Insert
            Insert(book);
        } else if (input == "0") { // 0. Exit
            exit = true;
        } else {
            cout << "Bad number" << endl;
            continue;
        }
    } while (!exit);

    cout << "Goodbye" << endl;
    ExportToFile(path, book);

    return 0;
}
