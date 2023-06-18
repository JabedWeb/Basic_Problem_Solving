#include <iostream>
using namespace std;

int getFinalPosition(int deep, int ball) {
    if (deep == 1) return 1; // base case

    if (ball % 2) { // if ball is odd
        return 2 * getFinalPosition(deep-1, (ball+1)/2);
    } else { // if ball is even
        return 2* getFinalPosition(deep-1, ball/2)+1 ;
    }
}

int main() {
    int numTests;
    cout << "Enter the number of test cases: "<<endl;
    cin >> numTests;

    while (numTests--) {
        int deep, ball;
        cout << "Enter the depth and ball number: "<<endl;
        cin >> deep >> ball;
        
        int ans = getFinalPosition(deep, ball);
        cout << "Final position: " << ans << endl;
    }

    return 0;
}
