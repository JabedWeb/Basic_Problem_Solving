/*
CSES Problem Set
Building Roads
TASK STATISTICS
Time limit: 1.00 s Memory limit: 512 MB
Byteland has n
 cities, and m
 roads between them. The goal is to construct new roads so that there is a route between any two cities.

Your task is to find out the minimum number of roads required, and also determine which roads should be built.

Input

The first input line has two integers n
 and m
: the number of cities and roads. The cities are numbered 1,2,…,n
.

After that, there are m
 lines describing the roads. Each line has two integers a
 and b
: there is a road between those cities.

A road always connects two different cities, and there is at most one road between any two cities.

Output

First print an integer k
: the number of required roads.

Then, print k
 lines that describe the new roads. You can print any valid solution.

Constraints
1≤n≤105

1≤m≤2⋅105

1≤a,b≤n

Example

Input:
4 2
1 2
3 4

Output:
1
2 3

*/

#include <bits/stdc++.h>
using namespace std;

const int N =1e4+7;
vector <int> adj[N];
vector <bool> visited(N,false);

vector < int > roads;

void dfs(int source){
    visited[source]=true;
    for(int v : adj[source]){
        if(visited[v]) continue;
        dfs(v);
    }
}

int main() {
    int n ,m;
    cin>>n>>m;

    for(int i =0;i<m;i++){
        int x,y;
        cin >>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ct=0;

    for(int i =1;i<=n;i++){
        if(visited[i]) continue;
        dfs(i);
        ct++;
        roads.push_back(i);
    }

    cout << ct-1 <<endl;

    for(int i =1;i<roads.size();i++){
        cout << roads[i-1] << " " << roads[i] << endl;
    }
}
