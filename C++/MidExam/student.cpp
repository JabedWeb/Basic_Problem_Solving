#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    char name[50];
    float height;
    int age;


    Person(const char* personName, float personHeight, int personAge) {
        strcpy(name, personName);
        height = personHeight;
        age = personAge;
        cout << "New person object created!" << endl;
    }
};

int main() {

    Person* personObj = new Person("John Doe", 1.75, 30);

    cout << "Person Name: " << personObj->name << endl;
    cout << "Person Height: " << personObj->height << endl;
    cout << "Person Age: " << personObj->age << endl;

    delete personObj;

    return 0;
}
