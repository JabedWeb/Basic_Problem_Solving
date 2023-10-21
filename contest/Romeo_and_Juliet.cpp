/*
Romeo and Juliet
Problem
Submissions
Leaderboard
Discussions
Problem Statement

Romeo and Juliet are a newly married couple. They went to Switzerland for their honeymoon. They had a plan in mind: they would test their fortune by staying in different cities and seeing if they could reunite in at most K steps. Switzerland has N cities numbered from 0 to N-1, with E two-way roads connecting them.

Romeo is in city X, and Juliet is in city Y. In each step, they can cross one road and move from one city to another. It is not mandatory for both of them to cross; one can choose to stay in the same city if desired. However, the step will still be counted.

Can you tell if they can be reunited or not?

Input Format

First line will contain N and E; The number of city and number of roads respectively.
Next E lines will contain A and B which means there is a road between city A and B.
Last line will contain X,Y and K.
Constraints

2 <= N <= 100
0 <= E <= 1000
0 <= X, Y < N and X != Y
0 <= K <= 1000
Output Format

Output "YES" if they can be reunited otherwise output "NO".
Sample Input 0

8 9
0 1
4 0
4 2
2 3
1 3
2 5
5 6
6 7
6 3
4 7 2
Sample Output 0

YES
Explanation 0

Initial city of Romeo and Juliet are 4 and 7. 
They can be reunited in 2 steps as follows:
Romeo at city 2 and Juliet at city 6 after step 1 -
Romeo and Juliet are both at city 5 after step 2 -


Sample Input 1

8 9
0 1
4 0
4 2
2 3
1 3
2 5
5 6
6 7
6 3
2 7 2
Sample Output 1

YES
Sample Input 2

8 9
0 1
4 0
4 2
2 3
1 3
2 5
5 6
6 7
6 3
2 7 1
Sample Output 2

NO
Sample Input 3

7 6
4 0
0 1
3 1
3 2
4 2
5 6
4 6 10
Sample Output 3

NO
*/
//Initial city of Romeo and Juliet are 4 and 7. 
// move romero one forward and juliet one backward 
//find out the shortest step to meet them 
//Initial city of Romeo and Juliet are 4 and 7. 
//They can be reunited in 2 steps as follows:
//Romeo at city 2 and Juliet at city 6 after step 1 -
//Romeo and Juliet are both at city 5 after step 2 -


#include <bits/stdc++.h>
using namespace std;

const int N =1e5+7;
vector <int> adjacent[N];
bool visited[N];
vector <int> dist(N,-1);
vector <int > desNode[N];


void distanceStoD(int src,int des){

    queue <int > q;
    visited[src]=true;
    q.push(src);

    desNode[src].push_back(src);

    dist[src]=0;

    while (!q.empty()){
        int u=q.front();
        q.pop();
        for(int v : adjacent[u]){
            if(visited[v]) continue;
            q.push(v);
            dist[v]=dist[u]+1;
            visited[v]=true;
            if(v==des){
                desNode[des].push_back(dist[v]);
            }
        }
    }

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

        int src, des,k;
        cin >>src>>des>>k;
        for(int i =0;i<=v;i++){
            visited[i]=false;
            dist[i]=-1;
        }
        if(src==des){
            cout <<"YES"<<endl;
            return 0;
        }
        if(src>v || des>v){
            cout <<"N0"<<endl;
            return 0;
        }
        
        distanceStoD(src,des);

        // we have to multiply k by 2 because we have to go and come back
        for(int i =0;i<desNode[des].size();i++){
            if(desNode[des][i]<=k*2){
                cout <<"YES"<<endl;
                return 0;
            }
        }
        cout <<"NO"<<endl;
        
   
    return 0;
}

