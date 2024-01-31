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
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = x;
    newNode->next = S->top;
    S->top = newNode;
}

bool Pop(LinkedStack* S, int* x) {
    if (S->top == NULL) {
        printf("栈空\n");
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
        printf("栈空\n");
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
    printf("栈顶元素为：%d\n", GetTop(S));
    printf("出栈顺序为：");
    PrintStack(S);
    int x;
    if (Pop(&S, &x)) {
        printf("%d出栈\n", x);
    }
    printf("栈中剩余元素：");
    PrintStack(S);
    if (!Empty(S)) {
        printf("当前栈不为空\n");
    } else {
        printf("当前栈为空\n");
    }
    DestroyStack(&S);
    return 0;
}
