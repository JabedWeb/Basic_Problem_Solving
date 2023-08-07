#include <bits/stdc++.h>
using namespace std;

const int N=1e3+7;

vector <int> adjacent[N];

bool visited[N];

void dfs(int u){
    // section 1 : actions after entering node u
    visited[u]=true;
    cout << u << " " ;

    for(int v : adjacent[u]){
        //section 2 : actions before entering a new neighbor
        if(visited[v]==true) continue;
        dfs(v);
        //section 3 : actions after exiting a new neighbor
    }
    //section 4 : actions before exiting node u
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

    cout << "\nvisiting array " << endl;

    for(int i =1;i<=v;i++){
        cout << "Node" << i << " status : " <<visited[i] << endl;
    }


    return 0;
}