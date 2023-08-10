#include <bits/stdc++.h>
using namespace std;

const int N=1e3+7;

vector <int> adjacent[N];

bool visited[N];
int depth[N];
int height[N];    

void dfs(int u){
    // section 1 : actions after entering node u
    visited[u]=true;
    cout << "parent " << u  <<endl;
    for(int v : adjacent[u]){ 
        //section 2 : actions before entering a new neighbor
        if(visited[v]==true) {
            cout << " visited " << v <<endl;
            continue;
        };

        dfs(v);
        //section 3 : actions after exiting a new neighbor
        // if(height[v]+1 >height[u]){
        //     height[u]=height[v]+1;
        // }
        cout <<"parent " << u << " : " << v << endl;
        height[u] = max(height[u],height[v]+1);
    }

    cout << " outside " << endl;
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

    cout << "\nHeight array " << endl;
    for(int i =1;i<=v;i++){
        cout << "Node " << i << " height : " <<height[i] << endl;
    }

    return 0;
}