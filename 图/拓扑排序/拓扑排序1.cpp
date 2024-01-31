#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Node {
    int value;
    struct Node* next;
};

struct Graph {
    int numNodes;
    struct Node* adjLists[MAX_NODES];
    int inDegrees[MAX_NODES];
};

struct Graph* createGraph(int numNodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = numNodes;
    
    for (int i = 0; i < numNodes; ++i) {
        graph->adjLists[i] = NULL;
        graph->inDegrees[i] = 0;
    }
    
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    graph->inDegrees[dest]++;
}

void topologicalSort(struct Graph* graph) {
    int visited[MAX_NODES];
    for (int i = 0; i < graph->numNodes; ++i) {
        visited[i] = 0;
    }
    
    for (int i = 0; i < graph->numNodes; ++i) {
        if (graph->inDegrees[i] == 0 && !visited[i]) {
            visited[i] = 1;
            printf("%d ", i);
            
            struct Node* temp = graph->adjLists[i];
            while (temp != NULL) {
                graph->inDegrees[temp->value]--;
                temp = temp->next;
            }
            
            topologicalSort(graph);
        }
    }
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    
    printf("Topological Sort: ");
    topologicalSort(graph);
    
    return 0;
}

