/*
9
6
1 4 
1 2 
1 3
4 7
4 8
2 9
*/


#include <bits/stdc++.h>
using namespace std;

const int N=1e5+3;
vector <int>adj[N];

int main() {
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
    }
    for(int i=1;i<=v;i++){
        cout<<"List " << i << " : ";
        for(int j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}