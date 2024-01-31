#include <stdio.h>
#include <stdlib.h>

// ������нڵ�Ľṹ
typedef struct Node {
    int data;            // �ڵ������
    struct Node* next;   // ָ����һ���ڵ��ָ��
} Node;

// ������еĽṹ
typedef struct {
    Node* front;    // ָ�����ͷ����ָ��
    Node* rear;     // ָ�����β����ָ��
} Queue;

// ��ʼ������
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue* q) {
    return (q->front == NULL);
}

// ����У����Ԫ�أ�
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("�ڴ����ʧ��\n");
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

    printf("%d �����\n", value);
}

// �����У��Ƴ�Ԫ�أ�
void dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("����Ϊ��\n");
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    printf("%d ������\n", temp->data);
    free(temp);
}

// ��ӡ���еĵ�ǰԪ��
void printQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("����Ϊ��\n");
        return;
    }

    printf("����Ԫ�أ�");
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
        printf("���е�ǰ��Ԫ�أ�%d\n", q.front->data);
        printf("���еĺ��Ԫ�أ�%d\n", q.rear->data);
    }

    return 0;
}

