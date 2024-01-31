#include <stdio.h>
#include <stdlib.h>

// ����ͼ�ڵ�����ݽṹ
struct Node {
    int vertex;
    struct Node* next;
};

// ����ͼ�����ݽṹ
struct Graph {
    int numVertices;
    struct Node** adjacencyList;
    int* visited;
};

// ����ͼ�ڵ�
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// ����ͼ
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// ��ӱ�
void addEdge(struct Graph* graph, int src, int dest) {
    // ��� src -> dest ��
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // ��� dest -> src ��
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// �����������
void DFS(struct Graph* graph, int vertex) {
    printf("%d ", vertex);
    graph->visited[vertex] = 1;

    struct Node* adjList = graph->adjacencyList[vertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->vertex;
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        adjList = adjList->next;
    }
}

int main() {
    struct Graph* graph = createGraph(5); // ��������5�������ͼ

    // ��ӱ�
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("������ȱ��������\n");
    DFS(graph, 2); // �Ӷ���2��ʼ���������������

    return 0;
}

