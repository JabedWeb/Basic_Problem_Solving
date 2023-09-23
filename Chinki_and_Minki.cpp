
#include <bits/stdc++.h>
using namespace std;

int minimizeCoinDifference(vector<int>& coins) {
    int totalSum = accumulate(coins.begin(), coins.end(), 0);
    int targetSum = totalSum / 2;

    int n = coins.size();

    // Initialize a 2D DP array to store achievable sums
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

    // Base case: an achievable sum of 0 is always possible
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // Find the closest achievable sum to targetSum
    int closestSum = targetSum;
    while (!dp[n][closestSum])
        closestSum--;

    // Calculate the minimum difference
    int minDifference = totalSum - 2 * closestSum;

    return minDifference;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> coins(N);
        for (int i = 0; i < N; ++i)
            cin >> coins[i];

        int minDifference = minimizeCoinDifference(coins);
        cout << minDifference << endl;
    }

    return 0;
}
