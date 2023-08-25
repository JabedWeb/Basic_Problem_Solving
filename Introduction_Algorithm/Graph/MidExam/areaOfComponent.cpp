/*
Area of Component
Problem
Submissions
Leaderboard
Discussions
Problem Statement

You will be given a 2D matrix of size NxM which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(.) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

The area of a component is the number of dots(.) in that component that can be accessible. You need to tell the minimum area of all available components.

Note: If there are no components, print -1.

Input Format

First line will contain N and M.
Next you will be given the 2D matrix.
Constraints

1 <= N, M <= 1000
Output Format

Output the minimum area.
Sample Input 0

6 5
..-..
..-..
-----
.-...
.----
.....
Sample Output 0

3
Sample Input 1

3 3
---
---
---
Sample Output 1

-1
*/


#include <bits/stdc++.h>
using namespace std;
vector <string> g;
const int N =10e3+5;


bool visited[N][N];

int n,m;
int minArea = INT_MAX;

vector <pair<int,int>> dire={{-1,0},{1,0},{0,1},{0,-1}};

bool isValid(int i ,int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void dfs(int i ,int j,int &compo){
    
    if(isValid(i,j) && !visited[i][j] && g[i][j]!='-'){
        visited[i][j]=true;
        compo++;
        for(auto d : dire){
            dfs(i+d.first,j+d.second,compo);
        }
    }
}

int main() {
    cin >> n >>m ;

    for(int i =0 ; i<n;i++){
        string line;
        cin >> line;
        g.push_back(line);
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(visited[i][j]) continue;
            if(g[i][j]=='-') continue;
            int  compo=0;
            dfs(i,j,compo);
            minArea=min(minArea,compo);
        }
    }
    if (minArea == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minArea << endl;
    }
}