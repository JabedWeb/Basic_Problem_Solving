#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const long long INF = LLONG_MAX;

long long d[N][N];
int n, m;

void dist_initialize() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                d[i][j] = INF;
            } else {
                d[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    dist_initialize();

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;

        if (d[x][y] == INF) {
            cout << -1 << endl;
        } else {
            cout << d[x][y] << endl;
        }
    }

    return 0;
}
