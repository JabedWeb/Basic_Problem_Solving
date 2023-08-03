/*
Problem Statement

You will be given a list A of size N. Then you will be given Q queries, for each query there will be some commands. Commands are given below -

0 X -> Insert X into the list. Then print the current minimum value from the list.
1 -> Print the minimum value from the list.
2 -> Delete the minimum value from the list and print the current minimum value from the list.
Note: If the list is empty and you can't print anything then you should print "Empty".

Input Format

First line will contain N.
Second line will contain the list A of size N.
Third line will contain Q.
Next Q lines will contain the commands.
Constraints

1 <= N+Q <= 10^5
-10^9 <= A[i] <= 10^9 ; Here A[i] means the values of the list A.
-10^9 <= X <= 10^9
Output Format

For each command, print as asked from the list.
Sample Input 0

4
10 -10 -5 -20
10
1
2
2
2
2
0 10
1
2
0 20
1
Sample Output 0

-20
-10
-5
10
Empty
10
10
Empty
20
20
Sample Input 1

6
45 -30 83 -99 19 75 
9
1
2
2
0 32
0 6
2
2
0 -86
1
Sample Output 1

-99
-30
19
19
6
19
32
-86
-86

*/


#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int command;
        cin >> command;

        if (command == 0) {
            int X;
            cin >> X;
            pq.push(X);
            cout << pq.top() << endl;
        } else if (command == 1) {
            if (pq.empty()) {
                cout << "Empty" << endl;
            } else {
                cout << pq.top() << endl;
            }
        } else if (command == 2) {
            if (pq.empty()) {
                cout << "Empty" << endl;
            } else {
                pq.pop();
                if (pq.empty()) {
                    cout << "Empty" << endl;
                } else {
                    cout << pq.top() << endl;
                }
            }
        }
    }

    return 0;
}