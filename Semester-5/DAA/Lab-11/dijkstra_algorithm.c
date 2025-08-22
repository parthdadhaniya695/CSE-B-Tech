#include <stdio.h>
#include <limits.h>

#define V 5
#define INF 99999

int graph[V][V] = {
    {0, 75, 10, INF, INF},
    {75, 0, INF, 9, 31},
    {10, INF, 0, 95, 91},
    {INF, 9, 95, 0, 42},
    {INF, 31, 91, 42, 0}
};

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's algorithm
void dijkstra(int src) {
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nVertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int src;
    printf("Enter source vertex (0 to %d): ", V - 1);
    scanf("%d", &src);

    if (src < 0 || src >= V) {
        printf("Invalid source vertex. Please enter a value between 0 and %d.\n", V - 1);
        return 1;
    }

    dijkstra(src);
    return 0;
}