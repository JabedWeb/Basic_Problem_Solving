/*
Can Go Again?
Problem
Submissions
Leaderboard
Discussions
Problem Statement

You will be given N numbers of nodes, E numbers of edges in a graph. For each edge you will be given A, B and W which means there is a connection from A to B for which you need to give W cost. The value of nodes could be from 1 to N.

You will be given a source node S. Then you will be given a test case T, for each test case you will be given a destination node D. You need to tell the minimum cost from source node to destination. If there is no possible path from S to D then print Not Possible.

Note: If there is a negative weight cycle in the graph, then no answer would be correct. So print one line only - "Negative Cycle Detected".

Input Format

First line will contain N and E.
Next E lines will contain A, B and W.
Next line will contain source node S.
Next line will contain T, the number of test cases.
For each test case, you will get D.
Constraints

1 <= N <= 1000
1 <= E <= 1000
1 <= S <= N
1 <= T <= 1000
1 <= D <= N
-10^9 <= W <= 10^9
Output Format

Ouput "YES" or "NO" for each test case if it is possible to go from S to D in DW cost.
Sample Input 0

5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
1
5
1
2
3
4
5
Sample Output 0

0
-1
-2
-5
0
Sample Input 1

5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
5
5
1
2
3
4
5
Sample Output 1

Not Possible
Not Possible
Not Possible
Not Possible
0
Sample Input 2

5 8
1 2 -2
1 3 -10
3 2 1
2 4 7
4 3 -3
4 5 5
2 5 2
4 1 1
1
5
1
2
3
4
5
Sample Output 2

Negative Cycle Detected
*/

#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

class Edge {
    public :
    int source, dest;
    long long weight;
};

vector<Edge> edges;
vector<long long> dist;

bool bellmanFord(int source, int n) {
    dist[source] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (Edge edge : edges) {
            int u = edge.source;
            int v = edge.dest;
            long long w = edge.weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (Edge edge : edges) {
        int u = edge.source;
        int v = edge.dest;
        long long w = edge.weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, e;
    cin >> n >> e;

    dist.resize(n + 1, INF);

    for (int i = 0; i < e; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }

    int source; 
    cin >> source;

    int t;
    cin >> t;

    while (t--) {
        int dest;
        cin >> dest;

        if (bellmanFord(source, n)) {
            if (dist[dest] != INF) {
                cout << dist[dest] << endl;
            } else {
                cout << "Not Possible" << endl;
            }
        } else {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
    }

    return 0;
}
