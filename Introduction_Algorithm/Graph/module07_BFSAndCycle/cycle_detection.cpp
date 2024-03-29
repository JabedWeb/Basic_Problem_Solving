#include <bits/stdc++.h>
using namespace std;
const int N =1e5+7;
vector<int> adjacent[N];
bool visited[N];

bool dfs(int u ,int p=-1) {
    bool isExisted=false;
    cout << " visiting Node " << u <<" " <<endl;

    visited[u]=true;
    for(int v : adjacent[u]){
        if(v==p) continue;
        if(visited[v]==true) return true;
        isExisted |=dfs(v,u);
    }
    cout <<"Ok" <<endl;
    return isExisted;
}

int main() {
    int v,e;
    cin>> v>>e;


    for(int i =0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }

    for(int i=1;i<=v;i++){
        cout << "list of " <<i << " : ";
        for(int j : adjacent[i]){
            cout << j << " ";
        }
        cout <<endl;
    }

    cout << dfs(1) <<endl;
    // bool cycleExists=false;
    // for(int i =1;i<=v;i++){
    //   cycleExists |=dfs(i);
    // }
    
    // if(cycleExists)
    //  cout <<"cycle detected " <<endl;
    // else 
    // cout <<"cycle not detected " <<endl;
    
}