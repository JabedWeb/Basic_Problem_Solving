/*
Subsets
Problem
Submissions
Leaderboard
Discussions
Problem Statement

Alice and Bob are facing a fun mathematical challenge involving a set of positive numbers. They have an array A of N numbers and want to figure out the number of ways to divide the array into two subsets such that the absolute difference between the sums of the elements in these subsets equals a given number D. Help them to do it.

Note: As the answer could be very big, print the answer modulo 1e9+7.

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain N and D.
Next line of each test case will contain the array A.
Constraints

1 <= T <= 100
2 <= N <= 1000
1 <= D <= 100
1 <= A[i] <= 100
Output Format

Output the number of ways to do the given task.
Sample Input 0

1
5 3
1 2 3 4 5
Sample Output 0

3
Explanation 0

In the first test case, you can divide them in 3 ways so that the difference remains 3.
1. {1,2,3} and {4,5}
2. {2,3,4} and {1,5}
3. {2,4} and {1,3,5}

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, D;
        cin >> N >> D;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        int sum = accumulate(A.begin(), A.end(), 0);

        if (sum % 2 != D % 2) {
            cout << 0 << endl;
            continue;
        }

        int target = (sum - D) / 2;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = target; j >= A[i]; j--) {
                dp[j] += dp[j - A[i]];
                dp[j] %= 1000000007;
            }
        }

        cout << dp[target] << endl;
    }

    return 0;
}