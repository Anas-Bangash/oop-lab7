#include<iostream>
#include<string>
#include "studentlib.h"

using namespace std;
int main()
{
    Student s1, s2;
    string name;
    Library* library;
    s1.setName("Anas");
    s1.setId("1022");
    s1.setLibrary(&library);
    if(s1.canBorrowBook)
    {
        cout<<s1.getName<<" can borrow a book."<<endl;
    }
    else
    {
        cout<<s1.getName<<"Cannot borrow a book."<<endl;
    }
    s2.setName("Saad");
    s2.setId("2222");
    s2.setLibrary(&library);
    if(s2.canBorrowBook)
    {
        cout<<s2.getName<<" can borrow a book."<<endl;
    }
    else
    {
        cout<<s2.getName<<"Cannot borrow a book."<<endl;
    }

}