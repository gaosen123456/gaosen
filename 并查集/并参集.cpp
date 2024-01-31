#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int uset[MAXSIZE]; // 记录元素所属的集合代表
int rank[MAXSIZE]; // 记录集合的秩，用于优化合并

// 初始化并查集，每个元素初始为独立的集合
void makeSet(int size) {
    for (int i = 1; i <= size; i++) {
        uset[i] = i;     // 初始时每个元素的代表是自己
        rank[i] = 0;     // 初始时每个集合的秩为0
    }
}

// 查找元素所属的集合代表，并进行路径压缩
int find(int i) {
    if (i == uset[i]) {
        return i; // 如果元素的代表是自己，说明找到了根节点，返回根节点
    }
    // 路径压缩：将路径上的节点直接连接到根节点，降低树的高度
    return uset[i] = find(uset[i]); // 路径压缩优化
}

// 合并两个集合，根据树的高度进行优化
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) {
        return; // 如果两个元素已经在同一集合，无需合并
    }
    // 按秩合并优化：将较小秩的树连接到较大秩的树下面
    if (rank[rootX] < rank[rootY]) {
        uset[rootX] = rootY; // 将rootX所在集合连接到rootY所在集合
    } else {
        uset[rootY] = rootX; // 将rootY所在集合连接到rootX所在集合
        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++; // 如果两个集合的秩相等，连接后秩加一
        }
    }
}

int main() {
    int size = 10; // 调整需要的大小
    makeSet(size);

    // 示例使用
    unite(1, 2);
    unite(3, 4);
    unite(5, 6);
    unite(1, 3);

    printf("Find(2) = %d\n", find(2));
    printf("Find(4) = %d\n", find(4));
    printf("Find(6) = %d\n", find(6));

    return 0;
}

