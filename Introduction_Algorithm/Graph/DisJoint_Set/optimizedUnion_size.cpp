#include <bits/stdc++.h>
using namespace std;

int parent[1008];
int parentSize[1008];

int dsu_find(int n) {  
    while(parent[n]!=-1){
        n=parent[n];
    }
    return n;
}
void dsu_set(int n){
    for(int i =0;i<n;i++){
        parent[i]=-1;
        parentSize[i]=1;
    }
}

void dsu_union(int a,int b){
    int leaderA=dsu_find(a);
    int leaderB=dsu_find(b);
    if(leaderA!=leaderB){
        if(parentSize[leaderA]>parentSize[leaderB]){
            parent[leaderB]=leaderA;
            parentSize[leaderA]+=1;
        }
        else{
            parent[leaderA]=leaderB;
            parentSize[leaderB]+=1;
        }
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
    cout <<dsu_find(10); 

}

/*
7 4
1 2 
2 3
4 5
6 5
*/