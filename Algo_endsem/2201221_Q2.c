#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 999999

typedef struct Edge {
    int destination;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int vertices;
    Edge** adjList;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjList = (Edge**)malloc(vertices * sizeof(Edge*));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int u, int v, int weight) {
    Edge* edge1 = (Edge*)malloc(sizeof(Edge));
    edge1->destination = v;
    edge1->weight = weight;
    edge1->next = graph->adjList[u];
    graph->adjList[u] = edge1;

    Edge* edge2 = (Edge*)malloc(sizeof(Edge));
    edge2->destination = u;
    edge2->weight = weight;
    edge2->next = graph->adjList[v];
    graph->adjList[v] = edge2;
}

void dijkstra(Graph* graph, int source, int* distance) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        distance[i] = INF;
    }

    distance[source] = 0;


    while (1) {
        int minDist = INF;
        int u = -1;

        for (int i = 0; i < graph->vertices; i++) {
            if (!visited[i] && distance[i] < minDist) {
                minDist = distance[i];
                u = i;
            }
        }

        if (u == -1) {
            break; // All vertices visited
        }

        visited[u] = 1;

        Edge* current = graph->adjList[u];
        while (current != NULL) {
            int newDistance = distance[u] + current->weight;
            if (newDistance < distance[current->destination]) {
                distance[current->destination] = newDistance;
            }
            current = current->next;
        }
    }
}

int findEquidistantLocation(Graph* graph, int p, int q) {
    int* distanceP = (int*)malloc(graph->vertices * sizeof(int));
    int* distanceQ = (int*)malloc(graph->vertices * sizeof(int));

    dijkstra(graph, p, distanceP);
    dijkstra(graph, q, distanceQ);

    int minDistance = INF;
    int equidistantLocation = -1;

    for (int i = 0; i < graph->vertices; i++) {
        if (distanceP[i] != INF && distanceQ[i] != INF && distanceP[i] == distanceQ[i]) {
            if (distanceP[i] < minDistance) {
                minDistance = distanceP[i];
                equidistantLocation = i;
            }
        }
    }

    free(distanceP);
    free(distanceQ);

    return equidistantLocation;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        printf("Adjacency list of vertex %d\n", i);
        Edge* current = graph->adjList[i];
        while (current != NULL) {
            printf(" -> %d(%d)", current->destination, current->weight);
            current = current->next;
        }
        printf("\n");
    }
}


int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    Graph* graph = createGraph(vertices);

    printf("Enter the edges and their weights (format: u v weight):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(graph, u, v, weight);
    }

    printGraph(graph);

    int p, q;
    printf("Enter your starting location (p): ");
    scanf("%d", &p);
    printf("Enter your friend's starting location (q): ");
    scanf("%d", &q);

    int equidistantLocation = findEquidistantLocation(graph, p, q);
    if (equidistantLocation != -1) {
        printf("Equidistant location: %d\n", equidistantLocation);
    } else {
        printf("No equidistant location found.\n");
    }

    return 0;
}
