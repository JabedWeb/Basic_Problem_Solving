/*
Make It
Problem
Submissions
Leaderboard
Discussions
Problem Statement

You will be given a positive integer N. You will start from 1 and do some steps (possibly zero).

In each step you can choose one of the following:

Add 3 with the current value
Multiply by 2 with the current value
Can you tell if you can reach N by using any number of steps you want.

Input Format

First line will contain T, the number of test cases.
In each test case you will be given N.
Constraints

1 <= T <= 1000
1 <= N <= 10^5
Output Format

Print "YES" if you can reach N, "NO" otherwise.
Sample Input 0

5
1
3
5
15
16
Sample Output 0

YES
NO
YES
NO

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool dp[n + 5];
        for (int i = 0; i <= n; i++){
            dp[i] = false;
        }
        dp[1] = true;
        for (int i = 1; i <= n; i++)
        {
            if (dp[i])
            {
                if (i + 3 <= n)
                    dp[i + 3] = true;
                if (i * 2 <= n)
                    dp[i * 2] = true;
            }
        }  
        if (dp[n])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}