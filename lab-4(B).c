//kruskal
#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7

struct Edge {
    int src, dest, weight;
};

struct Graph {
    struct Edge edge[E];
};

int parent[V];

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);  // Path compression
    return parent[i];
}

void unionSet(int u, int v) {
    int uroot = find(u);
    int vroot = find(v);
    parent[uroot] = vroot;
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST(struct Graph* graph) {
    struct Edge result[V];  // To store MST edges
    int e = 0;              // Index for result[]
    int i = 0;              // Index for sorted edges

    for (int v = 0; v < V; v++)
        parent[v] = v;

    qsort(graph->edge, E, sizeof(graph->edge[0]), compareEdges);

    while (e < V - 1 && i < E) {
        struct Edge next_edge = graph->edge[i++];

        int x = find(next_edge.src);
        int y = find(next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            unionSet(x, y);
        }
    }

    int totalWeight = 0;
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

int main() {
    struct Graph graph = {{
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
        {1, 4, 9},
        {3, 4, 7}
    }};

    kruskalMST(&graph);
    return 0;
}

