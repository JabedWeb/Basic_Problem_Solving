#include <bits/stdc++.h>
using namespace std;

class MyClass {
public:
    int value;

    void printValue() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    MyClass obj;
    obj.value = 42;

    MyClass* ptr = &obj;
    ptr->printValue();

    return 0;
}
