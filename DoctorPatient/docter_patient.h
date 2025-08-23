#ifndef DOCTER_PATIENT_H
#define DOCTER_PATIENT_H

#include<iostream>
#include<string>

using namespace std;

class Patient;
class Docter
{
    private:
    string name;
    Patient* patients[10];
    int patientCount;
    public:
    Docter();
    void setName(string nm);
    string getname();
    void addPatient(Patient* p);
    bool hasPatient(string search);
    int getPatientCount();
    Patient** getPatients();
    void DeletePatient(string patName);
};

class Patient
{
    private:
    string name;
    Docter* docters[5];
    int docterCount;
    public:
    Patient();
    void setName(string nm);
    string getName();
    void addDocter(Docter* d);
    bool hasDocter(string search);
    int getDocterCount();
    Docter** getDocters(); // Added getter for docters
    void DeleteDocter(string docName);
};
void saveData(Patient* patient, const int& patientCount, Docter* docter, const int& docterCount);
void loadData(Patient* patient, Docter* docter);

#endif