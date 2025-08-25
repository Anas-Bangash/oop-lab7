#include "docter_patient.h"
#include <iostream>
#include <string>
#include<fstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

Docter::Docter() : name(""), patientCount(0)
{ 
    for (int i = 0; i < 10; ++i)
    {
        patients[i] = nullptr;
    }
}
void Docter::setName(string nm)
{
    name = nm;
}
string Docter::getname() 
{
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
            for (int j = i; j <(patientCount-1) ; j++) 
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
Docter** Patient::getDocters() 
{
    return docters; 
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
            for (int j = i; j < (docterCount - 1); j++) 
            {
                docters[j] = docters[j + 1]; // Shift docters to the left
            }
            docters[--docterCount] = nullptr; // Decrease count and nullify last pointer
            return;
        }
    }
}
void saveData(Patient* patient, const int& patientCount, Docter* docter, const int& docterCount)
{   
    ofstream outfile("data.json");
    json j;
    if (!outfile.is_open()) 
    {
        cout << "Error opening file for writing." << endl;
        return;
    }
    else
    {
        j["patientCount"] = patientCount;
        j["docterCount"] = docterCount;
        for (int i = 0; i < patientCount; i++)
        {
            
            j["patients"][i]["name"] = patient[i].getName();
            if(patient[i].getDocterCount()!=0)
            {
                Docter** docters = patient[i].getDocters();
                j["patients"][i]["docters"] = json::array();
                for(int d=0; d < patient[i].getDocterCount(); d++)
                {
                    j["patients"][i]["docters"].push_back(docters[d]->getname());
                }
            }

        }
        for(int i=0; i < docterCount; i++)
        {
            j["docters"][i]["name"] = docter[i].getname();
            if(docter[i].getPatientCount() != 0)
            {
                Patient** patients = docter[i].getPatients();
                j["docters"][i]["patients"] = json::array();
                for(int p=0; p < docter[i].getPatientCount(); p++)
                {   
                    j["docters"][i]["patients"].push_back(patients[p]->getName());
                }
            }
        }
        outfile << j.dump(4); 
        cout<<"Data saved successfully!"<<endl;
        outfile.close();
    }
}
void loadData(Patient* patient,int& patientCount, Docter* docter, int& docterCount)
{
    ifstream infile("data.json");
    json j;
    if (!infile.is_open()) 
    {
        cout << "Error opening file for reading." << endl;
        return;
    }
    else
    {
        infile >> j;
        patientCount = j["patientCount"];
        docterCount = j["docterCount"];
        for(int i=0; i<patientCount; i++)
        {
            patient[i].setName(j["patients"][i]["name"]);
        }
        for(int i=0; i<docterCount; i++)
        {
            docter[i].setName(j["docters"][i]["name"]);
        }
        for(int i=0; i<patientCount; i++)
        {
            if(j["patients"][i].contains("docters"))
            {
                int assignedDoctorCount = j["patients"][i]["docters"].size();
                for(int d=0; d < assignedDoctorCount; d++)
                {             
                    string docName = j["patients"][i]["docters"][d];
                    for(int k = 0; k < docterCount; k++)
                    {
                        if(docter[k].getname() == docName)
                        {
                            patient[i].addDocter(&docter[k]);
                            break;
                        }
                    }
                }
            }
        }  
        for(int i=0; i<docterCount; i++)
        {
            if(j["docters"][i].contains("patients"))
            {
                int assignedPatientCount = j["docters"][i]["patients"].size();
                for(int p=0; p < assignedPatientCount; p++)
                {
                 string patName = j["docters"][i]["patients"][p];
                    for(int k = 0; k < patientCount; k++)
                    {
                        if(patient[k].getName() == patName)
                        {
                            docter[i].addPatient(&patient[k]);
                            break;
                        }
                    }
                }
            }
        }     
        cout<<"Data loaded successfully!"<<endl;
        infile.close();
    }
}