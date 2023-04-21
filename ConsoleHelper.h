#ifndef STRUCT_DEMO_CONSOLEHELPER_H
#define STRUCT_DEMO_CONSOLEHELPER_H

#include <iostream>
#include <string>
#include <vector>

#include "GuestBook.h"

using namespace std;

void ShowAll(GuestBook book) {
    for (auto item : book) {
        cout << item.user_name << " <" << item.email << "> : " << item.comment << endl;
    }
}

string Input(string message) {
    string input;
    cout << message << " : ";
    getline(cin, input);

    return input;
}

void Insert(GuestBook& book) {
    GuestBookItem item;
    item.user_name = Input("Enter user name");
    item.email = Input("Enter email");
    item.comment = Input("Enter comment");
    book.push_back(item);
}

void ShowMenu() {
    cout << "--- MENU ---" << endl;
    cout << "--- 1. Show all ---" << endl;
    cout << "--- 2. Insert ---" << endl;
    cout << "--- 0. Exit ---" << endl;
}

#endif //STRUCT_DEMO_CONSOLEHELPER_H
