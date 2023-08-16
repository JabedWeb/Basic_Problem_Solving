#include <bits/stdc++.h>
using namespace std;
const int N =10e3+5;
const int INF=10e5+7;
int d[N][N];

int n,m;

void dist_initialize(){
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                d[i][j]=INF;
            }
        }
    }
}


void printMatrix(){
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]==INF) cout << "X ";
            else cout <<d[i][j] <<" ";
        }
        cout <<endl;
    }
}


int main() {
    cin>>n>>m;
    dist_initialize();
    for(int i =0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=w;
        //d[v][u]=w;
    }

    printMatrix();

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    cout <<endl;

    printMatrix();

}