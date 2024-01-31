#include <stdio.h>
#include <stdbool.h>

#define MaxSize 100
typedef int ElemType;

// 定义顺序表结构
typedef struct {
    ElemType data[MaxSize]; // 存储元素的数组
    int length;             // 顺序表当前长度
} SqList;

// 在顺序表中的第i个位置插入元素e
bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) {
        return false; // 插入位置非法
    }
    if (L.length >= MaxSize) {
        return false; // 顺序表已满
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1]; // 后移元素
    }
    L.data[i - 1] = e; // 插入元素
    L.length++; // 长度加1
    return true; // 插入成功
}

// 删除顺序表中的第i个位置的元素，并将被删除元素保存在e中
bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) {
        return false; // 删除位置非法
    }
    e = L.data[i - 1]; // 保存被删除元素
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j]; // 前移元素
    }
    L.length--; // 长度减1
    return true; // 删除成功
}

// 在顺序表中查找元素e，返回其位置
int LocateElem(SqList L, ElemType e) {
    int i=1;
    for (i = 0; i < L.length; i++) {
        if (e == L.data[i]) {
            return i + 1; // 找到元素，返回位置（从1开始）
        }
    }
    return 0; // 未找到元素，返回0
}

// 打印顺序表元素
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList list = { {1, 2, 3, 4, 5}, 5 }; // 初始化顺序表
    int i;
    ElemType e;
    printf("线性表为：\n");
    PrintList(list);

    printf("插入位置：\n");
    scanf("%d", &i); // 输入插入位置
    printf("插入元素：\n");
    scanf("%d", &e); // 输入插入元素
    if (ListInsert(list, i, e)) {
        printf("插入成功\n");
        PrintList(list);
    } else {
        printf("失败\n");
    }
    
    printf("删除位置：\n");
    scanf("%d", &i); // 输入删除位置
    if (ListDelete(list, i, e)) {
        printf("删除成功\n");
        PrintList(list);
    } else {
        printf("失败\n");
    }
    
    printf("查询元素：\n");
    scanf("%d", &e); // 输入要查询的元素
    int t = LocateElem(list, e);
    if (t != 0) {
        printf("查询成功\n");
        printf("%d 的位置是 %d\n", e, t); 
    } else {
        printf("无\n");
    }
    return 0;
}

