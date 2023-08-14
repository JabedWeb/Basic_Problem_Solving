/*
CSES Problem Set
Counting Rooms
TASK SUBMIT RESULTS STATISTICS
Time limit: 1.00 s Memory limit: 512 MB
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n×m
 squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

Input

The first input line has two integers n
 and m
: the height and width of the map.

Then there are n
 lines of m
 characters describing the map. Each character is either . (floor) or # (wall).

Output

Print one integer: the number of rooms.

Constraints
1≤n,m≤1000

Example

Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;

const int N =10e3+7;
vector <string> g;
int visited [N][N];
int n,m;

vector <pii> dire= {{0,-1},{0,1},{-1,0},{1,0}};

bool isValid(int i ,int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void dfs(int i,int j){
    if(!isValid(i,j)) return;
    if(visited[i][j]) return;
    if(g[i][j]=='#') return;
    visited[i][j]=true;
    for(auto d : dire){
        dfs(i+d.first,j+d.second);
    }
    // dfs(i,j-1);
    // dfs(i,j+1);
    // dfs(i-1,j);
    // dfs(i+1,j);
}

int main() {
    cin >>n>>m;
    for(int i=0;i<m;i++){
        string str;
        cin >> str;
        g.push_back(str);
    }
    int room=0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(g[i][j]=='#') continue;
            if(visited[i][j]) continue;
            dfs(i,j);
            room++;
        }
    }
    cout <<room <<endl;
}