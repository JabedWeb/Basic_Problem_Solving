#include <bits/stdc++.h>
using namespace std;

class MyClass {
public:
    int value;
    void display() {
        cout << "The value is: " << value << endl;
    }
};

int main() {
    MyClass obj; 
    obj.value = 42;
    obj.display();  

    return 0;
}
