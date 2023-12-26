#include <iostream>
#include <fstream>
#include <iomanip> // For  using setw

using namespace std;

const int MAX_RECORDS = 100;  //intitallize 

struct Student {
    int studentID;   
    string studentName;
    double grades[5];
    double GPA;
};

double calculateGPA(const double grades[]) { //function to calculate the gpa 

    return 0.0; // Placeholder, replace with actual calculation
}

void displayStudent(const Student& student) { //displaing the student records
    cout << setw(10) << student.studentID << setw(20) << student.studentName << setw(10) << student.GPA << "\t";
    // Display other fields as needed
    cout << endl;
}

void readStudentRecords(Student records[], int numRecords) {
    for (int i = 0; i < numRecords; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Student ID: ";
        cin >> records[i].studentID;
        cout << "Student Name: ";
        cin.ignore(); 
        getline(cin, records[i].studentName);

        // entering grades or marks 
        cout << "Enter grades for five subjects:\n";
        for (int j = 0; j < 5; ++j) {
            cout << "Subject " << j + 1 << ": ";
            cin >> records[i].grades[j];
        }

        //  GPA calculation
        records[i].GPA = calculateGPA(records[i].grades);
    }
}

void writeToFile(const Student records[], int numRecords, const string& filename) {
    ofstream outFile(filename);

    for (int i = 0; i < numRecords; ++i) {
        outFile << records[i].studentID << "\t" << records[i].studentName << "\t" << records[i].GPA << "\t";
        // Write other fields as needed
        for (int j = 0; j < 5; ++j) {
            outFile << records[i].grades[j] << "\t";
        }
        outFile << endl;
    }

    outFile.close();
}

void readFromFile(Student records[], int& numRecords, const string& filename) {
    ifstream inFile(filename);
    numRecords = 0;

    while (inFile >> records[numRecords].studentID >> records[numRecords].studentName >> records[numRecords].GPA) {
        // Read other fields as needed
        for (int j = 0; j < 5; ++j) {
            inFile >> records[numRecords].grades[j];
        }

        numRecords++;
        if (numRecords >= MAX_RECORDS) {
            cout << "Maximum number of records reached. Exiting reading from file.\n";
            break;
        }
    }

    inFile.close();
}

void appendRecord(Student records[], int& numRecords) {
    // Implementation
    cout << "Functionality not implemented yet.\n";
}

void searchAndDeleteRecord(Student records[], int& numRecords, int studentID) {
    // Implementation
    cout << "Functionality not implemented yet.\n";
}

void insertAfterID(Student records[], int& numRecords, int afterID) {
    // Implementation
    cout << "Functionality not implemented yet.\n";
}

void insertBeforeID(Student records[], int& numRecords, int beforeID) {
    // Implementation
    cout << "Functionality not implemented yet.\n";
}

void displayAllRecords(const Student records[], int numRecords) {
    cout << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "GPA" << setw(10) << "Grades\n";
    for (int i = 0; i < numRecords; ++i) {
        displayStudent(records[i]);
    }
}

int main() {
    const int NUM_RECORDS = 3;
    Student L1[MAX_RECORDS];
    int numRecords = 0;

    // Step 1: Read at least three records from the user
    readStudentRecords(L1, NUM_RECORDS);
    numRecords += NUM_RECORDS;

    // Step 2: Write data from memory to a text file
    writeToFile(L1, numRecords, "List1.txt");

    // Step 3a: Read data from the text file into an array L1
    Student L1FromFile[MAX_RECORDS];
    int numRecordsFromFile = 0;
    readFromFile(L1FromFile, numRecordsFromFile, "List1.txt");

    // Step 3b: Implement menu-driven operations
    int choice;
    do {
        cout << "\n_______Menu_______:\n";
        cout << "1. Enter  a new record\n";
        cout << "2. Search or delete a record\n";
        cout << "3. Enter a new record to list (after)\n";
        cout << "4. Enter a new record to list (before) \n";
        cout << "5. Display all records in list \n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                appendRecord(L1FromFile, numRecordsFromFile);
                break;
            case 2:
                int deleteID;
                cout << "Enter the ID to delete: ";
                cin >> deleteID;
                searchAndDeleteRecord(L1FromFile, numRecordsFromFile, deleteID);
                break;
            case 3:
                int afterID;
                cout << "Enter the ID  to be inserted (after): ";
                cin >> afterID;
                insertAfterID(L1FromFile, numRecordsFromFile, afterID);
                break;
            case 4:
                int beforeID;
                cout << "Enter the ID To be inserted (before): ";
                cin >> beforeID;
                insertBeforeID(L1FromFile, numRecordsFromFile, beforeID);
                break;
            case 5:
                displayAllRecords(L1FromFile, numRecordsFromFile);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
