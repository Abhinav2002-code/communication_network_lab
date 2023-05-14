#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6 // number of vertices in the graph

void dijkstra(int graph[V][V], int src) {
   int dist[V];
   bool visited[V] = {false};
   for (int i = 0; i < V; i++) {
      dist[i] = INT_MAX;
   }
   dist[src] = 0;
   for (int count = 0; count < V-1; count++) {
      int u, min = INT_MAX;
      for (int v = 0; v < V; v++) {
         if (!visited[v] && dist[v] <= min) {
            min = dist[v], u = v;
         }
      }
      visited[u] = true;
      for (int v = 0; v < V; v++) {
         if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
               && dist[u]+graph[u][v] < dist[v]) {
            dist[v] = dist[u] + graph[u][v];
         }
      }
   }
   printf("Vertex \t Distance from Source\n");
   for (int i = 0; i < V; i++) {
      printf("%d \t\t %d\n", i, dist[i]);
   }
}

int main() {
    int G[V][V], i, j, u;
     printf("\nEnter the adjacency matrix::");
     for(i=0; i<V; i++)
     for(j=0; j<V; j++)
     scanf("%d", &G[i][j]);
     printf("\nEnter the starting node:: ");
     scanf("%d", &u);
   dijkstra(G, u);
   return 0;
}
