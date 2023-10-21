/*

123 Ka 4
Problem
Submissions
Leaderboard
Discussions
Problem Statement

You will be given an integer number N and you need to create this pattern for the corresponding inputs.

For example,

If N=4, the pattern pattern look like this,
image

If N=7, the pattern pattern look like this,
image

Input Format

You will be given a positive integer N as input.
Constraints

1 <= N <= 9
Output Format

Output the pattern
Sample Input 0

4
Sample Output 0

1234
2  4
3  4
4444
Sample Input 1

1

Sample Output 1

1


Sample Input 3

7
Sample Output 0

1234567
2     7
3     7
4     7
5     7
6     7
7777777
Sample

*/

#include <bits/stdc++.h>
using namespace std;

void pattern(int n) {
    
    if(n==1) {
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << i;
    }
    cout << endl;

    for (int i = 2; i < n; i++) {
        cout << i;
        for (int j = 2; j < n; j++) {
            cout << " ";
        }
        cout << n << endl;
    }

    for (int i = 1; i <= n; i++) {
        cout << n;
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;

    pattern(n);

    return 0;
}
