/*
Cycle of Edges
Problem
Submissions
Leaderboard
Discussions
Problem Statement

You will be given an undirected graph where there will be N nodes and E edges. You need to tell the number of edges that can create a cycle in the graph.

Note: Duplicate edges as input can not be possible. The value of nodes are from 1 to N.

Input Format

First line will contain N and E.
Next E lines will contain A and B which means there is a edge between A and B.
Constraints

1 <= N <= 10^5
1 <= E <= (N*(N-1))/2
1 <= A, B <= N
Output Format

Output the number of edges that can create a cycle.
Sample Input 0

5 7
1 2
2 3
3 4
4 5
4 1
2 4
5 3
Sample Output 0

3
Sample Input 1

3 3
1 2
2 3
1 3
Sample Output 1

1
*/
#include <bits/stdc++.h>
using namespace std;
const int N=10e5+7;
int parent[N];
int parentSize[N];

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
    int ct=0;
 
    cin>>n>>e;
    dsu_set(n);
    for(int i =0;i<e;i++){
        int a,b;
        cin>>a>>b;
        int leaderA=dsu_find(a);
        int leaderB=dsu_find(b);
        if(leaderA==leaderB){
            ct++;
        }
        dsu_union(a,b);
    }
    cout << ct <<endl;

}