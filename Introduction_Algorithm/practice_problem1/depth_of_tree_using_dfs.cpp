#include <bits/stdc++.h>
using namespace std;

const int N=1e3+7;

vector <int> adjacent[N];

bool visited[N];
int depth[N];
int height[N];    

void dfs(int u,int df){
    visited[u]=true;
    for(int v : adjacent[u]){
        if(visited[v]==true) continue;

        depth[v]=depth[u]+1;
        if(df==v){
            cout <<" Depth of " << df <<" = " << depth[v];
        }
        dfs(v,df);
        height[u] = max(height[u],height[v]+1);
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
    int df;
    cin>>df;

    dfs(1,df);

    return 0;
}