/*


Question: You are given a 2D grid which will contain only the characters ‘s’, ‘.’, ‘x’ and ‘e’. The size of the grid is N*M squares, where ‘s’ means where you should start, ‘.’ means there is a path, ‘x’ means there is no path and ‘e’ means where you should stop. You can walk left, right, up, and down through the cell of squares. You need to say “YES” if you can go from ‘S’ to ‘E’. Otherwise print “NO”. There will be exactly one ‘s’ and one ‘e’. If there is no path, print -1.
Note: Try to solve this using both BFS and DFS as you don’t need the shortest distance.
Sample Input
Sample Output
6 5
.s.x.
...x.
..x..
..x..
..xex
.....
YES
5 5
.s.x.
...x.
..x..
..x..
..xex
NO
5 5
.....
.....
.x..e
s.x..
....x
YES
*/

#include <bits/stdc++.h>
using namespace std;
int n,m;
typedef pair <int ,int> pii;
const int N=10e3+7;
vector <string>g;
int visited[N][N];

int level[N][N];

vector <pii> dire={{0,-1},{0,1},{-1,0},{1,0}};

bool isValid(int i ,int j){
    return (i>=0 && i<n && j>=0 && j <m);
}

void bfs(int si,int sj){
    queue <pii> q;
    q.push({si,sj});
    level[si][sj]=0;
    visited[si][sj]=true;

    while(!q.empty()){
        pii uPair=q.front();
        int i =uPair.first;
        int j =uPair.second;
        q.pop();
        for(pii d : dire){
            int ni=i+d.first;
            int nj=j+d.second;
            if(isValid(ni,nj) && !visited[ni][nj] && g[ni][nj]!='x'){
                q.push({ni,nj});
                level[ni][nj]=level[i][j]+1;
                visited[ni][nj]=true;
            }
        }
    }
}


int main() {
    cin>>n>>m;
    int si,sj,di,dj;

    for(int i =0;i<n;i++){
        string x;
        cin >> x;
        for(int j=0;j<m;j++){
            if(x[j]=='s'){
                si=i;
                sj=j;
            }
            if(x[j]=='e'){
                di=i;
                dj=j;
            }
       }
        g.push_back(x);
    }
    bfs(si,sj);
    cout <<(level[di][dj] ? level[di][dj]  : -1 )<<endl;


}