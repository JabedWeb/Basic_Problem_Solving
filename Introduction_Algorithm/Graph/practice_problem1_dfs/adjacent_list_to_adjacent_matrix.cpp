#include <bits/stdc++.h>
using namespace std;
const int N=1e3+7;
vector <int> adj[N];

int main() {
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    //first v+1 is how many row we need for this 2D array
    //second v+1 is need for the setup default value;

    vector<vector<int>> adjacentMatrix(v+1,vector<int>(v+1,0));
    //convert adjacent list to adjacent matrix 
    for(int i =1;i<=v;i++){
        for(int j: adj[i]){
           adjacentMatrix[i][j]=1;
        }
    }

    for(int i =1;i<=v;i++){
        for(int j=1;j<=v;j++){

            cout <<adjacentMatrix[i][j]<<" ";
        }
        cout <<endl;
    }
}