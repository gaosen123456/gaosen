#include <stdio.h>
#include <stdlib.h>

// 定义队列节点的结构
typedef struct Node {
    int data;            // 节点的数据
    struct Node* next;   // 指向下一个节点的指针
} Node;

// 定义队列的结构
typedef struct {
    Node* front;    // 指向队列头部的指针
    Node* rear;     // 指向队列尾部的指针
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// 判断队列是否为空
int isQueueEmpty(Queue* q) {
    return (q->front == NULL);
}

// 入队列（添加元素）
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("内存分配失败\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("%d 入队列\n", value);
}

// 出队列（移除元素）
void dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("队列为空\n");
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    printf("%d 出队列\n", temp->data);
    free(temp);
}

// 打印队列的当前元素
void printQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("队列为空\n");
        return;
    }

    printf("队列元素：");
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printQueue(&q);

    dequeue(&q);
    dequeue(&q);

    printQueue(&q);

    if (!isQueueEmpty(&q)) {
        printf("队列的前端元素：%d\n", q.front->data);
        printf("队列的后端元素：%d\n", q.rear->data);
    }

    return 0;
}

