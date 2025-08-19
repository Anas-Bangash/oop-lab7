#include "docter_patient.h"
#include <iostream>
#include <string>

using namespace std;

Docter::Docter() : name(""), patientCount(0)
{ 
    for (int i = 0; i < 10; ++i)
    {
        patients[i] = nullptr;
    }
}
void Docter::setName(string nm) {
    name = nm;
}
string Docter::getname() {
    return name;
}
void Docter::addPatient(Patient* p) 
{
    if (patientCount < 10)
    {
        patients[patientCount++] = p;
    } 
    else 
    {
        cout << "Cannot add more patients." << endl;
    }
}
bool Docter::hasPatient(string search) 
{
    for (int i = 0; i < patientCount; ++i) 
    {
        if (patients[i]->getName() == search) 
        {
            return true;
        }
    }
    return false;
}
int Docter::getPatientCount()
{
    return patientCount;
}
Patient** Docter::getPatients()
{
    return patients; 
}
Patient::Patient() : name(""), docterCount(0) 
{
    for (int i = 0; i < 5; ++i) 
    {
        docters[i] = nullptr;
    }
}
void Patient::setName(string nm)
{
    name = nm;
}
string Patient::getName() 
{
    return name;
}
void Patient::addDocter(Docter* d) 
{
    if (docterCount < 5) 
    {
        docters[docterCount++] = d;
    } 
    else 
    {
        cout << "Cannot add more docters." << endl;
    }
}
bool Patient::hasDocter(string search) 
{
    for (int i = 0; i < docterCount; ++i) 
    {
        if (docters[i]->getname() == search) 
        {
            return true;
        }
    }
    return false;
}
int Patient::getDocterCount()
{
    return docterCount;
}

