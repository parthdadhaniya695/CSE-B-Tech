#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
void dfs(int graph[MAX][MAX], int n, int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal starting from vertex %d:\n", start);
    dfs(graph, n, start);

    return 0;
}