/*
Problem Statement

You will be given an undirected graph as input. You will be given a query Q, for each query you will be given a source S and a destination D. You need to tell the minimum distance from source to destination for each query.

Note: If there is no path in between the source and destination, print -1.

Input Format

First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 10^5.
Next E lines will contain A, B which means there is a edge between node A and B.
Next line will contain Q, the number of queries.
For each query every line will contain S and D.
Constraints

1 <= N, E <= 1000
1 <= Q <= 1000
0 <= S, D <= 10^5
Output Format

Output the minimum distance from source to destination for each query.
Sample Input 0

6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
6
0 5
1 5
2 5
2 3
1 4
0 0
Sample Output 0

2
3
3
2
2
0
Explanation 0

In this test case, the graph is given below.
image

Sample Input 1

7 6
0 1
0 2
1 2
0 3
4 2
4 3
4
3 10
2 6
0 6
0 10
Sample Output 1

-1
-1
-1
-1

*/

#include <bits/stdc++.h>
using namespace std;

const int N =1e5+7;
vector <int> adjacent[N];
bool visited[N];

vector <int> dist(N,-1);

void find_shortest_dist(int src){

    queue <int > q;
    visited[src]=true;
    q.push(src);

    dist[src]=0;

    while (!q.empty()){
        int u=q.front();
        //cout << u << " ";
        q.pop();
        for(int v : adjacent[u]){
            if(visited[v]) continue;
            q.push(v);
            dist[v]=dist[u]+1;
            visited[v]=true;
        }
    }

}

int main() {
    int v,e;
    cin>>v>>e;
    for(int i =0;i<e;i++){
        int x,y;
        cin >>x>>y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }

    int t;
    cin >>t;
    while(t--){
        int src, des;
        cin >>src>>des;
        for(int i =0;i<=v;i++){
            visited[i]=false;
            dist[i]=-1;
        }
        find_shortest_dist(src);
        cout << dist[des] << endl;
    }
}
