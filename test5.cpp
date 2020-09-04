// test5.cpp

#include "mystring.h"
#include <cstdio>
#include <cassert>

int main()
{

    MyString obj1("1");
    MyString obj2("2");
    assert(obj1 == "1");
    cout << "1 is equal to 1" << endl;
    assert(obj1 != obj2);
    cout << " is not equal to 2" << endl;
    assert(obj2 > "1");
    cout << "2 is greater than 1" << endl;
    assert("1" < obj2);
    cout << "1 is smaller than 2" << endl;
    assert(obj2 >= "1");
    cout << "2 is greater than or equal to 1" << endl;
    assert("1" <= obj1);
    cout << "1 is smaller than or equal to 1" << endl;
    

    // test op+=() and op+()
    MyString sp(" ");
    MyString period(".");
    MyString str;
    
    str += "This" + sp + "should" + sp
        += "work" + sp + "without"
        += sp + "any" + sp + "memory"
        += sp + "leak"
        += period;
        
    cout << str << endl;
    return 0;
}

