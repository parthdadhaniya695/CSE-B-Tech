#include <stdio.h>
#define MAX 100
#define INF 99999

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX], visited[MAX];

    // Initialize distances and visited array
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u;

        // Find the unvisited node with the smallest distance
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update distances of adjacent nodes
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances
    printf("\nShortest distances from node %d:\n", start);
    for (int i = 0; i < n; i++) {
        printf("To node %d: %d\n", i, dist[i]);
    }
}

int main() {
    int n, graph[MAX][MAX], start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}