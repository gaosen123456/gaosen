#include <stdio.h>
#include <stdbool.h>

#define MaxSize 100

typedef struct SqStack {
    int data[MaxSize]; // ���ջ�е�Ԫ��
    int top; // ջ��ָ��
} SqStack;

void InitStack(SqStack* S) {
    S->top = -1; // ��ʼ��ջ��ָ��Ϊ-1����ʾջΪ��
}

bool Empty(SqStack S) {
    return S.top == -1; // ���ջ��ָ��Ϊ-1����ʾջΪ�գ�����true�����򷵻�false
}

void Push(SqStack* S, int x) {
    if (S->top == MaxSize - 1) { // ���ջ��ָ���Ѿ��ﵽ���ֵ����ʾջ����
        printf("ջ��\n"); // ���ջ������ʾ��Ϣ
        return; // ���أ���ִ����ջ����
    }
    S->data[++S->top] = x; // ջ��ָ���1������Ԫ��x����ջ��λ��
}

void Pop(SqStack* S, int* x) {
    if (S->top == -1) { // ���ջ��ָ��Ϊ-1����ʾջΪ��
        printf("ջ��\n"); // ���ջ�յ���ʾ��Ϣ
        return; // ���أ���ִ�г�ջ����
    }
    *x = S->data[S->top--]; // ��ջ��Ԫ�ظ�ֵ��x������ջ��ָ���1��ʵ�ֳ�ջ����
} 

int GetTop(SqStack S) {
    if (S.top == -1) { // ���ջ��ָ��Ϊ-1����ʾջΪ��
        printf("ջ��\n"); // ���ջ�յ���ʾ��Ϣ
        return -1; // ����-1����ʾջΪ��
    }
    return S.data[S.top]; // ����ջ��Ԫ�ص�ֵ
}

void PrintStack(SqStack S) {
    while (S.top != -1) { // ��ջ��Ϊ��ʱ
        printf("%d ", S.data[S.top--]); // ���ջ��Ԫ�أ�����ջ��ָ���1��ʵ�ֱ���ջ
    }
    printf("\n"); // ������У�ʹ���������
}

void DestroyStack(SqStack* S) {
    S->top = -1; // ��ջ��ָ����Ϊ-1����ʾջ������
}

int main() {
    SqStack S; // ����һ��SqStack���͵ı���S����ʾջ
    InitStack(&S); // ��ʼ��ջS
    Push(&S, 1); // ��ջ��������Ԫ��1����ջ��
    Push(&S, 2); // ��ջ��������Ԫ��2����ջ��
    Push(&S, 3); // ��ջ��������Ԫ��3����ջ��
    Push(&S, 4); // ��ջ��������Ԫ��4����ջ��
    printf("ջ��Ԫ��Ϊ��%d\n", GetTop(S)); // ���ջ��Ԫ�ص�ֵ
    printf("��ջ˳��Ϊ��");
    PrintStack(S); // ���������ջ�е�Ԫ��
    int x;
    Pop(&S, &x); // ��ջ��������ջ��Ԫ�ص�����������ֵ����x
    printf("%d��ջ\n", x); // �����������Ԫ�ص�ֵ
    printf("ջ��ʣ��Ԫ�أ�");
    PrintStack(S); // ���������ջ�е�ʣ��Ԫ��
    Pop(&S, &x); // ��ջ��������ջ��Ԫ�ص�����������ֵ����x
    printf("%d��ջ\n", x); // �����������Ԫ�ص�ֵ
    printf("ջ��ʣ��Ԫ�أ�");
    PrintStack(S); // ���������ջ�е�ʣ��Ԫ��
    if (!Empty(S)) { // �ж�ջ�Ƿ�Ϊ��
        printf("��ǰջ��Ϊ��\n"); // ���ջ��Ϊ�յ���ʾ��Ϣ
    } else {
        printf("��ǰջΪ��\n"); // ���ջΪ�յ���ʾ��Ϣ
    }
    return 0;
}

