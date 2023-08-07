#include <bits/stdc++.h>
using namespace std;

const int N=1e3+7;
int adj[N][N];

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int value;
            cin>>value;
            adj[i][j]=value;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout <<adj[i][j] << " ";
    //     }
    //     cout <<endl;
    // }
    for(int i=1;i<=n;i++){
        cout <<"List " <<" : " ; 
        for(int j=1;j<=n;j++){
           if( adj[i][j]==1){
            cout << j << " ";
           }
        }
        cout <<endl;
    }
}