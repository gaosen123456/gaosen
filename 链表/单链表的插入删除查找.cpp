#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;  // 定义链表元素的类型

typedef struct Node {
    ElemType data;  // 数据域，存储元素的值
    struct Node* next;  // 指针域，指向下一个节点
} Node, *LinkedList;  // 定义节点和链表的类型

// 显示菜单选项
void menu() {
    printf("*****1.单链表的插入*****\n");  // 单链表的插入
    printf("*****2.单链表的删除*****\n");  // 单链表的删除
    printf("*****3.单链表的查找*****\n");  // 单链表的查找
    printf("*****0.     退出   *****\n");  // 退出
}

// 初始化链表，创建头节点
LinkedList LinkListInit() {
    LinkedList L;
    L = (LinkedList)malloc(sizeof(Node));  // 为头节点分配内存空间
    if (L == NULL) {
        printf("申请内存空间失败\n");
        exit(1);
    }
    L->next = NULL;  // 头节点的指针域指向NULL
    return L;
}

// 头插法创建链表
LinkedList ListCreatH() {
    LinkedList L;
    L = (LinkedList)malloc(sizeof(Node));  // 创建头节点
    L->next = NULL;  // 头节点的指针域指向NULL，初始化 
    int i = 0;
    ElemType x;
    while (i < 10) {
        Node* p = (Node*)malloc(sizeof(Node));  // 创建新节点
        scanf("%d", &x);  // 输入节点的值
        p->data = x;  // 将节点的值赋给数据域
        p->next = L->next;  // 将新节点的指针域指向原先的第一个节点
        L->next = p;  // 头节点的指针域指向新节点，完成插入操作
        i++;
    }
    return L;
}

// 尾插法创建链表
LinkedList ListCreatT() {
    LinkedList L;
    L = (LinkedList)malloc(sizeof(Node));  // 创建头节点
    L->next = NULL;  // 头节点的指针域指向NULL
    Node* r = L;  // r指向链表的尾节点
    int i = 0;
    for (i = 0; i < 10; i++) {
        Node* p = (Node*)malloc(sizeof(Node));  // 创建新节点
        scanf("%d", &p->data);  // 输入节点的值
        r->next = p;  // 将新节点插入到链表尾部
        r = p;  // 移动尾指针到新节点
    }
    r->next = NULL;  // 尾节点的指针域指向NULL
    return L;
}

// 在指定位置插入元素
LinkedList ListInsert(LinkedList L, int i, ElemType x) {
    LinkedList pre = L;  // pre指向要插入位置的前一个节点
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++) {
        pre = pre->next;  // 找到插入位置的前一个节点
    }
    Node* p = (Node*)malloc(sizeof(Node));  // 创建新节点
    p->data = x;  // 将节点的值赋给数据域
    p->next = pre->next;  // 将新节点的指针域指向原先的第i个节点
    pre->next = p;  // 将前一个节点的指针域指向新节点，完成插入操作
    return L;
}

// 删除指定位置的元素
LinkedList ListDelete(LinkedList L, int i) {
    LinkedList p = L;  // p指向要删除节点的前一个节点
    int j = 1;
    while (p->next && j < i) {
        p = p->next;  // 找到要删除节点的前一个节点
        ++j;
    }
    if (!(p->next) || j > i) {
        printf("第i个元素不存在\n");
        return L;
    }
    LinkedList q = p->next;  // q指向要删除的节点
    p->next = q->next;  // 将前一个节点的指针域指向要删除节点的下一个节点，完成删除操作
    free(q);  // 释放要删除的节点的内存空间
    return L;
}

// 查找指定元素的位置
void FindElem(LinkedList L, ElemType x) {
    int index = 1;
    LinkedList p = L->next;  // p指向链表的第一个节点
    while (p != NULL) {
        if (p->data == x) {
            printf("元素 %d 的位置为 %d\n", x, index);
        }
        p = p->next;  // 移动到下一个节点
        index++;
    }
}

int main() {
    LinkedList list, start;
    printf("请输入单链表的数据：\n");
    list = ListCreatT();  // 创建链表
    printf("成功创建链表：\n");
    for (start = list->next; start != NULL; start = start->next) {
        printf("%d ", start->data);  // 遍历链表并打印节点的值
    }
    printf("\n");
    menu();
    int option;
    ElemType x;
    do {
        printf("请输入选项：");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int i;
                printf("请输入插入数据的位置：");
                scanf("%d", &i);
                printf("请输入插入数据的值：");
                scanf("%d", &x);
                list = ListInsert(list, i, x);  // 在指定位置插入元素
                printf("插入后的链表为：");
                for (start = list->next; start != NULL; start = start->next) {
                    printf("%d ", start->data);  // 遍历链表并打印节点的值
                }
                printf("\n");
                break;
            }
            case 2: {
                int i;
                printf("请输入删除的位置：");
                scanf("%d", &i);
                if (i == 1) {
                    list = ListDelete(list, i);  // 删除第一个节点
                } else {
                    list = ListDelete(list, i + 1);  // 删除指定位置的节点
                }
                printf("删除后的链表为：");
                for (start = list->next; start != NULL; start = start->next) {
                    printf("%d ", start->data);  // 遍历链表并打印节点的值
                }
                printf("\n");
                break;
            }
            case 3:
                printf("请输入要查找的元素：");
                scanf("%d", &x);
                FindElem(list, x);  // 查找指定元素的位置
                break;
            case 0:
                printf("退出程序\n");
                break;
            default:
                printf("请输入有效选项\n");
                break;
        }
    } while (option != 0);

    Node* p = list;
    Node* q;
    while (p != NULL) {
        q = p->next;
        free(p);  // 释放链表的节点内存空间
        p = q;
    }

    return 0;
}

