
#include <bits/stdc++.h>
using namespace std;

const int N =1e5+7;

vector <int> adjacent[N];

int visited[N];

void dfs(int u){
    visited[u]=true;

    for(int v: adjacent[u]){
        if(visited[v]==true) {
            cout<<"common" <<endl;
            continue;
        }
        dfs(v);
    }
    cout << u << " " ;

}

int main() {
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adjacent[x].push_back(y);
    }

    dfs (1);

    // for(int i=1;i<=v;i++){
    //     cout << "Node " << i << " : " ;
    //     for(int j : adjacent[i]){
    //         cout<< j << " " ;
    //     }
    //     cout <<endl;
    // }



}