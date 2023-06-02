#include<bits/stdc++.h>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* Array = new int[size];

    for (int i = 0; i < size; ++i) {
        Array[i] = i * 2;
    }

    cout << "Elements of the dynamic array: ";
    for (int i = 0; i < size; ++i) {
        cout << Array[i] << " ";
    }
    cout << endl;

    delete[] Array;  

    return 0;
}
