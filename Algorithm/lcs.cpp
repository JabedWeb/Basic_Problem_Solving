#include <iostream>
#include <vector>

using namespace std;

void printLongestCommonSubsequence(const string& seq1, const string& seq2) {
    int m = seq1.length();
    int n = seq2.length();

    // Create a 2D table to store the lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Calculate the lengths of LCS
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    } 

    // Find the LCS
    int lcsLength = dp[m][n];
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (seq1[i - 1] == seq2[j - 1]) {
            lcs = seq1[i - 1] + lcs;
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    // Print the LCS
    cout << "Longest Common Subsequence: " << lcs << endl;
}

int main() {
    string seq1 = "AGBGTABX";
    string seq2 = "GBXTXAYBX";

    printLongestCommonSubsequence(seq1, seq2);

    return 0;
}
