#include <bits/stdc++.h>
using namespace std;    
class Example {
public:
    int num;
    char character;
};

int main() {
    Example obj;

    cout << "Size of Example object: " << sizeof(obj) << " bytes" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " byte" << endl;


    // Size of Example object: 8 bytes
    // Size of int: 4 bytes
    // Size of char: 1 byte
    //In this specific case, the compiler has introduced 3 bytes of padding between the num and character data members, resulting in a total size of 8 bytes for the Example object.
    return 0;
}
