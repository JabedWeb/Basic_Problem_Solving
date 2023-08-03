/*
Problem Statement

You will be given a list A of size N. You need to sort those values in descending order and also you need to remove any duplicate values from the list and print the final outcome.

Input Format

First line will contain T, the number of test cases.
The first line of every test case will contain N.
The second line of every test case will contain the list A of size N.
Constraints

1 <= T <= 100
1 <= N <= 10^4
-10^9 <= A[i] <= 10^9, Here A[i] means the values of list A.
Output Format

Output the final list.
Sample Input 0

4
5
20 10 40 50 30
10
10 20 40 20 10 30 50 10 20 40
5
20 20 20 20 20
4
10 30 10 30
Sample Output 0

50 40 30 20 10 
50 40 30 20 10 
20 
30 10 

*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> st;
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            st.insert(val);
        }

        vector<int> vec;
        for (auto it = st.begin(); it != st.end(); it++) {
            vec.push_back(*it);
        }

        for (int k = vec.size() - 1; k >= 0; k--) {
            cout << vec[k] << " ";
        }

        cout << endl;
        st.clear();
    }

    return 0;
}