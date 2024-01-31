#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// ������еĽṹ
typedef struct {
    int data[MAX_SIZE];  // �������ڴ洢��������
    int front, rear;     // ����ǰ��λ��ָ��
} Queue;

// ��ʼ������
void initQueue(Queue *q) {
    q->front = q->rear = 0;  // �����е�ǰ��λ��ָ���ʼ��Ϊ0����ʾ����Ϊ��
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue *q) {
    return (q->front == q->rear);  // ��ǰ��λ��ָ����ȣ������Ϊ�գ�����1�����򷵻�0
}

// �ж϶����Ƿ�Ϊ��
int isQueueFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);  // ��ǰ��λ��ָ�����1������Ϊ��������1������ѭ�������
}

// ����У����Ԫ�أ�
void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {  // ����������
        printf("��������\n");  // �����Ϣ������
        return;
    }
    q->data[q->rear] = value;  // ��ֵ������еĺ�λ��
    q->rear = (q->rear + 1) % MAX_SIZE;  // ���¶��еĺ�λ��ָ�룬����ѭ�������
    printf("%d �����\n", value);  // �����Ϣ
}

// �����У��Ƴ�Ԫ�أ�
void dequeue(Queue *q) {
    if (isQueueEmpty(q)) {  // ������Ϊ��
        printf("����Ϊ��\n");  // �����Ϣ������
        return;
    }
    printf("%d ������\n", q->data[q->front]);  // ����������е�Ԫ��ֵ
    q->front = (q->front + 1) % MAX_SIZE;  // ���¶��е�ǰλ��ָ�룬����ѭ�������
}

// ��ӡ���еĵ�ǰԪ��
void printQueue(Queue *q) {
    if (isQueueEmpty(q)) {  // ������Ϊ��
        printf("����Ϊ��\n");  // �����Ϣ������
        return;
    }
    printf("����Ԫ�أ�");
    int i = q->front;
    while (i != q->rear) {  // ��������Ԫ��
        printf("%d ", q->data[i]);  // �����ǰԪ��
        i = (i + 1) % MAX_SIZE;  // �ƶ�����һ��λ�ã�����ѭ�������
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);  // ��ʼ������

    enqueue(&q, 10);  // �����һЩԪ��
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printQueue(&q);  // ����к��ӡԪ��

    dequeue(&q);  // ������һЩԪ��
    dequeue(&q);

    printQueue(&q);  // �����к��ӡԪ��

    printf("���е�ǰ��Ԫ�أ�%d\n", q.data[q.front]);  // ��ӡǰ��Ԫ��
    printf("���еĺ��Ԫ�أ�%d\n", q.data[(q.rear - 1 + MAX_SIZE) % MAX_SIZE]);  // ��ӡ���Ԫ�أ�����ѭ�������

    return 0;
}

