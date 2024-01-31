#include <stdio.h>
#include <stdbool.h>

#define MaxSize 100

typedef struct SqStack {
    int data[MaxSize]; // 存放栈中的元素
    int top; // 栈顶指针
} SqStack;

void InitStack(SqStack* S) {
    S->top = -1; // 初始化栈顶指针为-1，表示栈为空
}

bool Empty(SqStack S) {
    return S.top == -1; // 如果栈顶指针为-1，表示栈为空，返回true；否则返回false
}

void Push(SqStack* S, int x) {
    if (S->top == MaxSize - 1) { // 如果栈顶指针已经达到最大值，表示栈已满
        printf("栈满\n"); // 输出栈满的提示信息
        return; // 返回，不执行入栈操作
    }
    S->data[++S->top] = x; // 栈顶指针加1，并将元素x放入栈顶位置
}

void Pop(SqStack* S, int* x) {
    if (S->top == -1) { // 如果栈顶指针为-1，表示栈为空
        printf("栈空\n"); // 输出栈空的提示信息
        return; // 返回，不执行出栈操作
    }
    *x = S->data[S->top--]; // 将栈顶元素赋值给x，并将栈顶指针减1，实现出栈操作
} 

int GetTop(SqStack S) {
    if (S.top == -1) { // 如果栈顶指针为-1，表示栈为空
        printf("栈空\n"); // 输出栈空的提示信息
        return -1; // 返回-1，表示栈为空
    }
    return S.data[S.top]; // 返回栈顶元素的值
}

void PrintStack(SqStack S) {
    while (S.top != -1) { // 当栈不为空时
        printf("%d ", S.data[S.top--]); // 输出栈顶元素，并将栈顶指针减1，实现遍历栈
    }
    printf("\n"); // 输出换行，使结果更清晰
}

void DestroyStack(SqStack* S) {
    S->top = -1; // 将栈顶指针置为-1，表示栈已销毁
}

int main() {
    SqStack S; // 声明一个SqStack类型的变量S，表示栈
    InitStack(&S); // 初始化栈S
    Push(&S, 1); // 入栈操作，将元素1放入栈中
    Push(&S, 2); // 入栈操作，将元素2放入栈中
    Push(&S, 3); // 入栈操作，将元素3放入栈中
    Push(&S, 4); // 入栈操作，将元素4放入栈中
    printf("栈顶元素为：%d\n", GetTop(S)); // 输出栈顶元素的值
    printf("出栈顺序为：");
    PrintStack(S); // 遍历并输出栈中的元素
    int x;
    Pop(&S, &x); // 出栈操作，将栈顶元素弹出，并将其值赋给x
    printf("%d出栈\n", x); // 输出被弹出的元素的值
    printf("栈中剩余元素：");
    PrintStack(S); // 遍历并输出栈中的剩余元素
    Pop(&S, &x); // 出栈操作，将栈顶元素弹出，并将其值赋给x
    printf("%d出栈\n", x); // 输出被弹出的元素的值
    printf("栈中剩余元素：");
    PrintStack(S); // 遍历并输出栈中的剩余元素
    if (!Empty(S)) { // 判断栈是否为空
        printf("当前栈不为空\n"); // 输出栈不为空的提示信息
    } else {
        printf("当前栈为空\n"); // 输出栈为空的提示信息
    }
    return 0;
}

