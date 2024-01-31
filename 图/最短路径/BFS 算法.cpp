#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 6

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (queue->size == queue->capacity)
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void BFS(Node* adjList[], int start, int end) {
    Queue* queue = createQueue(MAX_NODES);
    bool visited[MAX_NODES] = {false};
    int parent[MAX_NODES] = {-1};

    enqueue(queue, start);
    visited[start] = true;

    while (!isEmpty(queue)) {
        int current = dequeue(queue);

        if (current == end)
            break;

        Node* temp = adjList[current];
        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                enqueue(queue, neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            }
            temp = temp->next;
        }
    }

    if (!visited[end]) {
        printf("No path found between %d and %d\n", start, end);
        return;
    }

    printf("Shortest path from %d to %d: ", start, end);
    int current = end;
    int path[MAX_NODES];
    int pathLength = 0;
    while (current != -1) {
        path[pathLength++] = current;
        current = parent[current];
    }

    for (int i = pathLength - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    Node* adjList[MAX_NODES] = {NULL};

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 3, 5);
    addEdge(adjList, 4, 5);

    int start = 0;
    int end = 5;
    BFS(adjList, start, end);

    return 0;
}

