
// Why do we need dynamic memory allocation?
// Dynamic memory allocation is necessary in certain situations where the size or lifetime of objects cannot be determined at compile time. It allows programs to allocate and deallocate memory dynamically at runtime. Some common reasons for using dynamic memory allocation 


// Variable-sized data structures: When the size of a data structure, such as an array or linked list, is determined by user input or varies during program execution, dynamic memory allocation enables the creation of appropriately sized structures.


// Dynamic object creation: In cases where objects need to be created and destroyed during program execution, dynamic memory allocation allows for the creation of objects with a specific lifetime beyond their enclosing scope.













#include <bits/stdc++.h>

using namespace std;

class Student {
public:
    char name[100];
    int roll;
    char section[10];
};

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";

        cout << "Name: ";
        cin.ignore(); 
        cin.getline(students[i].name, 100);

        cout << "Roll Number: ";
        cin >> students[i].roll;

        cout << "Section: ";
        cin.ignore();
        cin.getline(students[i].section, 10);
    }

    for (int i = 0; i < numStudents; ++i) {
        cout << "Details for student " << i + 1 << ":\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "Roll Number: " << students[i].roll << "\n";
        cout << "Section: " << students[i].section << "\n";
    }

    delete[] students;

    return 0;
}
