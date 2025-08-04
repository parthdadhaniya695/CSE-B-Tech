#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge edge[MAX];
};

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void* a, const void* b) {
    struct Edge* A = (struct Edge*)a;
    struct Edge* B = (struct Edge*)b;
    return A->weight - B->weight;
}

void kruskal(struct Graph* g) {
    int i, j;
    int cost = 0;

    // Sort edges by weight
    qsort(g->edge, g->E, sizeof(g->edge[0]), compare);

    // Initialize parent array
    for (i = 0; i < g->V; i++)
        parent[i] = i;

    printf("Edges in MST:\n");
    for (i = 0, j = 0; j < g->V - 1 && i < g->E; i++) {
        int u = g->edge[i].src;
        int v = g->edge[i].dest;

        if (find(u) != find(v)) {
            printf("%d - %d : %d\n", u, v, g->edge[i].weight);
            union_set(u, v);
            cost += g->edge[i].weight;
            j++;
        }
    }

    printf("Total cost of MST: %d\n", cost);
}

int main() {
    struct Graph g;
    g.V = 4;
    g.E = 5;

    g.edge[0] = (struct Edge){0, 1, 10};
    g.edge[1] = (struct Edge){0, 2, 6};
    g.edge[2] = (struct Edge){0, 3, 5};
    g.edge[3] = (struct Edge){1, 3, 15};
    g.edge[4] = (struct Edge){2, 3, 4};

    kruskal(&g);

    return 0;
}