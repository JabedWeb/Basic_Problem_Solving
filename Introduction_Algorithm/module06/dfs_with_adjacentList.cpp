#include <bits/stdc++.h>
using namespace std;

const int N=1e3+7;

vector <int> adjacent[N];

bool visited[N];

void dfs(int u){
    visited[u]=true;
    cout << u << " " ;

    for(int v : adjacent[u]){
        if(visited[v]==true) continue;
        dfs(v);
    }
}


int main() {
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adjacent[x].push_back(y);
    }

    dfs(1);

    // for(int i=1;i<=v;i++){
    //     cout << "List " << i << ": ";
    //     for(int j: adjacent[i]){
    //         cout << j << " ";
    //     }
    //     cout<<endl;
    // }


    return 0;
}