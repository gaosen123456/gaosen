#include <stdio.h>
#include <stdbool.h>

#define MaxSize  10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

bool ListDelete(SqList* L, int pos, int* elem) {
    if (pos < 1 || pos > L->length) {
        return false; // 删除位置不合法
    }

    *elem = L->data[pos - 1]; // 保存被删除元素的值

    // 将删除位置后面的元素依次前移
    for (int i = pos; i < L->length; i++) {
        L->data[i - 1] = L->data[i];
    }
    L->length--; // 线性表长度减少

    return true;
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList list = { {1, 2, 3, 4, 5}, 5 };
    int pos, elem;

    printf("原始线性表：");
    PrintList(list);

    printf("请输入要删除的位置（1-%d）：", list.length);
    scanf("%d", &pos);

    if (ListDelete(&list, pos, &elem)) {
        printf("删除成功！被删除的元素为%d\n", elem);
        printf("删除后的线性表：");
        PrintList(list);
    } else {
        printf("删除失败！\n");
    }

    return 0;
}
