#include <stdio.h>
#include <limits.h>

int V = 0;

int minDistance(int dist[], int visited_node[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (visited_node[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void print(int dist[])
{
    char a = 'A';
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("  %c \t\t %d\n", a + i, dist[i]);
}

void djkstra(int graph[V][V], int src)
{
    int dist[V], visited_node[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited_node[i] = 0;
    }
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {

        int u = minDistance(dist, visited_node);

        // Mark the current vertex as visited
        visited_node[u] = 1;

        // Update dist value of the adjacent vertices of the current vertex.
        for (int v = 0; v < V; v++)
        {
            if (!visited_node[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    // print the constructed distance array
    print(dist);
}

int main()
{
    int n, e, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    int graph[n][n];
    V = n;
    for (i = 0; i < e; i++)
    {
        int firstNode, secondNode, weight;
        printf("Enter firstNode secondNode: ");
        scanf("%d %d", &firstNode, &secondNode);
        printf("Enter edge weight: ");
        scanf("%d", &weight);
        graph[firstNode][secondNode] = weight;
        graph[secondNode][firstNode] = weight;
    }
    djkstra(graph, 0);
    return 0;
}
