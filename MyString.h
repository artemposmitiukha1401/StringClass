#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <__ostream/basic_ostream.h>

// MyString.h - файл дизайна

class MyString {
    char* str = nullptr;
    int length;
    static int strings_count;
public:
    MyString();
    MyString(int length);
    MyString(const char *str);
    MyString(const MyString &target_str);
    ~MyString();
    MyString(MyString &&target_str);
    void MyStrcpy(const MyString &target_str);
    bool MyStrStr(const char *target_str);
    int  MyChr(char target_symbol);
    int MyStrLen();
    void MyStrCat(const MyString &cat_str_target);
    int MyStrCmp(MyString &cmp_str_target);
    void MyDelChr(char target_char);
    static void PrintStringsCount();

    MyString operator+(const MyString &target_str) const;
    MyString operator+(const char* target_str) const;
    MyString operator+(const char target_str) const;
    MyString operator-(const char* target_str) const;

    bool operator==(const MyString &target_str) const;
    bool operator!=(const MyString &target_str) const;
    bool operator>(const MyString &target_str) const;
    bool operator<(const MyString &target_str) const;
    bool operator>=(const MyString &target_str) const;
    bool operator<=(const MyString &target_str) const;

    bool operator==(const int length) const;
    bool operator!=(const int length) const;
    bool operator>(const int length) const;
    bool operator<(const int length) const;
    bool operator>=(const int length) const;
    bool operator<=(const int length) const;

    bool operator==(const char* target_str) const;
    bool operator!=(const char* target_str) const;
    bool operator>(const char* target_str) const;
    bool operator<(const char* target_str) const;
    bool operator>=(const char* target_str) const;
    bool operator<=(const char* target_str) const;

    void Print();
    void Input();
};

#endif
