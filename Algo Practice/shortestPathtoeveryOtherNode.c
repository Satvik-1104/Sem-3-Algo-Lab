#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct node
{
    int data;
    struct node * next;
}Node;

typedef struct adjList
{
    struct Node * head;
}AdjList;

typedef struct graph
{
    int vertices;
    AdjList * AdjListArray;
}Graph;

typedef struct queue
{
    int vertices[MAX_VERTICES];
    int front;
    int rear;
}Queue;

Node * createNode (int data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

Queue * createQueue ()
{
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q -> front = -1;
    q -> rear = -1;
    return q;
}

Graph * createGraph (int v)
{
    Graph * graph = (Graph *)malloc(sizeof(Graph));
    graph -> vertices = v;
    graph -> AdjListArray = (AdjList *)malloc((graph -> vertices) * sizeof(AdjList));
    for (int i = 0; i < graph -> vertices; i++)
    {
        graph -> AdjListArray[i].head = NULL;
    }
    return graph;
}

int isEmpty (Queue * q)
{
    if (q -> front > q -> rear)
    return 1;

    return 0;
}

void enQueue (Queue * q, int vertex)
{
    if (isEmpty(q))
    {
        q -> front = 0;
        q -> rear++;
    }
    q -> vertices[q -> rear] = vertex;
}

int deQueue (Queue * q)
{
    int curVer;
    if (q -> front == q -> rear)
    {
        curVer = q -> vertices[q -> front];
        q -> front = -1;
        q -> rear = -1;
    }
    else
    {
        curVer = q -> vertices[q -> front];
        q -> front++;
    }
    return curVer;
}

void printAdjList (Graph * graph)
{
    
}

int main ()
{

}