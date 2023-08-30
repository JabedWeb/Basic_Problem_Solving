 #include <bits/stdc++.h>
using namespace std;

int parent[1008];
int parentLevel[1008];

int dsu_find(int n) {  
    while(parent[n]!=-1){
        n=parent[n]; 
    }
    return n;
}
void dsu_set(int n){
    for(int i =0;i<n;i++){
        parent[i]=-1;
        parentLevel[i]=1;
    }
}

void dsu_union(int a,int b){
    int leaderA=dsu_find(a);
    int leaderB=dsu_find(b);
    if(leaderA!=leaderB){
        if(parentLevel[leaderA]>parentLevel[leaderB]){
            parent[leaderB]=leaderA;
        }
        if(parentLevel[leaderB]>parentLevel[leaderA]){
            parent[leaderA]=leaderB;
        }
        else{
            parent[leaderB]=leaderA;
            parentLevel[leaderA]+=1;
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
        int leaderA=dsu_find(a);
        int leaderB=dsu_find(b);
        if(leaderA==leaderB){
            cout << "Cycle detected in between: " <<a << " " <<b <<endl;
        }
        else{
            dsu_union(a,b);
        }
        
    }

}

/*
5 5
1 2
2 5
1 4
2 3
4 5
*/