//https://atcoder.jp/contests/abc326/tasks/abc326_c
////https://codeforces.com/contest/266/problem/A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
int adjacent[N][N];
int main() {
    int n,e;cin>>n>>e;
    
    for(int i=0;i<e;i++){
        int u,v;cin>>u>>v;
        adjacent[u][v]=1;
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adjacent[i][j]<<" ";
        }
        cout<<endl;
    }

}
