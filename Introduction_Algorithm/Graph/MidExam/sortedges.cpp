/*
Problem Statement

You will be given E, the number of edges. For each you will be given A and B which means there is an edge between A and B.

You need to sort all edges in such a way that the edges are sorted in ascending order for A. If multiple edges have same A, then you will sort them according to B in ascending order.

Input Format

First line will contain E.
Next E lines will contain A and B.
Constraints

1 <= E <= 10^5
0 <= A, B <= 10^9
Output Format

Output all the edges in sorted order.
Sample Input 0

6
3 4
3 2
3 5
1 2
1 4
1 5
Sample Output 0

1 2
1 4
1 5
3 2
3 4
3 5

*/

#include <bits/stdc++.h>
using namespace std;
const int N=10e5+7;

int n;

vector <pair<int,int>> edges;

bool compareEdges(pair<int,int> edg1,pair<int,int>edg2){
    if(edg1.first==edg2.first){
        return edg1.second < edg2.second;
    }
    else{
        return edg1.first <edg2.first;
    }
}

int main() {

    cin>>n;

    for(int i =0;i<n;i++){
        long long int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    sort(edges.begin(),edges.end(),compareEdges);

    for(pair<int,int> edge : edges){
        cout << edge.first << " " <<edge.second <<endl;
    }
}