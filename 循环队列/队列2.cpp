#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义队列的结构
typedef struct {
    int data[MAX_SIZE];  // 数组用于存储队列数据
    int front, rear;     // 队列前后位置指针
} Queue;

// 初始化队列
void initQueue(Queue *q) {
    q->front = q->rear = 0;  // 将队列的前后位置指针初始化为0，表示队列为空
}

// 判断队列是否为空
int isQueueEmpty(Queue *q) {
    return (q->front == q->rear);  // 若前后位置指针相等，则队列为空，返回1，否则返回0
}

// 判断队列是否为满
int isQueueFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);  // 若前后位置指针相差1，队列为满，返回1，考虑循环的情况
}

// 入队列（添加元素）
void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {  // 若队列已满
        printf("队列已满\n");  // 输出信息并返回
        return;
    }
    q->data[q->rear] = value;  // 将值放入队列的后位置
    q->rear = (q->rear + 1) % MAX_SIZE;  // 更新队列的后位置指针，考虑循环的情况
    printf("%d 入队列\n", value);  // 输出信息
}

// 出队列（移除元素）
void dequeue(Queue *q) {
    if (isQueueEmpty(q)) {  // 若队列为空
        printf("队列为空\n");  // 输出信息并返回
        return;
    }
    printf("%d 出队列\n", q->data[q->front]);  // 输出被出队列的元素值
    q->front = (q->front + 1) % MAX_SIZE;  // 更新队列的前位置指针，考虑循环的情况
}

// 打印队列的当前元素
void printQueue(Queue *q) {
    if (isQueueEmpty(q)) {  // 若队列为空
        printf("队列为空\n");  // 输出信息并返回
        return;
    }
    printf("队列元素：");
    int i = q->front;
    while (i != q->rear) {  // 遍历队列元素
        printf("%d ", q->data[i]);  // 输出当前元素
        i = (i + 1) % MAX_SIZE;  // 移动到下一个位置，考虑循环的情况
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);  // 初始化队列

    enqueue(&q, 10);  // 入队列一些元素
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printQueue(&q);  // 入队列后打印元素

    dequeue(&q);  // 出队列一些元素
    dequeue(&q);

    printQueue(&q);  // 出队列后打印元素

    printf("队列的前端元素：%d\n", q.data[q.front]);  // 打印前端元素
    printf("队列的后端元素：%d\n", q.data[(q.rear - 1 + MAX_SIZE) % MAX_SIZE]);  // 打印后端元素，考虑循环的情况

    return 0;
}

