//import the folder Algorithm to the project folder
//import the folder Algorithm to the project folder


import java.util.ArrayList;
import java.util.Arrays;

public class lcs {
    public static void printLongestCommonSubsequence(String seq1, String seq2) {
        int m = seq1.length();
        int n = seq2.length();

        // Create a 2D table to store the lengths of LCS
        int[][] dp = new int[m + 1][n + 1];

        // Calculate the lengths of LCS
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Find the LCS
        int lcsLength = dp[m][n];
        StringBuilder lcs = new StringBuilder();
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                lcs.insert(0, seq1.charAt(i - 1));
                --i;
                --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                --i;
            } else {
                --j;
            }
        }

        // Print the LCS
        System.out.println("Longest Common Subsequence: " + lcs.toString());
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";

        printLongestCommonSubsequence(seq1, seq2);
    }
}




// https://chatbot.theb.ai/#/chat/1002