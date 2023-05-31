#include <bits/stdc++.h>
using namespace std;
class Person {
public:
    char name[50];
    int age;
    float height;
    Person(const char* personName, int personAge, float personHeight) {
        strcpy(name, personName);
        age = personAge;
        height = personHeight;
        //cout << "New person object created!" << endl;
    }
};

int main() {
   
   
   Person* p1 = new Person("Akbar", 30, 1.75);
    Person* p2 = new Person("Modhu", 25, 1.65);
    if(p1->age > p2->age){
        cout << p1->name << " is older than " << p2->name << endl;
    }else{
        cout << p2->name << " is older than " << p1->name << endl;
    }
    delete p1;
    delete p2;
    return 0;
}
