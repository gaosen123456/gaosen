#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int top;
} SeqStack;

SeqStack* Init_SeqStack() {  // ջ��ʼ��
    SeqStack* s;
    s = (SeqStack*) malloc(sizeof(SeqStack));
    if (!s) {
        printf("�ռ䲻��\n");
        return NULL;
    } else {
        s->top = -1;
        return s;
    }
}

int Empty_SeqStack(SeqStack* s) {  // ��ջ��
    if (s->top == -1)
        return true;
    else
        return false;
}

int Push_SeqStack(SeqStack* s, int x) {  // ��ջ
    if (s->top == MAXSIZE - 1) {
        printf("ջ�����޷���ջ\n");
        return -1;
    } else {
        s->top++;
        s->data[s->top] = x;
        return 0;
    }
}

int Pop_SeqStack(SeqStack* s, int* x) {  // ��ջ
    if (Empty_SeqStack(s)) {
        printf("ջΪ�գ��޷���ջ\n");
        return -1;
    } else {
        *x = s->data[s->top];
        s->top--;
        return 0;
    }
}

int Top_SeqStack(SeqStack* s) {
    if (Empty_SeqStack(s)) {
        printf("ջΪ�գ���ջ��Ԫ��\n");
        return -1;
    } else {
        return s->data[s->top];
    }
}

int Print_SeqStack(SeqStack* s) {
    int i;
    printf("��ǰջ�е�Ԫ��:\n");
    for (i = s->top; i >= 0; i--)
        printf("%3d", s->data[i]);
    printf("\n");
    return 0;
}

int main() {
    SeqStack* L;
    int n, num, m;
    int i;

    L = Init_SeqStack();

    printf("��ʼ�����\n");
    printf("ջ�գ�%d\n", Empty_SeqStack(L));
    printf("��������ջԪ�ظ�����\n");
    scanf("%d", &n);
    printf("������Ҫ��ջ��%d��Ԫ�أ�\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        Push_SeqStack(L, num);
    }

    Print_SeqStack(L);

    printf("ջ��Ԫ�أ�%d\n", Top_SeqStack(L));
    printf("������Ҫ��ջ��Ԫ�ظ��������ܳ���%d������\n", n);
    scanf("%d", &n);
    printf("���γ�ջ��%d��Ԫ�أ�\n", n);

    for (i = 0; i < n; i++) {
        Pop_SeqStack(L, &m);
        printf("%3d", m);
    }

    printf("\n");

    Print_SeqStack(L);
    printf("ջ��Ԫ�أ�%d\n", Top_SeqStack(L));

    return 0;
}
