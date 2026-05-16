main.cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;

    void addStudent() {
        ofstream file("students.txt", ios::app);

        cout << "Enter Roll Number: ";
        cin >> roll;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;

        file << roll << " " << name << " " << marks << endl;

        file.close();

        cout << "\nStudent Added Successfully!\n";
    }

    void displayStudents() {
        ifstream file("students.txt");

        int r;
        string n;
        float m;

        cout << "\n--- Student Records ---\n";

        while (file >> r >> n >> m) {
            cout << "Roll Number : " << r << endl;
            cout << "Name        : " << n << endl;
            cout << "Marks       : " << m << endl;
            cout << "----------------------\n";
        }

        file.close();
    }
};

int main() {
    Student s;
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                s.addStudent();
                break;

            case 2:
                s.displayStudents();
                break;

            case 3:
                cout << "Program Closed.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}