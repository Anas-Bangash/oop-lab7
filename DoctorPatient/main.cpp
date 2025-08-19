#include "docter_patient.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Docter* docter;
    Patient* patient;
    docter = new Docter[20];
    patient = new Patient[20];
    int choice;
    int patientCount = 0, docterCount = 0;
    do
    {
        cout<<"Menu: \n1. Add Docter\n2. Add Patient\n3. Assign Patient to Docter\n4. Check if Docter has a Patient\n5.Delete Patient\n6.Delete Doctor\n7. Exit\n";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer
        switch (choice) 
        {
            case 1:
            { 
                cout << "Adding Docter..." << endl;
                string docName;
                char addMore;
                do 
                {
                    cout << "Enter Docter Name: ";
                    getline(cin, docName);
                    docter[docterCount].setName(docName);
                    cout << "Docter added successfully!" << endl;
                    cout << "Do you want to add another Docter? (y/n): ";
                    cin >> addMore;
                    cin.ignore(); 
                    docterCount++;                   
                }while ((addMore == 'y' || addMore == 'Y') && docterCount< 20);
                break;
            }
            case 2:
            {
                string patName;
                char addMore;
                do 
                {
                    cout << "Adding Patient..." << endl;
                    cout << "Enter Patient Name: ";
                    getline(cin, patName);
                    patient[patientCount].setName(patName);
                    cout << "Patient added successfully!" << endl;
                    cout << "Do you want to add another Patient? (y/n): ";
                    cin >> addMore;
                    cin.ignore();
                    patientCount++;
                }while ((addMore == 'y' || addMore == 'Y') && patientCount < 20);
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
                    if(!patfound) 
                    {
                        cout << "Patient not found!" << endl;
                    }
                    if(!dpCount) 
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
                else if(!pNum) 
                {
                    cout << "Docter has no patients." << endl;
                }
                break;
            }  
            case 5:
            {
                string patName;
                bool found = false;
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
                        patientCount--;
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
                            docter[j] = docter[j + 1]; // Shift docters to the left
                        }
                        docterCount--;
                        for(int k = 0; k < patientCount; ++k) 
                        {
                            patient[k].DeleteDocter(docName); // Remove docter from all patients
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
                cout << "Exiting..." << endl;
                break;
            }
            default:
            {
                cout << "Invalid choice!" << endl;
                break;
            }
        }

    } while (choice != 7);

    delete[] docter;
    delete[] patient;
    return 0;    
}