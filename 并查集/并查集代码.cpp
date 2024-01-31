#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// ���鼯�ṹ
typedef struct {
    int parent[MAX_SIZE];  // �洢���ڵ�
    int rank[MAX_SIZE];    // �洢�ȣ�������ȣ�
} DisjointSet;

// ��ʼ�����鼯
void init(DisjointSet* ds, int n) {
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;  // ��ʼʱÿ��Ԫ�صĸ��ڵ����Լ�
        ds->rank[i] = 0;    // ��ʼʱÿ��Ԫ�ص���Ϊ0
    }
}

// ���Ҹ��ڵ�
int find(DisjointSet* ds, int x) {
    if (ds->parent[x] != x) {
        ds->parent[x] = find(ds, ds->parent[x]);  // ·��ѹ������x�ĸ��ڵ���Ϊ���ڵ�
    }
    return ds->parent[x];
}

// �ϲ���������
void unionSet(DisjointSet* ds, int x, int y) {
    int rootX = find(ds, x);  // ����x�ĸ��ڵ�
    int rootY = find(ds, y);  // ����y�ĸ��ڵ�

    if (rootX == rootY) {
        return;  // x��y�Ѿ���ͬһ��������
    }

    if (ds->rank[rootX] < ds->rank[rootY]) {
        ds->parent[rootX] = rootY;  // ��rootX��ΪrootY���ӽڵ�
    } else if (ds->rank[rootX] > ds->rank[rootY]) {
        ds->parent[rootY] = rootX;  // ��rootY��ΪrootX���ӽڵ�
    } else {
        ds->parent[rootY] = rootX;  // ��rootY��ΪrootX���ӽڵ�
        ds->rank[rootX]++;          // rootX��������1
    }
}

int main() {
    int n = 5;  // Ԫ�ظ���
    DisjointSet ds;
  
    init(&ds, n);  // ��ʼ�����鼯
  
    // ����һЩ����ʾ�����ϲ�Ԫ��1��Ԫ��2���ϲ�Ԫ��3��Ԫ��4
    unionSet(&ds, 1, 2);
    unionSet(&ds, 3, 4);
  
    // �ж�Ԫ��1��Ԫ��3�Ƿ�����ͬһ����
    if (find(&ds, 1) == find(&ds, 3)) {
        printf("Ԫ��1��Ԫ��3����ͬһ����");
    } else {
        printf("Ԫ��1��Ԫ��3������ͬһ����");
    }
  
    return 0;
}
