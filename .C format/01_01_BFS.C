#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Structure to represent a node in the graph
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Structure to represent a queue
typedef struct Queue {
    Node* front, *rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue a node
void enqueue(Queue* queue, int data) {
    Node* node = newNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}

// Function to dequeue a node
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

// Breadth-First Search algorithm
void BFS(int graph[MAX_SIZE][MAX_SIZE], int vertices, int startVertex) {
    int visited[MAX_SIZE] = { 0 }; // Array to track visited vertices
    Queue* queue = createQueue(); // Create a queue for BFS traversal

    visited[startVertex] = 1; // Mark the start vertex as visited
    enqueue(queue, startVertex); // Enqueue the start vertex

    printf("Breadth-First Traversal starting from vertex %d: ", startVertex);

    while (!isEmpty(queue)) {
        int vertex = dequeue(queue); // Dequeue a vertex
        printf("%d ", vertex); // Print the dequeued vertex

        // Traverse all adjacent vertices of the dequeued vertex
        for (int i = 0; i < vertices; ++i) {
            if (graph[vertex][i] && !visited[i]) { // If an adjacent vertex is not visited
                visited[i] = 1; // Mark it as visited
                enqueue(queue, i); // Enqueue it
            }
        }
    }

    printf("\n");
}

int main() {
    int vertices, edges, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_SIZE][MAX_SIZE] = { 0 };

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    BFS(graph, vertices, startVertex);

    return 0;
}
