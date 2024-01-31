#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// ͼ���ڽӾ����ʾ
typedef struct {
    int vertices[MAX_SIZE][MAX_SIZE];
    int numVertices;
} Graph;

// ��ʼ��ͼ
void initGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->vertices[i][j] = 0;
        }
    }
}

// ��ӱ�
void addEdge(Graph* graph, int src, int dest) {
    graph->vertices[src][dest] = 1;
    graph->vertices[dest][src] = 1;
}

// ���������������ͼ
void breadthFirstSearch(Graph* graph, int startVertex) {
    bool visited[MAX_SIZE] = { false };
    int queue[MAX_SIZE];
    int front = -1, rear = -1;

    // ����ʼ������Ӳ����Ϊ�ѷ���
    queue[++rear] = startVertex;
    visited[startVertex] = true;

    while (front != rear) {
        // ���Ӳ�����
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        // ������ǰ������ڽӶ���
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->vertices[currentVertex][i] == 1 && !visited[i]) {
                // �ڽӶ�����Ӳ����Ϊ�ѷ���
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    Graph graph;
    int numVertices, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    initGraph(&graph, numVertices);

    int src, dest;
    while (true) {
        printf("Enter edge (-1 -1 to exit): ");
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1) {
            break;
        }
        addEdge(&graph, src, dest);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("Breadth First Search Traversal: ");
    breadthFirstSearch(&graph, startVertex);

    return 0;
}
