#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 100 // ������е��������Ϊ100

typedef int ElemType; // �������Ԫ������Ϊ����

// �������ݽṹ����
typedef struct {
    ElemType *base; // ���еײ�����
    int front;      // ��ͷָ��
    int rear;       // ��βָ��
} Queue;

// ��ʼ��˳�����
void InitQueue(Queue *Q) {
    Q->base = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    assert(Q->base != NULL);
    Q->front = Q->rear = 0;
}

// ��Ӳ���
int EnQueue(Queue *Q, ElemType x) {
    if (Q->rear >= MAXSIZE) {
        // �������������ʧ��
        return 0;
    }
    Q->base[Q->rear++] = x;
    return 1; // ��ӳɹ�
}

// ��ӡ˳������е�Ԫ��
void ShowQueue(Queue *Q) {
    for (int i = Q->front; i < Q->rear; ++i) {
        printf("%d ", Q->base[i]);
    }
    printf("\n");
}

// ����
int DeQueue(Queue *Q) {
    if (Q->front == Q->rear) {
        // ����Ϊ�գ�����ʧ��
        return 0;
    }
    Q->front++;
    return 1; // ���ӳɹ�
}

// ��ȡ��ͷԪ��
int GetHead(Queue *Q, ElemType *v) {
    if (Q->front == Q->rear) {
        // ����Ϊ�գ���ȡʧ��
        return 0;
    }
    *v = Q->base[Q->front];
    return 1; // ��ȡ�ɹ�
}

// ��ȡ����Ԫ�ظ���
int Length(Queue *Q) {
    return (Q->rear - Q->front);
}

// ��ն���
void ClearQueue(Queue *Q) {
    Q->front = Q->rear = 0;
}

// ���ٶ���
void DestroyQueue(Queue *Q) {
    free(Q->base);
    Q->base = NULL;
    Q->front = Q->rear = 0;
}

int main() {
    Queue q;
    InitQueue(&q); // ��ʼ������

    EnQueue(&q, 10); // �����
    EnQueue(&q, 20);
    EnQueue(&q, 30);

    printf("�����е�Ԫ��: ");
    ShowQueue(&q);

    int head;
    if (GetHead(&q, &head)) {
        printf("��ͷԪ��: %d\n", head);
    } else {
        printf("����Ϊ��\n");
    }

    DeQueue(&q); // ������

    printf("�����е�Ԫ��: ");
    ShowQueue(&q);

    ClearQueue(&q); // ��ն���

    if (GetHead(&q, &head)) {
        printf("��ͷԪ��: %d\n", head);
    } else {
        printf("����Ϊ��\n");
    }

    DestroyQueue(&q); // ���ٶ���

    return 0;
}

