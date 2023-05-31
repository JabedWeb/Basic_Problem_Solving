#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    int id;

    Student(int studentId) : id(studentId) {}
};

Student* getDefaultStudent() {
    static Student defaultStudent(12345);
    return &defaultStudent;
}

int main() {
    Student* studentPtr = getDefaultStudent();
   cout << "Default Student ID: " << studentPtr->id <<endl;

    return 0;
}
