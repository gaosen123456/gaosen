#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 100 // 假设队列的最大容量为100

typedef int ElemType; // 假设队列元素类型为整数

// 队列数据结构定义
typedef struct {
    ElemType *base; // 队列底层数组
    int front;      // 队头指针
    int rear;       // 队尾指针
} Queue;

// 初始化顺序队列
void InitQueue(Queue *Q) {
    Q->base = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    assert(Q->base != NULL);
    Q->front = Q->rear = 0;
}

// 入队操作
int EnQueue(Queue *Q, ElemType x) {
    if (Q->rear >= MAXSIZE) {
        // 队列已满，入队失败
        return 0;
    }
    Q->base[Q->rear++] = x;
    return 1; // 入队成功
}

// 打印顺序队列中的元素
void ShowQueue(Queue *Q) {
    for (int i = Q->front; i < Q->rear; ++i) {
        printf("%d ", Q->base[i]);
    }
    printf("\n");
}

// 出队
int DeQueue(Queue *Q) {
    if (Q->front == Q->rear) {
        // 队列为空，出队失败
        return 0;
    }
    Q->front++;
    return 1; // 出队成功
}

// 获取队头元素
int GetHead(Queue *Q, ElemType *v) {
    if (Q->front == Q->rear) {
        // 队列为空，获取失败
        return 0;
    }
    *v = Q->base[Q->front];
    return 1; // 获取成功
}

// 获取队列元素个数
int Length(Queue *Q) {
    return (Q->rear - Q->front);
}

// 清空队列
void ClearQueue(Queue *Q) {
    Q->front = Q->rear = 0;
}

// 销毁队列
void DestroyQueue(Queue *Q) {
    free(Q->base);
    Q->base = NULL;
    Q->front = Q->rear = 0;
}

int main() {
    Queue q;
    InitQueue(&q); // 初始化队列

    EnQueue(&q, 10); // 入队列
    EnQueue(&q, 20);
    EnQueue(&q, 30);

    printf("队列中的元素: ");
    ShowQueue(&q);

    int head;
    if (GetHead(&q, &head)) {
        printf("队头元素: %d\n", head);
    } else {
        printf("队列为空\n");
    }

    DeQueue(&q); // 出队列

    printf("队列中的元素: ");
    ShowQueue(&q);

    ClearQueue(&q); // 清空队列

    if (GetHead(&q, &head)) {
        printf("队头元素: %d\n", head);
    } else {
        printf("队列为空\n");
    }

    DestroyQueue(&q); // 销毁队列

    return 0;
}

