#include <iostream>
#include "MyString.h"
int main() {
    MyString test_str = "Hello world";
    MyString test_str2 = " World";
    MyString test_str3 = test_str + test_str2;
    test_str3.Print();
    MyString test_str4 = test_str + " Earth";
    test_str4.Print();
    MyString test_str5 = test_str + 'T';
    test_str5.Print();
    MyString test_str6 = test_str - "world";
    test_str6.Print();

    test_str > test_str2 ? std::cout << "First is bigger\n" : std::cout << "Second is bigger\n";
    test_str < test_str2 ? std::cout << "First is bigger\n" : std::cout << "Second is bigger\n";
    test_str == test_str2 ? std::cout << "String are equal\n" : std::cout << "String are different\n";
    test_str >= test_str2 ? std::cout << "String are equal or first is bigger\n" : std::cout << "String are different and first is not bigger\n";
    test_str > 2 ? std::cout << "String is longer\n" : std::cout << "String is shorter\n";

    // test_str.Print();
    // test_str2.Print();
    // std::cout << test_str.MyStrLen() << std::endl;
    // std::cout << test_str.MyStrCmp(test_str2) << std::endl;
    // test_str.MyDelChr('l');
    // test_str.Print();
    // std::cout << test_str.MyChr('H') << std::endl;
    // test_str.MyStrCat(test_str2);
    // test_str.Print();
    // MyString my_str = "Hello";
    // MyString my_str2 = std::move(my_str);
    // MyString::PrintStringsCount();


    return 0;
}