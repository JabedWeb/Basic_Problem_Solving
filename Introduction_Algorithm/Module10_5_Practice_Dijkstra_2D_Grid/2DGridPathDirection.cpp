#include <bits/stdc++.h>
using namespace std;
int n,m;

typedef pair<int,int> pii;

vector <string > g;
const int N=1e3+7;
int level[N][N];
int visited[N][N];

vector <pii > dire={{0,-1},{0,1},{-1,0},{1,0}};

bool isValid(int i,int j){
    return ( i>=0 && i<n && j>=0 && j<m);
}

pii parent[N][N];

void bfs(int si,int sj){
    queue <pii> q;
    level[si][sj]=0;
    visited[si][sj]=true;
    q.push({si,sj});

    while(!q.empty()){
        pii uPair=q.front();
        int i=uPair.first;
        int j =uPair.second; 

        q.pop();

        for(pii d : dire){
            int ni=i+d.first;
            int nj=j+d.second;
            if(isValid(ni,nj) && !visited[ni][nj] && g[ni][nj]!='x'){
                q.push({ni,nj});
                visited[ni][nj]=true;
                level[ni][nj]=level[i][j]+1;
                parent[ni][nj]={i,j};

            }
        }       

    }
}





int main() {
    cin >>n>>m;

    int si,sj,di,dj;

    for(int i=0;i<n;i++){
        string x;
        cin >>x;
        for(int j =0;j<m;j++){
            if(x[j]=='s')
            si=i,sj=j;
            if(x[j]=='e')
            di=i,dj=j;
        }
        g.push_back(x);
    }

    bfs(si,sj);
    cout << level[di][dj]<<endl;

    vector <pii> path;
    pii curr={di,dj};
    while( !(curr.first==si && curr.second==sj)){
        path.push_back(curr);
        curr=parent[curr.first][curr.second];
    }
    path.push_back({si,sj});
    reverse(path.begin(),path.end());
    for(pii d : path){
        cout <<d.first << " " <<d.second <<endl;
    }
    cout <<path.size() <<endl;

    for(int i =1;i<path.size();i++){
        if(path[i-1].first ==path[i].first){
            if(path[i-1].second==path[i].second-1){
                cout <<"R";
            }
            else {
                cout << "L";
            }

        }
        else {
            if(path[i-1].first==path[i].first-1){
                cout <<"D";
            }
            else {
                cout << "U";
            }
        }
    }
}