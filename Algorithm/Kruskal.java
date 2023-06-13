import java.util.*;

public class Kruskal {
    static int[] parent;
    static int[] sz;

    static void makeSet(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    static int findSet(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = findSet(parent[v]);
    }

    static void unionSets(int a, int b) {
        a = findSet(a);
        b = findSet(b);

        if (a != b) {
            if (sz[a] < sz[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        parent = new int[n + 1];
        sz = new int[n + 1];
        for (int i = 1; i <= n; i++)
            makeSet(i);

        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            edges.add(new int[]{w, u, v});
        }

        edges.sort(Comparator.comparingInt(a -> a[0]));
        int cost = 0;
        for (int[] edge : edges) {
            int w = edge[0];
            int u = edge[1];
            int v = edge[2];
            int x = findSet(u);
            int y = findSet(v);

            if (x != y) {
                cost += w;
                unionSets(u, v);
            }
        }

        System.out.println("Minimum cost is: " + cost);
    }
}
