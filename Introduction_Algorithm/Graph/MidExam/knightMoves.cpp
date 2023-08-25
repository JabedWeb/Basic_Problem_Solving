/*
Knight Moves
Problem
Submissions
Leaderboard
Discussions
Problem Statement

You will be given a chessboard of NxM size. You can move anywhere in the chessboard freely. You will be given two cells - the knight's cell K(Ki and Kj), and the queen's cell Q(Qi and Qj). You need to tell the minimum number of steps for the knight to attack the queen if the queen doesn't move.

A knight move in 8 directions. The directions are given below:image

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain N and M.
Second line of each test case will contain Ki and Kj.
Third line of each test case will contain Qi and Qj.
Constraints

1 <= T <= 100
1 <= N, M <= 100
0 <= Ki, Qi < N
0 <= Kj, Qj < M
Output Format

Output the minimum number of steps for the knight to reach the queen. If you can't reach to queen, print -1.
Sample Input 0

4
8 8
0 0
7 7
5 6
0 1
0 1
4 4
0 0
0 1
2 2
0 0
0 1
Sample Output 0

6
0
3
-1


*/
#include <bits/stdc++.h>
using namespace std;
int n,m;
int si,sj;
int di,dj;
const int N=1e2+7;
int visited[N][N];
int des[N][N];

vector <pair<int,int>> dire = {
    {-1, -2}, {-2, -1}, {1, -2}, {2, -1},
    {-1, 2}, {-2, 1}, {1, 2}, {2, 1}
};

bool isValid(int i ,int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void bfs(){
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=false;
            des[i][j]=0;
        }
    }
    queue <pair <int,int>> q;
    q.push({si,sj});
    des[si][sj]=0;
    visited[si][sj]=true;
    while(!q.empty()){
        pair <int,int> u=q.front();
        q.pop();
        int i=u.first;
        int j =u.second;
        for(auto d : dire){
            int ni=i+d.first;
            int nj=j+d.second;
            if(isValid(ni,nj) && !visited[ni][nj]){
              q.push({ni,nj});
              visited[ni][nj]=true;
              des[ni][nj]=des[i][j]+1;
            }
        }
    }
}
int main() {
    int t;
    cin >>t;
    while(t--){
        cin >>n>>m;
        cin >> si>>sj>>di>>dj;
        bfs();
        if (des[di][dj] == 0 && (si != di || sj != dj)) {
            cout << -1 << endl;
        } else {
            cout << des[di][dj] << endl;
        }
    }

}