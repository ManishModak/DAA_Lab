#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v, w;
};

int bellmanFord(int n, int m, int src, int dest, vector<Edge> &edges) {
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0; 

    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycles
    bool hasNegativeCycle = false;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        return -1; // Negative cycle detected
    }

    return dist[dest];
}

int main() {
    int n, m, src, dest;
    cout << "Enter the number of nodes (n): ";
    cin >> n;
    cout << "Enter the number of edges (m): ";
    cin >> m;

    vector<Edge> edges(m);
    cout << "Enter the edges in the format (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    cout << "Enter the source node: ";
    cin >> src;
    cout << "Enter the destination node: ";
    cin >> dest;

    int shortestDistance = bellmanFord(n, m, src, dest, edges);

    if (shortestDistance == -1) {
        cout << "There is a negative cycle in the graph." << endl;
    } else {
        cout << "Shortest distance from node " << src << " to node " << dest << ": " << shortestDistance << endl;
    }

    return 0;
}
