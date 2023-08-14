/*
CSES Problem Set
Message Route
TASK SUBMIT RESULTS STATISTICS
Time limit: 1.00 s Memory limit: 512 MB
Syrjälä's network has n
 computers and m
 connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.

Input

The first input line has two integers n
 and m
: the number of computers and connections. The computers are numbered 1,2,…,n
. Uolevi's computer is 1
 and Maija's computer is n
.

Then, there are m
 lines describing the connections. Each line has two integers a
 and b
: there is a connection between those computers.

Every connection is between two different computers, and there is at most one connection between any two computers.

Output

If it is possible to send a message, first print k
: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.

If there are no routes, print "IMPOSSIBLE".

Constraints
2≤n≤105

1≤m≤2⋅105

1≤a,b≤n

Example

Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5

*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector <int>adj[N];
vector <bool > visited(N,false);

vector <int> parent(N,-1);

void bfs(int source){
    visited[source]=true;
    queue <int> q;
    q.push(source);
    while(!q.empty()){
        int u =q.front();
        // cout << u << " " <<endl;
        q.pop();
        for(int v : adj[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v]=true;
            parent[v]=u;
        }
    }
}

int main() {
    int n,m;
    cin >>n>>m;
    for(int i =0;i<m;i++){
        int x,y;
        cin >>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1);

    int curr=n;
    vector < int > routes;

    while(curr !=-1){
        routes.push_back(curr);
        curr=parent[curr];
    }
    reverse(routes.begin(),routes.end());
    for(auto r : routes){
        cout << r << " ";
    }
}