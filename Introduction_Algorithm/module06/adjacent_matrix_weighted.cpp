#include <bits/stdc++.h>
using namespace std;

const int N=1e3+7;
int adjacent[N][N];
int main() {
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adjacent[x][y]=w;
    }
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cout<<adjacent[i][j]<< " ";
        }
        cout<<endl;
    }
}
