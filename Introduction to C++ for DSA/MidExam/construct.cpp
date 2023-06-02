#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    char name[50];
    int id;
    char section[10];

    Student(const char* studentName, int studentID, const char* studentSection) {
        strcpy(name, studentName);
        id = studentID;
        strcpy(section, studentSection);
        cout << "New student object created!" << endl;
    }
};

int main() {

    Student student1("John Doe", 12345, "A");
    Student student2("Jane Smith", 54321, "B");


    cout << "Student 1: " << student1.name << ", ID: " << student1.id << ", Section: " << student1.section << endl;
    cout << "Student 2: " << student2.name << ", ID: " << student2.id << ", Section: " << student2.section << endl;

    return 0;
}
