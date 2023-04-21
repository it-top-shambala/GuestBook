#ifndef STRUCT_DEMO_FILEHELPER_H
#define STRUCT_DEMO_FILEHELPER_H

#include <fstream>
#include <string>
#include <vector>

#include "GuestBook.h"
#include "Parser.h"

// user_name|email|comment
GuestBook ImportFromFile(string path) {
    GuestBook book;

    ifstream file;
    file.open(path);
    string line;
    while (getline(file, line)) {
        GuestBookItem item;
        item.user_name = Parser(line, '|');
        item.email = Parser(line, '|');
        item.comment = line;
        book.push_back(item);
    }
    file.close();

    return book;
}

void ExportToFile(string path, GuestBook book) {
    ofstream file;
    file.open(path, ios::trunc);

    for (auto item : book) {
        file << item.user_name << "|" << item.email << "|" << item.comment << endl;
    }

    file.close();
}

string ReadConfig() {
    string result;

    const string PATH = "path.cfg";
    ifstream file;
    file.open(PATH);
    getline(file, result);
    file.close();

    return result;
}

#endif //STRUCT_DEMO_FILEHELPER_H
