#include <bits/stdc++.h>
using namespace std;

int parent[1008];

int dsu_find(int n) {  
    while(parent[n]!=-1){
        n=parent[n];
    }
    return n;
}
void dsu_set(int n){
    for(int i =0;i<n;i++){
        parent[i]=-1;
    }
}

void dsu_union(int a,int b){
    int leaderA=dsu_find(a);
    int leaderB=dsu_find(b);
    if(leaderA!=leaderB){
        parent[leaderB]=leaderA;
    }
}

int main() {
    int n,e;
 
    cin>>n>>e;
    dsu_set(n);
    for(int i =0;i<e;i++){
        int a,b;
        cin>>a>>b;
        dsu_union(a,b);
    }
    cout <<dsu_find(5); 

}

/*
7 4
1 2 
2 3
4 5
6 5
*/