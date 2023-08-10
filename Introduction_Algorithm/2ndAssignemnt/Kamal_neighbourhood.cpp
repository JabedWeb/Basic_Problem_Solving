/*

Problem Statement

Kamal lives in mazenda city. In his neighbourhood there are several houses too. Some of them are directly connected to Kamal's house, and some of them are indirectly connected. But the roads are two-way as usual. If there are N houses and E roads in his area. Every house has a unique number from 0 to N-1. Can you tell how many houses are directly connected to Kamal's house if his house number is K?

Input Format

First line will contain N and E, the number of houses and roads respectively.
Next E lines will contain A and B, means there is a road between A house and B house. You can go from A to B and also B to A.
Next line will contain K, the number of Kamal's house
Constraints

0 < N <=20
0 <= E <= 190
0 <= A,B < N
0 <= K < N
Output Format

Output the number of houses that are directly connected to Kamal's house.
Sample Input 0

6 5
0 1
0 2
0 3
2 3
4 5
2
Sample Output 0

2
*/

#include <bits/stdc++.h>
using namespace std;

const int N =1e5+7;
vector <int> adjacent[N];
bool visited[N];


int kam_house_neigh(int src){
    int count_dir=0;
    queue <int > q;
    visited[src]=true;
    q.push(src);

    while (!q.empty()){
        int u=q.front();
        //cout <<"Visiting list " << u << " " ;
        q.pop();
        for(int v : adjacent[u]){
            count_dir ++;
            if(visited[v]) continue;
            q.push(v);
            visited[v]=true;
        }
        break;

    }
    return count_dir;

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
    int house_nu;
    cin >> house_nu;


    int house_count=kam_house_neigh(house_nu);
    cout << house_count << endl;
}
