#include "studentlib.h"
#include<string>

using namespace std;

Student::Student() : id(0), name(""), library(nullptr){}
void Student::setId(int id)
{
    this->id = id;
}
int Student::getId()
{
    return id;
}
void Student::setName(string name)
{
    this->name = name;
}
string Student::getName()
{
    return name;
}
void Student::setLibrary(Library &library)
{
    this->library = &library;
}
bool Student::canBorrowBook()
{
    bool a = isEligibleForLibrary(), b = library->getIsBorrowed();
    if(library!=nullptr && !b && a)
    {
        library->setIsBorrowed(true);
        return true;
    }
    return false;
}
bool Student::isEligibleForLibrary()
{
    return(id % 2 == 0);
}
Library::Library() : isBorrowed(false) {}
void Library::setIsBorrowed(bool iB)
{
    isBorrowed = iB;
}
bool Library::getIsBorrowed()
{
    return isBorrowed;
}
    