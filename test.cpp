#include<bits/stdc++.h>
using namespace std;
typedef pair<int, long long int> pii;
const int N = 1e5 + 7;
const long long int INF = LLONG_MAX;
vector<pii> g[N];
vector<long long int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (pii vpair : g[u]) {
            int v = vpair.first;
            long long int w = vpair.second;

            if (visited[v]) continue;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        long long int w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
       // g[v].push_back({u, w});
    }
    
    int x;
    cin >> x;
    dijkstra(x);
     int l;
    cin >> l;
    
    while (l--) {
        int a;
        long long int b;
        cin >> a >> b;
        if (dist[a] <= b) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}