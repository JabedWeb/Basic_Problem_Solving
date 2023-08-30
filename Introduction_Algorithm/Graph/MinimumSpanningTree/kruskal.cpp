#include <bits/stdc++.h>
using namespace std;

// for the dsu
int parent[1008];
int parentSize[1008];

class Edge{
    public : 
    int a ,b,w;
    Edge (int a,int b,int w){
        this->a=a;
        this->b=b;
        this->w=w;
    }
};
// for ascending order sort
bool cmp(Edge a,Edge b){
    return a.w < b.w;
};

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
    vector <Edge> v;
    vector <Edge > ans;
    while(e--){
        int a,b,w;
        cin>>a>>b>>w;
        v.push_back(Edge(a,b,w));
    }
    sort(v.begin(),v.end(),cmp);
    for(Edge val:v){
        // cout <<val.a << " " << val.b << " " <<val.w <<endl;
        int a=val.a;
        int b=val.b;
        int w=val.w;
        int leaderA=dsu_find(a); 
        int leaderB=dsu_find(b);
        if(leaderA==leaderB)continue;
        ans.push_back(val);
        dsu_union(a,b); 
    }
    for(Edge va:ans){
        cout <<va.a << " " << va.b << " " <<va.w <<endl;
    }
}

/*
8 11
1 5 2
1 2 4
1 4 10
5 4 5
2 4 8
2 3 18
3 4 11
4 8 9
4 7 11
7 6 1
8 6 2



*/

/*

*/