/*
Question: You will be given an undirected weighted graph. At first you will be given N, the number of nodes then you will be given M, the number of edges. The value of nodes are from 1 to N. Next M lines will contain A, B and W which means there is an edge from A to B where the cost is W. There will be no negative weight in the graph.
Also, you will be given a source and a destination. You need to tell the shortest distance between source and destination.
Sample Input
Sample Output
6 9
1 2 5
2 3 2
1 3 10
3 4 1
4 1 5
1 5 9
5 6 1
2 6 4
2 5 2
4 6
6

The shortest path is 4-> 3-> 2-> 5-> 6, so the shortest distance is 6.


*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N =10e3+7;
const int INF=10e4+10;
vector <bool >visited(N,false);
vector <pii> adj[N];
vector <int> dist(N,INF);

void dijkstra(int source){
    priority_queue <pii,vector<pii>,greater<pii>> pq;
    visited[source]=true;
    dist[source]=0;
    pq.push({dist[source],source});

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();


        for(pii vPair : adj[u]){
            int v=vPair.first;
            int w=vPair.second;
            if(visited[v]) continue;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    
}

int main() {
    int n,m;
    cin >>n>>m;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra(4);
    cout << dist[6];
}