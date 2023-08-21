#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;

const int N =1e5+7;

vector <pii> adj[N];
vector <bool>visited(N);

const int INF=-1;

vector <int> dist(N,INF);


void dijkstra (int source){

    dist [source]=0;

    priority_queue<pii,vector<pii>> pq;


    pq.push({dist[source],source});

    while(!pq.empty()){
        int u =pq.top().second;
        pq.pop();
        visited[u]=true;
        for(pii vPair: adj[u]){
            int v=vPair.first;
            int w=vPair.second;
            if(visited[v]) continue;
            if(dist[v]<dist[u]+w){
                dist[v]=dist[u]+w; 
                pq.push({dist[v],v});
            }
        }
    }
    // int max=-1;
    // int max2=-1;

    // for(int i =0;i<1;i++){
    //     for(pii VPair : adj[source]){
    //     int v=VPair.first;
    //     int w =VPair.second;
    //     if(dist[v]>max){
    //         max=dist[v];
    //     }
    //     if(dist[v]>dist[source]+w){
    //         max2=dist[source]+w;
    //     }
    //  }
    //   break;
    // }
    // cout << max << endl;
    // cout <<max2 << endl;
    // cout << max+max2 << endl;
}

int main() {

    int n,e;
    cin >>n>>e;

    for(int i =0;i<e;i++){
        int u ,v ,w;
        cin >>u >>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(1);

    for(int i =1;i<=n;i++){
        cout << "distance of Node " << i << " : ";
        cout << dist[i] <<endl;
    }
}