#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int>adjacent[N];
bool visited[N];

void dfs(int u){
    cout << u << " ";
    visited[u]=true;

    for(int v: adjacent[u]){
        if(visited[v]==true) continue;
        dfs(v);
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int u =q.front();
        cout <<"visiting Node : " << u << endl;
        q.pop();
        for(int v : adjacent[u]){
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
        }
    }
}

int main() {
    int v,e;
    cin >>v>>e;

    for(int i=0;i<e;i++){
        int x,y;
        cin >>x>>y;
        adjacent[x].push_back(y);
        //adjacent[y].push_back(x);
    }
    int cc=0;

    for(int i=1;i<=v;i++){
        if(visited[i]==true) continue;
         bfs(i);
         cc++;
    }
    cout<<"\nconnected component "<<cc <<endl;
    
}