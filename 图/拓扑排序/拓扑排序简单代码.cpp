#include <stdio.h>

#define MAX 100

int adjMatrix[MAX][MAX]; // �ڽӾ���洢ͼ�ı߹�ϵ
int inDegree[MAX]; // �洢ÿ����������
int queue[MAX]; // ���ڴ洢��������Ľ��
int front = -1, rear = -1; // ���е�ǰ��ָ��

// ���һ����
void addEdge(int v, int w) {
    adjMatrix[v][w] = 1; // ���ڽӾ����б�������
    inDegree[w]++; // ͳ�ƶ�������
}

// ��������
void topologicalSort(int n) {
    // �ҵ����Ϊ0�Ķ��㲢���
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    printf("Topological Sort: ");

    // BFS��������
    while (front != rear) {
        // ���Ӳ����
        int vertex = queue[++front];
        printf("%d ", vertex);

        // ��������Ӷ����йصĶ���
        for (int i = 0; i < n; i++) {
            if (adjMatrix[vertex][i]) {
                inDegree[i]--; // �������ڶ�������
                // �����ڶ������Ϊ0�������
                if (inDegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // ��ʼ�����������ڽӾ���
    for (int i = 0; i < n; i++) {
        inDegree[i] = 0;
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    int m;
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges:\n");
    // ����ߵ���Ϣ����ӵ�ͼ��
    for (int i = 0; i < m; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        addEdge(v, w);
    }

    // ������������
    topologicalSort(n);

    return 0;
}
