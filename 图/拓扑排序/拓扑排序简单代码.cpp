#include <stdio.h>

#define MAX 100

int adjMatrix[MAX][MAX]; // 邻接矩阵存储图的边关系
int inDegree[MAX]; // 存储每个顶点的入度
int queue[MAX]; // 用于存储拓扑排序的结果
int front = -1, rear = -1; // 队列的前后指针

// 添加一条边
void addEdge(int v, int w) {
    adjMatrix[v][w] = 1; // 在邻接矩阵中标记有向边
    inDegree[w]++; // 统计顶点的入度
}

// 拓扑排序
void topologicalSort(int n) {
    // 找到入度为0的顶点并入队
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    printf("Topological Sort: ");

    // BFS拓扑排序
    while (front != rear) {
        // 出队并输出
        int vertex = queue[++front];
        printf("%d ", vertex);

        // 遍历与出队顶点有关的顶点
        for (int i = 0; i < n; i++) {
            if (adjMatrix[vertex][i]) {
                inDegree[i]--; // 减少相邻顶点的入度
                // 若相邻顶点入度为0，则入队
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

    // 初始化入度数组和邻接矩阵
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
    // 输入边的信息并添加到图中
    for (int i = 0; i < m; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        addEdge(v, w);
    }

    // 进行拓扑排序
    topologicalSort(n);

    return 0;
}
