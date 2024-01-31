#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int uset[MAXSIZE]; // ��¼Ԫ�������ļ��ϴ���
int rank[MAXSIZE]; // ��¼���ϵ��ȣ������Ż��ϲ�

// ��ʼ�����鼯��ÿ��Ԫ�س�ʼΪ�����ļ���
void makeSet(int size) {
    for (int i = 1; i <= size; i++) {
        uset[i] = i;     // ��ʼʱÿ��Ԫ�صĴ������Լ�
        rank[i] = 0;     // ��ʼʱÿ�����ϵ���Ϊ0
    }
}

// ����Ԫ�������ļ��ϴ���������·��ѹ��
int find(int i) {
    if (i == uset[i]) {
        return i; // ���Ԫ�صĴ������Լ���˵���ҵ��˸��ڵ㣬���ظ��ڵ�
    }
    // ·��ѹ������·���ϵĽڵ�ֱ�����ӵ����ڵ㣬�������ĸ߶�
    return uset[i] = find(uset[i]); // ·��ѹ���Ż�
}

// �ϲ��������ϣ��������ĸ߶Ƚ����Ż�
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) {
        return; // �������Ԫ���Ѿ���ͬһ���ϣ�����ϲ�
    }
    // ���Ⱥϲ��Ż�������С�ȵ������ӵ��ϴ��ȵ�������
    if (rank[rootX] < rank[rootY]) {
        uset[rootX] = rootY; // ��rootX���ڼ������ӵ�rootY���ڼ���
    } else {
        uset[rootY] = rootX; // ��rootY���ڼ������ӵ�rootX���ڼ���
        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++; // ����������ϵ�����ȣ����Ӻ��ȼ�һ
        }
    }
}

int main() {
    int size = 10; // ������Ҫ�Ĵ�С
    makeSet(size);

    // ʾ��ʹ��
    unite(1, 2);
    unite(3, 4);
    unite(5, 6);
    unite(1, 3);

    printf("Find(2) = %d\n", find(2));
    printf("Find(4) = %d\n", find(4));
    printf("Find(6) = %d\n", find(6));

    return 0;
}

