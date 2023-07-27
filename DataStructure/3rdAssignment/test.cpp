/*
Problem Statement

Arif, the magician is putting some magic colors in a box serially. But he is not providing any divider between the colors. So, the color may be mix up instantly.

There are three types of colors- Red, Green and Blue. How they could mix up is given below -

Red+Blue = Purple
Red+Green = Yellow
Blue+Green = Cyan
And there are some other problems. If two same type of colors mix up, they will vanish each other. For example if two Purple colors get together, both of them will be vanished.

Can you help the magician to get the final colors that will be in the box?

Input Format

First line will contain T, the number of test cases.
Next line will contain N, number of colors in the box.
Next line will contain N characters (R,G,B only) , first capital letter of the color.
Constraints

0 < T <= 100
0 < N <= 100
Output Format

Output the first capital letter of the colors that are saved finally. If there are no colors in the box, the output could be empty in that case.
Sample Input 0

2
3
RBG
4
RGBB
Sample Output 0

PG
Y
Sample Input 1

6
6
RGGRRG
6
RGRGRG
4
RGGR
5
RGGGR
4
RGGB
18
RBRBRBGRBRRGBGGBGB
Sample Output 1

Y
Y

YR
YC
PYPYC


*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int sz;
        cin >> sz;
        string s;
        cin >> s;
        stack<char> st;
        for (char c : s) {
            if (!st.empty()) {
                if(st.top() == c) {
                    st.pop();
                }
                else if ((st.top() == 'R' && c == 'B') || (st.top() == 'B' && c == 'R')) {
                    st.pop();
                    if (!st.empty() && st.top() == 'P') {
                        st.pop();
                    } else {
                        st.push('P');
                    }
                } else if ((st.top() == 'R' && c == 'G') || (st.top() == 'G' && c == 'R')) {
                    st.pop();
                    if (!st.empty() && st.top() == 'Y') {
                        st.pop();
                    } else {
                        st.push('Y');
                    }
                } else if ((st.top() == 'B' && c == 'G') || (st.top() == 'G' && c == 'B')) {
                    st.pop();
                    if (!st.empty() && st.top() == 'C') {
                        st.pop();
                    } else {
                        st.push('C');
                    }
                } else {
                    st.push(c);
                }
            } else {
                st.push(c);
            }
        }
        stack<char> st2;
        while (!st.empty()) {
            st2.push(st.top());
            st.pop();
        }
        while (!st2.empty()) {
            cout << st2.top();
            st2.pop();
        }
        cout << endl;
    }
    return 0;
}
