/*
Problem Statement

You will be given a 2D matrix of size NxM which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(.) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

You will be given the indexes of to cells - S(si,sj) and D(di,dj). You need to tell if these cells are in the same component or not where you can go from S to D.

Input Format

First line will contain N and M.
Next you will be given the 2D matrix.
Next line will contain si and sj.
Last line will contain di and dj.
Constraints

1 <= N, M <= 1000
0 <= si, di < N
0 <= sj, dj < M
Output Format

Output "YES" if those cell are in the same component, "NO" otherwise.
Sample Input 0

5 4
..-.
---.
..-.
--..
....
0 1
3 2
Sample Output 0

NO
Sample Input 1

5 4
....
---.
..-.
--..
....
0 1
3 2
Sample Output 1

YES

*/

#include <bits/stdc++.h>
using namespace std;
const int N =10e3+7;

vector <string> g;

bool visited[N][N];
int n,m;
int si,sj;
int di,dj;

int ct=0;

vector <pair<int,int>> dire={{0,-1},{0,1},{-1,0},{1,0}};

bool isValid(int i ,int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void dfs(int i ,int j ){

    if(isValid(i,j) && !visited[i][j] && g[i][j]!='-'){
        if((i==si && j==sj) || (i==di && j==dj) ){
            ct++;
        }
        //cout << i << " " << j <<endl;
        visited[i][j]=true;
        for(auto d : dire){
            dfs(i+d.first,j+d.second);
        }
    }

}

int main() {
    cin >>n>>m;

    for(int i =0 ;i<n;i++){
        string line;
        cin >> line;
        g.push_back(line);
    }

    cin >>si >>sj >>di >>dj;


    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='-') continue;
            if(visited[i][j]) continue;
            ct=0;
            dfs(i,j);
            if(ct==2){
            cout << "YES" <<endl;
            return 0;
    }
        }
    }

    
  
        cout <<"N0" <<endl;
    

    // cout << ct <<endl;


    



    //dfs()

    // for(int i =0 ;i<n;i++){
    //     cout << g[i] <<endl;
    // }
}



