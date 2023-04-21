cmake_minimum_required(VERSION 3.17)
project(GuestBook)

set(CMAKE_CXX_STANDARD 17)

add_executable(GuestBook main.cpp GuestBookItem.h FileHelper.h Parser.h ConsoleHelper.h GuestBook.h)
