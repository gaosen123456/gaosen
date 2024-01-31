#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// ����ͼ�Ľڵ�ṹ
typedef struct Node {
    int vertex;         // �ڵ������
    struct Node* next;  // ��һ���ڵ��ָ��
} Node;

// ����ͼ�Ľṹ
typedef struct Graph {
    int numVertices;           // ͼ�ж��������
    Node* adjLists[MAX_VERTICES];  // �洢ÿ��������ڽ�����
    int visited[MAX_VERTICES];     // ��¼�����Ƿ񱻷��ʹ�
} Graph;

// ��ʼ��ͼ
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    
    // ��ʼ��ÿ���ڽ�����ΪNULL��visited����Ϊ0����ʾδ���ʣ�
    int i;
    for (i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    
    return graph;
}

// ��ӱ�
void addEdge(Graph* graph, int src, int dest) {
    // ��Ӵ�src��dest�ı�
    
    // ����һ���½ڵ㣬������������Ϊdest
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    
    // ���½ڵ���뵽�ڽ������ͷ��
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
 
    // ��Ӵ�dest��src�ıߣ�����ͼ��
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    
    // ���½ڵ���뵽�ڽ������ͷ��
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// �����������
void breadthFirstSearch(Graph* graph, int startVertex) {
    // ����һ���������ڴ洢�����ʵĶ���
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
 
    // �����ʼ����Ϊ�ѷ��ʣ�������������
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS traversal starting from vertex %d: ", startVertex);
 
    while (front < rear) {
        // �Ӷ�����ȡ��һ�����㲢��ӡ
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
 
        // �����뵱ǰ�������ڵĶ���
        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            // ������ڶ���δ���ʣ�����Ϊ�ѷ��ʲ�����������
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
    
    // ��ӱ�
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    // �Ӷ���0��ʼ���й����������
    breadthFirstSearch(graph, 0);

    return 0;
}
