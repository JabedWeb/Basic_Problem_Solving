/*
Problem Statement

You will be given an undirected graph as input. You need to tell the number nodes in each component in ascending order.

Note: There will be no component with single node.

Input Format

First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 1000.
Next E lines will contain A, B which means there is a edge between node A and B.
Constraints

1 <= N, E <= 1000
Output Format

Output the number of nodes in each component in ascending order.
Sample Input 0

9 7
0 1
1 2
0 2
2 3
4 5
5 7
8 9
Sample Output 0

2 3 4 
Explanation 0

The components are shown for the sample test case:
image

Sample Input 1

5 3
999 1000
100 500
500 600
Sample Output 1

2 3

*/


#include <bits/stdc++.h>
using namespace std;

const int N =1e3+7;
vector <int> adjacent[N];
bool visited[N];

vector <int> size_com[N];

void components_count(int src,int n_size){

     size_com[n_size].push_back(src);
     visited[src]=true;
    for(int v : adjacent[src]){
        if(visited[v]) continue;
        components_count(v,n_size);
    }
}

bool compareVectorsBySize(vector<int> &a, vector<int> &b) {
    return a.size() < b.size();
}

int main() {
    int v,e;
    cin>>v>>e;
    for(int i =0;i<e;i++){
        int x,y;
        cin >>x>>y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }


    for (int i = 0; i < N; i++) {
        if (!visited[i] && !adjacent[i].empty()) {
            components_count(i,i);
        }
    }


    sort(size_com, size_com + N , compareVectorsBySize);

        for(int i =0;i<=N;i++){
            if(size_com[i].size()>1){
                cout << size_com[i].size() <<" ";
            }
        }
}
