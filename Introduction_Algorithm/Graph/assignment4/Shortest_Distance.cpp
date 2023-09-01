/*
Shortest Distance
Problem
Submissions
Leaderboard
Discussions
Problem Statement

You'll be given a graph of N nodes and E edges. For each edge, you'll be given A, B and W which means there is an edge from A to B which will cost W. Also, you'll be given Q queries, for each query you'll be given X and Y, where X is the source and Y is the destination. You need to print the minimum cost from A to B for each query. If there is no connection between X and Y, print -1.

Note: There can be multiple edges from one node to another.

Input Format

First line will contain N and E.
Next E lines will contain A, B and W.
After that you'll get Q.
Next Q queries will contain X and Y.
Constraints

1 <= N <= 100
1 <= E <= 10^5
1 <= A, B <= N
1 <= W <= 10^9
1 <= Q <= 10^5
1 <= X, Y <= N
Output Format

Output the minimum cost for each query.
Sample Input 0

4 7
1 2 10
2 3 5
3 4 2
4 2 3
3 1 7
2 1 1
1 4 4
6
1 2
4 1
3 1
1 4
2 4
4 2
Sample Output 0

7
4
6
4
5
3
Sample Input 1

4 4
1 2 4
2 3 4
3 1 2
1 2 10
6
1 2
2 1
1 3
3 1
2 3
3 2
Sample Output 1

4
6
8
2
4
6
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, long long int> pii;

const int N = 101;

vector<pii> adj[N];
const long long int INF = LLONG_MAX;
vector<long long int> dist(N, INF);

void dijkstra(int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (pii vPair : adj[u]) {
            int v = vPair.first;
            long long int w = vPair.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int x, y;
        long long int w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        for (int i = 1; i <= v; i++) {
            dist[i] = INF;
        }
        dijkstra(x);

        if (dist[y] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[y] << endl;
        }
    }
}
