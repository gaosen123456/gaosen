#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// 定义图的节点结构
typedef struct Node {
    int vertex;         // 节点的索引
    struct Node* next;  // 下一个节点的指针
} Node;

// 定义图的结构
typedef struct Graph {
    int numVertices;           // 图中顶点的数量
    Node* adjLists[MAX_VERTICES];  // 存储每个顶点的邻接链表
    int visited[MAX_VERTICES];     // 记录顶点是否被访问过
} Graph;

// 初始化图
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    
    // 初始化每个邻接链表为NULL，visited数组为0（表示未访问）
    int i;
    for (i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    
    return graph;
}

// 添加边
void addEdge(Graph* graph, int src, int dest) {
    // 添加从src到dest的边
    
    // 创建一个新节点，并将其索引设为dest
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    
    // 将新节点插入到邻接链表的头部
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
 
    // 添加从dest到src的边（无向图）
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    
    // 将新节点插入到邻接链表的头部
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// 广度优先搜索
void breadthFirstSearch(Graph* graph, int startVertex) {
    // 创建一个队列用于存储待访问的顶点
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
 
    // 标记起始顶点为已访问，并将其加入队列
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS traversal starting from vertex %d: ", startVertex);
 
    while (front < rear) {
        // 从队列中取出一个顶点并打印
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
 
        // 遍历与当前顶点相邻的顶点
        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            // 如果相邻顶点未访问，则标记为已访问并将其加入队列
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    Graph* graph = createGraph(6);
    
    // 添加边
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    // 从顶点0开始进行广度优先搜索
    breadthFirstSearch(graph, 0);

    return 0;
}
