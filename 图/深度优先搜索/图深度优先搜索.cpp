#include <stdio.h>
#include <stdlib.h>

// 定义图节点的数据结构
struct Node {
    int vertex;
    struct Node* next;
};

// 定义图的数据结构
struct Graph {
    int numVertices;
    struct Node** adjacencyList;
    int* visited;
};

// 创建图节点
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// 创建图
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

// 添加边
void addEdge(struct Graph* graph, int src, int dest) {
    // 添加 src -> dest 边
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // 添加 dest -> src 边
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// 深度优先搜索
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
    struct Graph* graph = createGraph(5); // 创建包含5个顶点的图

    // 添加边
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("深度优先遍历结果：\n");
    DFS(graph, 2); // 从顶点2开始进行深度优先搜索

    return 0;
}

