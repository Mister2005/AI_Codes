#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Node structure for adjacency list
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Graph structure containing adjacency lists
typedef struct Graph {
    Node* adjList[MAX_NODES];
    int numNodes;
} Graph;

// Function to create a new graph with n nodes
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = n;
    for (int i = 0; i < n; ++i) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// DFS traversal function
void DFSUtil(Graph* graph, int node, int visited[]) {
    visited[node] = 1;
    printf("%d ", node);

    Node* curr = graph->adjList[node];
    while (curr != NULL) {
        int neighbor = curr->dest;
        if (!visited[neighbor]) {
            DFSUtil(graph, neighbor, visited);
        }
        curr = curr->next;
    }
}

// DFS function to traverse the entire graph
void DFS(Graph* graph, int startNode) {
    int visited[MAX_NODES] = {0}; // Array to keep track of visited nodes
    DFSUtil(graph, startNode, visited);
}

// Main function for testing DFS
int main() {
    Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("Depth-First Traversal starting from vertex 0: ");
    DFS(graph, 0);

    return 0;
}
