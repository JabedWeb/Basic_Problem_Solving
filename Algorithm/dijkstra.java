import java.util.*;

public class dijkstra {
    static final int inf = (int) 1e7;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();

        List<List<Pair>> graph = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        int[] dist = new int[n + 1];
        Arrays.fill(dist, inf);

        for (int i = 0; i < m; i++) {
            int u = input.nextInt();
            int v = input.nextInt();
            int w = input.nextInt();
            graph.get(u).add(new Pair(v, w));
            graph.get(v).add(new Pair(u, w));
        }

        int source = input.nextInt();
        input.close();

        dist[source] = 0;

        TreeSet<Pair> set = new TreeSet<>();
        for (int i = 1; i <= n; i++) {
            if (dist[i] < inf)
                System.out.print(dist[i] + "\t");
            else
                System.out.print(-1 + "\t");
        }
        System.out.println();

        set.add(new Pair(0, source));
        while (!set.isEmpty()) {
            Pair x = set.pollFirst();
            int vertex = x.second;
            for (Pair i : graph.get(vertex)) {
                if (dist[i.first] > dist[vertex] + i.second) {
                    set.remove(new Pair(dist[i.first], i.first));
                    dist[i.first] = dist[vertex] + i.second;
                    set.add(new Pair(dist[i.first], i.first));
                }
            }
            for (int i = 1; i <= n; i++) {
                if (dist[i] < inf)
                    System.out.print(dist[i] + "\t");
                else
                    System.out.print(-1 + "\t");
            }
            System.out.println();
        }

        System.out.print("final output: \t");
        for (int i = 1; i <= n; i++) {
            if (dist[i] < inf)
                System.out.print(dist[i] + "\t");
            else
                System.out.print(-1 + "\t");
        }
    }

    static class Pair implements Comparable<Pair> {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.first == other.first) {
                return Integer.compare(this.second, other.second);
            }
            return Integer.compare(this.first, other.first);
        }
    }
}
