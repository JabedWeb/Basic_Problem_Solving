
#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, w;
    Edge(int a, int b, int w) : a(a), b(b), w(w) {}
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

vector<int> parent;
vector<int> parentSize;

int dsu_find(int n) {
    if (parent[n] == n)
        return n;
    return parent[n] = dsu_find(parent[n]);
}

void dsu_union(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB) {
        if (parentSize[leaderA] > parentSize[leaderB])
            swap(leaderA, leaderB);

        parent[leaderA] = leaderB;
        parentSize[leaderB] += parentSize[leaderA];
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    parent.resize(N + 1);
    parentSize.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        parentSize[i] = 1;
    }

    vector<Edge> edges;

    for (int i = 0; i < E; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(Edge(a, b, w));
    }

    sort(edges.begin(), edges.end(), cmp);

    int totalCost = 0;
    int numRemoved = 0;

    for (Edge edge : edges) {
        int a = edge.a;
        int b = edge.b;
        int w = edge.w;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA != leaderB) {
            dsu_union(a, b);
            totalCost += w;
        } else {
            numRemoved++;
        }
    }

    if (parentSize[dsu_find(1)] != N) {
        cout << "Not Possible" << endl;
    } else {
        cout << numRemoved << " " << totalCost << endl;
    }

    return 0;
}
