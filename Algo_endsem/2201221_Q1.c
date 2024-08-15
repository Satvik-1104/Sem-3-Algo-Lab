#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node** adjacencyList;
} Graph;

Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int des);
void findSmallestSet(Graph* graph);

int main() {
    int v, e;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &v, &e);
    Graph* graph = createGraph(v);
	printf("Enter the edges in src, des format.");
	int src, des; 
    for (int i=0;i<e;i++)
	{
		scanf("%d %d", &src, &des);
		addEdge (graph, src, des);
	}

    findSmallestSet(graph);

    // Free allocated memory
    free(graph->adjacencyList);
    free(graph);

    return 0;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (Node**)malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int des) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = des;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

// Function to perform DFS and find the smallest set of vertices
void dfs(int vertex, int* visited, Graph* graph) {
    visited[vertex] = 1;

    Node* current = graph->adjacencyList[vertex];
    while (current != NULL) {
        int neighbor = current->vertex;
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
        current = current->next;
    }
}

void findSmallestSet(Graph* graph) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0;
    }

    // Perform DFS from each unvisited vertex
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            dfs(i, visited, graph);
            visited[i] = 0;
        }
    }

    printf("Smallest set of vertices: ");
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(visited);
}

