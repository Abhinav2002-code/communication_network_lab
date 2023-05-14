#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_V 100 // maximum number of vertices in the graph

struct Edge {
    int src, dest, weight;
};

void bellman_ford(struct Edge edges[], int num_edges, int src, int V) {
    int dist[MAX_V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    bool updated;
    for (int i = 0; i < V - 1; i++) {
        updated = false;
        for (int j = 0; j < num_edges; j++) {
            if (dist[edges[j].src] != INT_MAX && dist[edges[j].src] + edges[j].weight < dist[edges[j].dest]) {
                dist[edges[j].dest] = dist[edges[j].src] + edges[j].weight;
                updated = true;
            }
        }
        if (!updated) {
            break; // exit the loop if no updates were made in this iteration
        }
    }
    // Check for negative weight cycles
    for (int i = 0; i < num_edges; i++) {
        if (dist[edges[i].src] != INT_MAX && dist[edges[i].src] + edges[i].weight < dist[edges[i].dest]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    // Print the shortest distances
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int num_edges, src, V;
    printf("Enter number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter number of edges in the graph: ");
    scanf("%d", &num_edges);
    struct Edge edges[num_edges];
    printf("Enter edges (source, destination, weight):\n");
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    printf("Enter starting vertex: ");
    scanf("%d", &src);
    bellman_ford(edges, num_edges, src, V);
    return 0;
}
