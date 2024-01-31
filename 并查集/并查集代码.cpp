#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 并查集结构
typedef struct {
    int parent[MAX_SIZE];  // 存储父节点
    int rank[MAX_SIZE];    // 存储秩（树的深度）
} DisjointSet;

// 初始化并查集
void init(DisjointSet* ds, int n) {
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;  // 初始时每个元素的父节点是自己
        ds->rank[i] = 0;    // 初始时每个元素的秩为0
    }
}

// 查找根节点
int find(DisjointSet* ds, int x) {
    if (ds->parent[x] != x) {
        ds->parent[x] = find(ds, ds->parent[x]);  // 路径压缩，将x的父节点设为根节点
    }
    return ds->parent[x];
}

// 合并两个集合
void unionSet(DisjointSet* ds, int x, int y) {
    int rootX = find(ds, x);  // 查找x的根节点
    int rootY = find(ds, y);  // 查找y的根节点

    if (rootX == rootY) {
        return;  // x和y已经在同一个集合中
    }

    if (ds->rank[rootX] < ds->rank[rootY]) {
        ds->parent[rootX] = rootY;  // 将rootX设为rootY的子节点
    } else if (ds->rank[rootX] > ds->rank[rootY]) {
        ds->parent[rootY] = rootX;  // 将rootY设为rootX的子节点
    } else {
        ds->parent[rootY] = rootX;  // 将rootY设为rootX的子节点
        ds->rank[rootX]++;          // rootX的秩增加1
    }
}

int main() {
    int n = 5;  // 元素个数
    DisjointSet ds;
  
    init(&ds, n);  // 初始化并查集
  
    // 进行一些操作示例，合并元素1和元素2，合并元素3和元素4
    unionSet(&ds, 1, 2);
    unionSet(&ds, 3, 4);
  
    // 判断元素1和元素3是否属于同一集合
    if (find(&ds, 1) == find(&ds, 3)) {
        printf("元素1和元素3属于同一集合");
    } else {
        printf("元素1和元素3不属于同一集合");
    }
  
    return 0;
}
