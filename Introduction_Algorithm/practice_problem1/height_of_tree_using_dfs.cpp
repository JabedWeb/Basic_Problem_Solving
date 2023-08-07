#include <bits/stdc++.h>
using namespace std;

const int N=1e3+7;

vector <int> adjacent[N];

bool visited[N];
int depth[N];
int height[N];    

void dfs(int u,int df){
    visited[u]=true;
    cout<< u <<endl;
    for(int v : adjacent[u]){
        if(visited[v]==true) continue;

        depth[v]=depth[u]+1;
        if(df==v){
            cout <<" Depth of " << df <<" = " << depth[v]<<endl;
        }
        cout << "into" <<endl;
        dfs(v,df);
        cout<<"dfs er pore " << u  <<endl;
        height[u] = max(height[u],height[v]+1);
    }
    cout <<"ami loop er bahire" <<endl;
}


int main() {
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }
    int df;
    cin>>df;

    dfs(1,df);

    return 0;
}