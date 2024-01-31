#include <stdio.h>
#include <stdbool.h>

#define MaxSize  10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

bool ListInsert(SqList* L, int pos, int elem) {
    if (pos < 1 || pos > L->length + 1) {
        return false; // 插入位置不合法
    }
    if (L->length >= MaxSize) {
        return false; // 线性表已满
    }

    // 将插入位置及后面的元素依次后移
    for (int i = L->length - 1; i >= pos - 1; i--) {
        L->data[i + 1] = L->data[i];
    }
    L->data[pos - 1] = elem; // 在插入位置放入新元素
    L->length++; // 线性表长度增加

    return true;
}

bool ListDelete(SqList* L, int pos, int* elem) {
    if (pos < 1 || pos > L->length) {
        return false; // 删除位置不合法
    }

    *elem = L->data[pos - 1]; // 保存被删除的元素

    // 将删除位置后面的元素依次前移
    for (int i = pos; i < L->length; i++) {
        L->data[i - 1] = L->data[i];
    }
    L->length--; // 线性表长度减少

    return true;
}

int ListSearch(SqList L, int elem) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == elem) {
            return i + 1; // 返回元素在线性表中的位置
        }
    }
    return -1; // 元素未找到
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList list = { {1, 2, 3, 4, 5}, 5 };
    int choice, pos, elem;

    printf("原始线性表：");
    PrintList(list);

    printf("请选择操作：\n");
    printf("1. 插入元素\n");
    printf("2. 删除元素\n");
    printf("3. 查找元素\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("请输入要插入的位置（1-%d）：", list.length + 1);
            scanf("%d", &pos);
            printf("请输入要插入的元素：");
            scanf("%d", &elem);

            if (ListInsert(&list, pos, elem)) {
                printf("插入成功！插入后的线性表：");
                PrintList(list);
            } else {
                printf("插入失败！\n");
            }
            break;

        case 2:
            printf("请输入要删除的位置（1-%d）：", list.length);
            scanf("%d", &pos);

            if (ListDelete(&list, pos, &elem)) {
                printf("删除成功！被删除的元素是：%d\n", elem);
                printf("删除后的线性表：");
                PrintList(list);
            } else {
                printf("删除失败！\n");
            }
            break;

        case 3:
            printf("请输入要查找的元素：");
            scanf("%d", &elem);

            int searchResult = ListSearch(list, elem);
            if (searchResult != -1) {
                printf("元素 %d 在线性表中的位置是：%d\n", elem, searchResult);
            } else {
                printf("元素 %d 未找到！\n", elem);
            }
            break;

    }

    return 0;
}

