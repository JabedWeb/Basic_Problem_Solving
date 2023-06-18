#include <iostream>
using namespace std;

int main() {
    int numTests;
    cout << "Enter the number of test cases: "<<endl;
    cin >> numTests;

    while (numTests--) {
        int deep, ball, ans = 1;
        cout << "Enter the depth and ball number: "<<endl;
        cin >> deep >> ball;

        for (int i = 1; i < deep; i++) {
            if (ball % 2) {
                ans = ans * 2;
                ball = (ball + 1) / 2;
            } else {
                ans = ans * 2 + 1;
                ball /= 2;
            }
        }
        
        cout << "Final position: " << ans << endl;
    }

    return 0;
}



// 5
// 4 2
// 3 4
// 10 1
// 2 2
// 8 128
// -1


// Enter the number of test cases: 5
// Enter the depth and ball number: 4 2
// Final position: 12
// Enter the depth and ball number: 3 4
// Final position: 7
// Enter the depth and ball number: 10 1
// Final position: 512
// Enter the depth and ball number: 2 2
// Final position: 3
// Enter the depth and ball number: 8 128
// Final position: 255
