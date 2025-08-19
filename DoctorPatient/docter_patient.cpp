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
void Docter::DeletePatient(string patName) 
{
    for (int i = 0; i < patientCount; ++i) 
    {
        if (patients[i]->getName() == patName) 
        {
            for (int j = (patientCount - 1); j <i ; j--) 
            {
                patients[j] = patients[j + 1]; // Shift patients to the left
            }
            patients[--patientCount] = nullptr; // Decrease count and nullify last pointer
            return;
        }
    }
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
void Patient::DeleteDocter(string docName) 
{
    for (int i = 0; i < docterCount; ++i) 
    {
        if (docters[i]->getname() == docName) 
        {
            for (int j = (docterCount - 1); j > i; j--) 
            {
                docters[j] = docters[j + 1]; // Shift docters to the left
            }
            docters[--docterCount] = nullptr; // Decrease count and nullify last pointer
            return;
        }
    }
}
