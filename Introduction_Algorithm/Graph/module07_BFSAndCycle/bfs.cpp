#include <bits/stdc++.h>
using namespace std;
const int N=1e3+7;
vector<int>adjacent[N]; 
bool visited[N];

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
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }

    bfs(1);


    return 0;
}
