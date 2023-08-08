#include <bits/stdc++.h>
using namespace std;

const int N=1e3+7;

vector <int> adjacent[N];

bool visited[N];
int height[N];    
int maxHeight=0;

void dfs(int u,int df){

    visited[u]=true;
    for(int v : adjacent[u]){
        if(visited[v]==true) continue;
        dfs(v,df);
        height[u] = max(height[u],height[v]+1);
        if(df==u){
            if(maxHeight<height[u]){
                maxHeight =height[u];
            }
        //cout << "height of " << df << " : " << height[u]<<endl;
        }
    }

    //for the leap node
    if(df==u){
         maxHeight ==height[u];
        //cout << "height of " << df << " : " << height[u]<<endl;
    }
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
    int hf;
    cin>>hf;

    dfs(1,hf);

     cout << "height of " << hf << " : " << maxHeight<<endl;

    return 0;
}