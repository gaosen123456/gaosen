#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStack;

void InitStack(LinkedStack* S) {
    S->top = NULL;
}

bool Empty(LinkedStack S) {
    return S.top == NULL;
}

void Push(LinkedStack* S, int x) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1);
    }
    newNode->data = x;
    newNode->next = S->top;
    S->top = newNode;
}

bool Pop(LinkedStack* S, int* x) {
    if (S->top == NULL) {
        printf("ջ��\n");
        return false;
    }
    StackNode* temp = S->top;
    *x = temp->data;
    S->top = temp->next;
    free(temp);
    return true;
}

int GetTop(LinkedStack S) {
    if (S.top == NULL) {
        printf("ջ��\n");
        return -1;
    }
    return S.top->data;
}

void PrintStack(LinkedStack S) {
    StackNode* current = S.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void DestroyStack(LinkedStack* S) {
    while (S->top != NULL) {
        StackNode* temp = S->top;
        S->top = temp->next;
        free(temp);
    }
}

int main() {
    LinkedStack S;
    InitStack(&S);
    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);
    Push(&S, 4);
    printf("ջ��Ԫ��Ϊ��%d\n", GetTop(S));
    printf("��ջ˳��Ϊ��");
    PrintStack(S);
    int x;
    if (Pop(&S, &x)) {
        printf("%d��ջ\n", x);
    }
    printf("ջ��ʣ��Ԫ�أ�");
    PrintStack(S);
    if (!Empty(S)) {
        printf("��ǰջ��Ϊ��\n");
    } else {
        printf("��ǰջΪ��\n");
    }
    DestroyStack(&S);
    return 0;
}
