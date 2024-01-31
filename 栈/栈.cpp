#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int top;
} SeqStack;

SeqStack* Init_SeqStack() {  // 栈初始化
    SeqStack* s;
    s = (SeqStack*) malloc(sizeof(SeqStack));
    if (!s) {
        printf("空间不足\n");
        return NULL;
    } else {
        s->top = -1;
        return s;
    }
}

int Empty_SeqStack(SeqStack* s) {  // 判栈空
    if (s->top == -1)
        return true;
    else
        return false;
}

int Push_SeqStack(SeqStack* s, int x) {  // 入栈
    if (s->top == MAXSIZE - 1) {
        printf("栈满，无法入栈\n");
        return -1;
    } else {
        s->top++;
        s->data[s->top] = x;
        return 0;
    }
}

int Pop_SeqStack(SeqStack* s, int* x) {  // 出栈
    if (Empty_SeqStack(s)) {
        printf("栈为空，无法出栈\n");
        return -1;
    } else {
        *x = s->data[s->top];
        s->top--;
        return 0;
    }
}

int Top_SeqStack(SeqStack* s) {
    if (Empty_SeqStack(s)) {
        printf("栈为空，无栈顶元素\n");
        return -1;
    } else {
        return s->data[s->top];
    }
}

int Print_SeqStack(SeqStack* s) {
    int i;
    printf("当前栈中的元素:\n");
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

    printf("初始化完成\n");
    printf("栈空：%d\n", Empty_SeqStack(L));
    printf("请输入入栈元素个数：\n");
    scanf("%d", &n);
    printf("请输入要入栈的%d个元素：\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        Push_SeqStack(L, num);
    }

    Print_SeqStack(L);

    printf("栈顶元素：%d\n", Top_SeqStack(L));
    printf("请输入要出栈的元素个数（不能超过%d个）：\n", n);
    scanf("%d", &n);
    printf("依次出栈的%d个元素：\n", n);

    for (i = 0; i < n; i++) {
        Pop_SeqStack(L, &m);
        printf("%3d", m);
    }

    printf("\n");

    Print_SeqStack(L);
    printf("栈顶元素：%d\n", Top_SeqStack(L));

    return 0;
}
