/*
Problem Statement

Kamal lives in mazenda city. In his neighbourhood there are several houses too. Some of them are directly connected to Kamal's house, and some of them are indirectly connected. This time the roads are only one-way. If there are N houses and E roads in his area. Every house has a unique number from 0 to N-1. Can you tell how many houses Kamal can go directly or indirectly if Kamal's house if his house number is K?

Note: You can go in the road only in one direction.

Input Format

First line will contain N and E, the number of houses and roads respectively.
Next E lines will contain A and B, means there is a road between A house and B house. You can go only from A to B.
Next line will contain K, the number of Kamal's house
Constraints

0 < N <=20
0 <= E <= 190
0 <= A,B < N
0 <= K < N
Output Format

Output the number of houses that Kamal can go.
Sample Input 0

6 5
0 1
0 2
0 3
2 3
4 5
2
Sample Output 0

1
Explanation 0

image

Kamal can go in only one house that is house no 3.
Sample Input 1

6 5
0 1
0 2
2 3
3 0
4 5
2
Sample Output 1

3

*/



#include <bits/stdc++.h>
using namespace std;

const int N =1e5+7;
vector <int> adjacent[N];
bool visited[N];

vector <int> count_house;


void kam_house_neigh(int src){
    visited[src]=true;
    for(int v : adjacent[src]){
        if(visited[v]) continue;
        count_house.push_back(v);
        kam_house_neigh(v);
    }
}

int main() {
    int v,e;
    cin>>v>>e;
    for(int i =0;i<e;i++){
        int x,y;
        cin >>x>>y;
        adjacent[x].push_back(y);
    }
    int house_nu;
    cin >> house_nu;


    kam_house_neigh(house_nu);
    cout << count_house.size() << endl;
}
