#include "MyString.h"
#include <iostream>

int MyString::strings_count = 0;

void MyString::PrintStringsCount() {
    std::cout << "Total number of strings: " << strings_count << std::endl;
}

MyString MyString::operator+(const MyString &target_str) const{
    if (target_str.str == nullptr || strlen(target_str.str)) {
        std::cerr << "Invalid operation\n";
        return *this;
    }
    int cat_string_length = strlen(target_str.str) + strlen(str);
    MyString new_str{cat_string_length + 1};
    strcpy(new_str.str, str);
    strcat(new_str.str, target_str.str);
    strings_count++;
    return new_str;
}


MyString MyString::operator+(const char* target_str) const{
    if (target_str == nullptr || strlen(target_str)) {
        std::cerr << "Invalid operation\n";
        return *this;
    }
    int cat_string_length = strlen(target_str) + strlen(str);
    MyString new_str{ cat_string_length+ 1};
    strcpy(new_str.str, str);
    strcat(new_str.str, target_str);
    strings_count++;
    return new_str;
}

MyString MyString::operator+(const char target_char) const {
    int cat_string_length = strlen(str) ;
    MyString new_str{cat_string_length+ 2};
    strcpy(new_str.str, str);
    new_str.str[new_str.length ] = target_char;
    new_str.str[new_str.length + 1] = '\0';
    strings_count++;
    return new_str;
}
MyString MyString::operator-(const char* target_str) const {
    if (target_str == nullptr || strlen(target_str) == 0) return MyString(*this);

    int new_length = strlen(target_str);
    MyString result(this->length);
    int write_index = 0;

    for (int i = 0; str[i] != '\0'; ) {
        if (strncmp(&str[i], target_str, new_length) == 0) i += new_length;
        else result.str[write_index++] = str[i++];
    }
    strings_count++;
    result.str[write_index] = '\0';
    return result;
}

MyString::MyString() {
    length = 80;
    str = new char[length];
    str[0] = '\0';
    strings_count++;
}

MyString::MyString(int length) {
    this->length = length;
    str = new char[length];
    str[0] = '\0';
    strings_count++;
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
    strings_count++;
}

MyString::MyString(const MyString &target_str) {
    length = target_str.length;
    str = new char[length + 1];
    strcpy(str, target_str.str);
    strings_count++;
}


void MyString::Print() { std::cout << str << std::endl; }

void MyString::MyStrcpy(const MyString &target_str) {
    if (this == &target_str) return;

    char* temp = new char[strlen(target_str.str) + 1];
    strcpy(temp, target_str.str);

    delete[] str;
    str = temp;
    length = strlen(str);
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

void MyString::MyStrCat(const MyString &cat_str_target) {
    if (cat_str_target.str == nullptr) return;

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

MyString::MyString(MyString &&target_str) {
    length = target_str.length;
    target_str.length = 0;
    str = target_str.str;
    target_str.str = nullptr;
}
