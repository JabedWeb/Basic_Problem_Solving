/*
Problem Statement

Zarif has received M marks in his final term exam out of 1000. However, he wishes to obtain a perfect score of 1000 marks just once in his life. His wish was granted by a fairy who provided him with a list of N marks to choose from. Zarif needs to select any number of marks from that list, and he can choose each mark any number of times he wants. But this time the fairy told him to choose the minimum possible number of marks he can.

Can you tell what will be the minimum number of marks Zarif will need to fulfill his dream. If it is not possible then print -1.

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain N and M.
Second line of each test case will contain a list A of N marks.
Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= M <= 1000
1 <= A[i] <= 100; 0 <= i < N
Output Format

Output minimum number of marks needed if he can obtain perfect score of 1000, -1 otherwise.
Sample Input 0

5
5 1000
1 2 3 4 5
5 999
2 3 4 5 6
2 900
30 40
3 904
2 6 5
2 904
2 5
Sample Output 0

0
-1
3
16
21
*/


#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int t;
        cin>>t;
        int s=1000-t;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int dp[n+1][s+1];
        dp[0][0]=0;
        for(int i=1;i<=s;i++)
         dp[0][i]=MAX_N;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(a[i-1]<=j && dp[i][j-a[i-1]]!=MAX_N){
                    dp[i][j]=min(1+dp[i][j-a[i-1]],dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[n][s]==MAX_N)cout<<-1<<endl;
        else cout<<dp[n][s]<<endl;

    }
    return 0;
}