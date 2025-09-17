#include "MyString.h"
#include <iostream>

MyString::MyString() {
    length = 80;
    str = new char[length];
    str[0] = '\0';
}

MyString::MyString(int length) {
    this->length = length;
    str = new char[length];
    str[0] = '\0';
}

MyString::MyString(const char *str) {
    if (str == nullptr) {
        length = 1;
        this->str = new char[length];
        this->str[0] = '\0';
    }
    else {
        length = strlen(str);
        this->str = new char[length + 1];
        strcpy(this->str, str);
    }
}

MyString::MyString(const MyString &target_str) {
    length = target_str.length;
    str = new char[length + 1];
    strcpy(str, target_str.str);
}


void MyString::Print() { std::cout << str << std::endl; }

void MyString::MyStrcpy(MyString &target_str) {
    if (str != nullptr) delete[] str;
    if (target_str.str == nullptr) {
        std::cerr << "Invalid string to copy\n";
        return;
    }
    length = target_str.length;
    str = new char[length + 1];
    strcpy(str, target_str.str);
}


bool MyString::MyStrStr(const char *target_str) {
    char *temp = strstr(str, target_str);
    if (temp != nullptr) return true;
    return false;
}

int MyString::MyChr(char target_symbol) {
    char* found = strchr(str, target_symbol);
    return found ? (int)(found - str) : -1;
}

int MyString::MyStrLen() { return strlen(str); }

void MyString::Input() {
    char temp_str[256];
    std::cin.getline(temp_str, 256);

    if (this->str != nullptr) {
        delete[] this->str;
    }
    length = strlen(temp_str);
    this->str = new char[length + 1];
    strcpy(this->str, temp_str);
}

void MyString::MyStrCat(MyString &cat_str_target) {
    int cat_length = strlen(str) + strlen(cat_str_target.str);
    char* cat_str_result = new char[cat_length + 1];

    strcpy(cat_str_result, str);
    strcat(cat_str_result, cat_str_target.str);

    delete[] str;
    str = cat_str_result;
    length = cat_length;
}

int MyString::MyStrCmp(MyString &cmp_str_target) { return strcmp(this->str, cmp_str_target.str); }

void MyString::MyDelChr(char target_char) {
    int write_char_index = 0;

    for (int check_char = 0; str[check_char] != '\0'; check_char++) {
        if (str[check_char] != target_char) {
            str[write_char_index] = str[check_char];
            write_char_index++;
        }
    }

    str[write_char_index] = '\0';
}

MyString::~MyString() {
    delete[] str;
}
