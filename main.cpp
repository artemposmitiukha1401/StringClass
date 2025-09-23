#include <iostream>
#include "MyString.h"
int main() {
    MyString test_str = "Hello";
    MyString test_str2 = "World";
    test_str.Print();
    test_str2.Print();
    std::cout << test_str.MyStrLen() << std::endl;
    std::cout << test_str.MyStrCmp(test_str2) << std::endl;
    test_str.MyDelChr('l');
    test_str.Print();
    std::cout << test_str.MyChr('H') << std::endl;
    test_str.MyStrCat(test_str2);
    test_str.Print();
    MyString my_str = "Hello";
    MyString my_str2 = std::move(my_str);
    MyString::PrintStringsCount();


    return 0;
}