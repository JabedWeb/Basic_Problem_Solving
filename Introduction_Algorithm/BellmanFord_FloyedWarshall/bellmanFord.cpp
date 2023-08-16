/*
7
10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
4 7 3
*/

/*
Distance of 1 0
Distance of 2 1
Distance of 3 3
Distance of 4 5
Distance of 5 0
Distance of 6 4
Distance of 7 3


*/

#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int>pii;
int n,m;
const int N=10e3+7;
vector <pii> g[N];
vector <pair<pii,int>>list_of_edges;
int d[N];

const int INF=10e5+7;


void bellmanFord(int source){
    for(int i =1;i<=n;i++){
        d[i]=INF;
    }
    d[source]=0;
    for(int k=1;k<n;k++){
        //all edges relaxation
        for(auto edge : list_of_edges){
            int u =edge.first.first;
            int v=edge.first.second;
            int w=edge.second;
            if(d[u]!=INF && d[v]>d[u]+w){
                    d[v]=d[u]+w;
            }
        }

    }
}

int main() {

    cin >>n>>m;

    for(int i =0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        //g[u].push_back({v,w});
        //g[v].push_back({u,w});
        list_of_edges.push_back({{u,v},w});

    }
    bellmanFord(1);

    for(int i =1;i<=n;i++){
        cout<<"Distance of " <<i << " " << d[i]<<endl; 
    }

    ///////
    cout <<endl;
    for(auto edges : list_of_edges){
        cout << edges.first.first << " " <<edges.first.second << " " << edges.second<<endl;
    }
} 



/*
#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int>pii;
int n,m;
const int N=10e3+7;
vector <pii> g[N];
int d[N];

const int INF=10e5+7;


void bellmanFord(int source){
    for(int i =1;i<=n;i++){
        d[i]=INF;
    }
    d[source]=0;
    for(int k=1;k<n;k++){
        for(int u=1;u<=n;u++){
            for(pii vPair:g[u]){
                int v=vPair.first;
                int w=vPair.second;
                if(d[u]!=INF && d[v]>d[u]+w){
                    d[v]=d[u]+w;
                }
            }
        }
    }
}

int main() {

    cin >>n>>m;

    for(int i =0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        //g[v].push_back({u,w});
    }
    bellmanFord(1);

    for(int i =1;i<=n;i++){
        cout<<"Distance of " <<i << " " << d[i]<<endl; 
    }
} 




*/