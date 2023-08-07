#include <bits/stdc++.h>
using namespace std;

const int N=1e5+3;
vector <pair<int,int> >adj[N];

int main() {
    int v,e;
    cin>>v>>e;


    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;

        adj[x].push_back({y,w});
        //adj[x].push_back(make_pair(y,w))
    }
    for(int i=1;i<=v;i++){
        cout<<"List " << i << " : ";
        for(auto j:adj[i]){
            cout<< "("<< j.first<<"," <<j.second <<"), ";
        }
        cout<<endl;
    }
}