#include "docter_patient.h"
#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp" 


using namespace std;
using json = nlohmann::json; // Assuming you are using a JSON library like nlohmann/json

int main()
{
    Docter* docter;
    Patient* patient;
    docter = new Docter[20];
    patient = new Patient[60];
    int choice;
    int patientCount = 0, docterCount = 0;
    loadData(patient, patientCount, docter, docterCount);
    do
    {
        cout<<"Menu: \n1.Add Doctor\n2.Add Patient \n3.Assign Patient to Docter\n4.Check if Docter has a Patient"
        <<"\n5.Delete Patient\n6.Delete Doctor\n7.Delete all Doctors\n8.Delete all Patients"
        <<"\n9.Display all Doctors\n10.Save and Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer
        switch (choice) 
        {
        case 1:
        {
            cout << "Adding Docter..." << endl;
            string docName;
            char addMore='y';
            while ((addMore == 'y' || addMore == 'Y') && docterCount< 20)
            {
                cout << "Enter Docter Name: ";
                getline(cin, docName);
                for(int i = 0; i < docterCount; ++i) 
                {
                    if(docter[i].getname() == docName) 
                    {
                        cout << "Docter already exists!" << endl;
                        docName = ""; // Reset docName to avoid adding duplicate
                        break;
                    }
                }
                if(docName == "")
                {
                    continue; // Skip adding if name is duplicate
                }
                docter[docterCount].setName(docName);
                cout << "Docter added successfully!" << endl;                        cout << "Do you want to add another Docter? (y/n): ";
                cin >> addMore;
                cin.ignore(); 
                docterCount++;                   
            }
            if(docterCount == 20)
            {
                cout << "Maximum number of docters reached." << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Adding Patient..." << endl;
                string patName;
                char addMore = 'y';
                while ((addMore == 'y' || addMore == 'Y') && patientCount < 60)
                {
                    cout << "Enter Patient Name: ";
                    getline(cin, patName);
                    for(int i = 0; i < patientCount; ++i) 
                    {
                        if(patient[i].getName() == patName) 
                        {
                            cout << "Patient already exists!" << endl;
                            patName = ""; // Reset patName to avoid adding duplicate
                            break;
                        }
                    }
                    if(patName == "")
                    {
                        continue; // Skip adding if name is duplicate
                    }
                    patient[patientCount].setName(patName);
                    cout << "Patient added successfully!" << endl;
                    cout << "Do you want to add another Patient? (y/n): ";
                    cin >> addMore;
                    cin.ignore(); 
                    patientCount++;
                }
                if(patientCount == 60)
                {
                    cout << "Maximum number of patients reached." << endl;
                }
                break;
            }
        case 3:
        {
            char addMore= 'y';
            do
            {
                string docName, patName;
                bool docfound = false, patfound = false, dpCount = false;
                cout << "Assigning Patient to Docter..." << endl;
                cout << "Enter Docter Name: ";
                getline(cin, docName);
                for(int i = 0; i < docterCount; ++i) 
                {
                    if(docter[i].getname() == docName)
                    {
                        cout << "Enter Patient Name: ";
                        getline(cin, patName);
                        docfound = true;
                        for(int j=0; j<patientCount; j++)
                        {
                            if (patient[j].getName() == patName) 
                            {
                                patfound = true;
                                if(patient[j].getDocterCount() < 5 && docter[i].getPatientCount() < 10)
                                {
                                    docter[i].addPatient(&patient[j]);
                                    patient[j].addDocter(&docter[i]);
                                    cout << "Patient assigned to Docter successfully!" << endl;
                                    dpCount = true;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(!docfound) 
                {
                    cout << "Docter not found!" << endl;
                }
                if(!patfound && docfound) 
                {
                    cout << "Patient not found!" << endl;
                }
                if(!dpCount && patfound && docfound) 
                {
                    cout << "Docter or Patient has reached maximum limit." << endl;
                }
                cout << "Do you want to assign another Patient to Docter? (y/n): ";
                cin >> addMore;
                cin.ignore(); // Clear the newline character from the input buffer
            } while (addMore == 'y' || addMore == 'Y');
            break;
        }
        case 4:
        {
            string docterName;
            bool found = false, pNum=false;
            cout << "Checking if Docter has a Patient..." << endl;
            cout << "Enter Docter Name: ";
            getline(cin, docterName);
            for(int i = 0; i < docterCount; ++i) 
            {
                if(docter[i].getname() == docterName) 
                {
                    found = true;
                    if(docter[i].getPatientCount() > 0) 
                    {
                        pNum = true;
                        Patient** patientsDis = docter[i].getPatients();
                        cout << "Docter has the following patients:" << endl;
                        for(int j = 0; j < docter[i].getPatientCount(); ++j) 
                        {
                            cout << "Patient " << j + 1 << ": " << patientsDis[j]->getName() << endl;
                        }
                    }
                } 
            }
            if(!found) 
            {
                cout << "Docter not found!" << endl;
            } 
            else if(!pNum && found) 
            {
                cout << "Docter has no patients." << endl;
            }
            break;
        }  
        case 5:
        {
            string patName;
            bool found = false;
            if(patientCount == 0) 
            {
                cout << "No patients available to delete." << endl;
                break;
            }
            cout << "Deleting Patient..." << endl;
            cout << "Enter Patient Name: ";
            getline(cin, patName);
            for(int i = 0; i < patientCount; ++i) 
            {
                if(patient[i].getName() == patName) 
                {
                    found = true;
                    for(int j = i; j < (patientCount-1); j++) 
                    {
                        patient[j] = patient[j + 1]; // Shift patients to the left
                    }
                    patient[--patientCount] = Patient();
                    for(int k = 0; k < docterCount; ++k) 
                    {
                        docter[k].DeletePatient(patName); // Remove patient from all docters
                    }
                    cout << "Patient deleted successfully!" << endl;
                    break;
                }
            }
            if(!found) 
            {
                cout << "Patient not found!" << endl;
            }
            break;
        }    
        case 6:
        {
            string docName;
            bool found = false;
            if(docterCount == 0) 
            {
                cout << "No docters available to delete." << endl;
                break;
            }
            cout << "Deleting Docter..." << endl;
            cout << "Enter Docter Name: ";
            getline(cin, docName);
            for(int i = 0; i < docterCount; ++i) 
            {
                if(docter[i].getname() == docName) 
                {
                    found = true;
                    for(int j = i; j < docterCount-1; j++) 
                    {
                        docter[j] = docter[j + 1];
                    }
                    docter[docterCount-1] = Docter();
                    docterCount--;
                    for(int k = 0; k < patientCount; ++k) 
                    {
                        patient[k].DeleteDocter(docName); 
                    }
                    cout << "Docter deleted successfully!" << endl;
                    break;
                }
            }
            if(!found) 
            {
                cout << "Docter not found!" << endl;
            }
            break;
        }
        case 7:
        {
            if(docterCount == 0) 
            {
                cout << "No docters available to delete." << endl;
                break;
            }
            char confirm;
            cout<<"This will delete all docters and remove their associations with patients."<<endl;
            cout<<"Do you really want to delete all docters? (y/n): ";
            cin>>confirm;
            cin.ignore(); // Clear the newline character from the input buffer
            if(confirm != 'y' && confirm != 'Y') 
            {
                cout << "Operation cancelled." << endl;
                break;
            }
            for(int i = 0; i < docterCount; ++i) 
            {
                for(int j = 0; j < patientCount; ++j) 
                {
                    patient[j].DeleteDocter(docter[i].getname()); 
                }
                docter[i] = Docter(); // Reset each docter
            }
            docterCount = 0; // Reset docter count
            cout << "All docters deleted successfully!" << endl;
            break;
        }
        case 8:
        {
            if(patientCount == 0) 
            {
                cout << "No patients available to delete." << endl;
                break;
            }
            char confirm;
            cout<<"This will delete all patients and remove their associations with docters."<<endl;
            cout<<"Do you really want to delete all patients? (y/n): ";
            cin>>confirm;  
            cin.ignore(); // Clear the newline character from the input buffer
            if(confirm != 'y' && confirm != 'Y') 
            {
                cout << "Operation cancelled." << endl;
                break;
            }
            for(int i = 0; i < patientCount; ++i) 
            {
                for(int j = 0; j < docterCount; ++j) 
                {
                    docter[j].DeletePatient(patient[i].getName()); 
                }
                patient[i] = Patient(); // Reset each patient
            }
            patientCount = 0; // Reset patient count
            cout << "All patients deleted successfully!" << endl;
            break;
        }
        case 9:
        {
            if(docterCount == 0) 
            {
                cout << "No docters available to display." << endl;
                break;
            }
            cout << "Displaying all Docters and their Patients..." << endl;
            for(int i = 0; i < docterCount; ++i) 
            {
                cout << "Docter " << i + 1 << ": " << docter[i].getname() << endl;
                if(docter[i].getPatientCount() > 0) 
                {
                    Patient** patientsDis = docter[i].getPatients();
                    cout<<"Number of assigned patients: "<<docter[i].getPatientCount()<<endl;
                    cout << "  Patients:" << endl;
                    for(int j = 0; j < docter[i].getPatientCount(); ++j) 
                    {
                        cout << "    Patient " << j + 1 << ": " << patientsDis[j]->getName() << endl;
                    }
                } 
                else 
                {
                    cout << "  No patients assigned." << endl;
                }
            }
            break;
        }
        case 10:
        {
            saveData(patient, patientCount, docter, docterCount);
            delete[] docter;
            delete[] patient;
            return 0;    
        }
        default:
        {
            cout << "Invalid choice!" << endl;
            break;
        }
        }

    } while (choice != 10);
}