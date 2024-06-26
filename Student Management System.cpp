/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> studentNames;
vector<string> studentSubjects;
vector<string> studentGrades;

void addRecord() {
    string name, subject, grade;
    cout << "Enter student name: ";
    cin >> name;
    
    cout << "Enter student subject: ";
    cin >> subject;
    
    cout << "Enter student grade: ";
    cin >> grade;
    
    studentNames.push_back(name);
    studentSubjects.push_back(subject);
    studentGrades.push_back(grade);

    cout << "Record added successfully.\n";
}

void printRecords() {
    if (studentNames.empty()) {
        cout << "No record found\n";
        return;
    }
    for (size_t i = 0; i < studentNames.size(); i++) {
        cout << i + 1 << ". Name: " << studentNames[i]
             << ", Subject: " << studentSubjects[i]
             << ", Grade: " << studentGrades[i] << endl;
    }
}

void updateRecord() {
    if (studentNames.empty()) {
        cout << "No record found\n";
        return;
    }
    int recordNumber;
    cout << "Enter record number: ";
    cin >> recordNumber;
    
    if (recordNumber < 1 || recordNumber > studentNames.size()) {
        cout << "Invalid record number.\n";
        return;
    }
    
    string name, subject, grade;
    cout << "Enter new student name: ";
    cin >> name;
    
    cout << "Enter new student subject: ";
    cin >> subject;
    
    cout << "Enter new student grade: ";
    cin >> grade;
    
    studentNames[recordNumber - 1] = name;
    studentSubjects[recordNumber - 1] = subject;
    studentGrades[recordNumber - 1] = grade;

    cout << "Record updated successfully.\n";
}

void deleteRecord() {
    if (studentNames.empty()) {
        cout << "No record found\n";
        return;
    }
    int recordNumber;
    cout << "Enter record number: ";
    cin >> recordNumber;
    
    if (recordNumber < 1 || recordNumber > studentNames.size()) {
        cout << "Invalid record number.\n";
        return;
    }
    studentNames.erase(studentNames.begin() + recordNumber - 1);
    studentSubjects.erase(studentSubjects.begin() + recordNumber - 1);
    studentGrades.erase(studentGrades.begin() + recordNumber - 1);

    cout << "Record deleted successfully.\n";
}

void clearAllRecords() {
    studentNames.clear();
    studentSubjects.clear();
    studentGrades.clear();
    cout << "All records cleared successfully.\n";
}

void displayMenu() {
    cout << "\nStudent Record Management System\n";
    cout << "1. Add Record\n";
    cout << "2. Display Records\n";
    cout << "3. Update Record\n";
    cout << "4. Delete Record\n";
    cout << "5. Clear All Records\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                printRecords();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                clearAllRecords();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

