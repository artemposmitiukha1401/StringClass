#ifndef MYSTRING_H
#define MYSTRING_H

// MyString.h - файл дизайна

class MyString {
    char* str = nullptr;
    int length;
public:
    MyString();
    MyString(int length);
    MyString(const char *str);
    MyString(const MyString &target_str);
    ~MyString();
    MyString(MyString &&target_str);
    void MyStrcpy(MyString &target_str);
    bool MyStrStr(const char *target_str);
    int  MyChr(char target_symbol);
    int MyStrLen();
    void MyStrCat(MyString &cat_str_target);
    int MyStrCmp(MyString &cmp_str_target);
    void MyDelChr(char target_char);

    void Print();
    void Input();
};

#endif
