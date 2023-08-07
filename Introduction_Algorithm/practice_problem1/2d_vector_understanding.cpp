#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize a 2D vector with 3 rows and 4 columns, all initialized to 0
    vector<vector<int>> myVector(3, vector<int>(4, 0));

    // Access and modify elements in the 2D vector
    myVector[0][1] = 5;
    myVector[1][2] = 10;
    myVector[2][3] = 15;

    // Print the 2D vector
    for (int i = 0; i < myVector.size(); i++) {
        for (int j = 0; j < myVector[i].size(); j++) {
            cout << myVector[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
