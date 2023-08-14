#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;

const int N=1e3+7;

vector <pii> adj[N];
const int INF=10e9+7;
vector <int> dist(N,INF);
vector <bool> visited(N);
int cnt=0;

void dijkstra(int source){


    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dist[source]=0;
    pq.push({dist[source],source});

    while(!pq.empty()){
        
        cnt++;
        int u =pq.top().second;
        pq.pop(); 
        visited[u]=true;

        for(pii vPair:adj[u] ){
            int v=vPair.first;
            int w=vPair.second;
            cnt++;
            if(visited[v]) continue;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    cout << cnt << endl;

}

int main() {
    int v,e;
    cin >> v>>e;

    for(int i =0;i<e;i++){
        int x,y,w;
        cin >>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    dijkstra(1);

    for(int i=1;i<=v;i++){
        cout << "Distance of Node " << i <<" : ";
        cout << dist[i] <<endl;
    }
}



/*
7
8
1 2 3
1 3 5
3 4 1
4 6 1
2 5 6
5 6 1
5 7 2
3 7 12
*/