#ifndef FUNCTION_H
#define FUNCTION_H

#include<string>
using namespace std;

class Library;
class Student
{
    private:
    int id;
    string name;
    Library *library;
    public:
    Student() ;
    void setId(int id);
    int getId();
    void setName(string name);
    string getName();
    void setLibrary(Library &library);
    bool canBorrowBook();
    bool isEligibleForLibrary(); 
};
class Library
{
    private:
    bool isBorrowed;
    public:
    Library();
    void setIsBorrowed(bool iB);
    bool getIsBorrowed();
};

#endif
