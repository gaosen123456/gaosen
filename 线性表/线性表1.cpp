#include <stdio.h>
#include <stdbool.h>

#define MaxSize 100
typedef int ElemType;

// ����˳���ṹ
typedef struct {
    ElemType data[MaxSize]; // �洢Ԫ�ص�����
    int length;             // ˳���ǰ����
} SqList;

// ��˳����еĵ�i��λ�ò���Ԫ��e
bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) {
        return false; // ����λ�÷Ƿ�
    }
    if (L.length >= MaxSize) {
        return false; // ˳�������
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1]; // ����Ԫ��
    }
    L.data[i - 1] = e; // ����Ԫ��
    L.length++; // ���ȼ�1
    return true; // ����ɹ�
}

// ɾ��˳����еĵ�i��λ�õ�Ԫ�أ�������ɾ��Ԫ�ر�����e��
bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) {
        return false; // ɾ��λ�÷Ƿ�
    }
    e = L.data[i - 1]; // ���汻ɾ��Ԫ��
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j]; // ǰ��Ԫ��
    }
    L.length--; // ���ȼ�1
    return true; // ɾ���ɹ�
}

// ��˳����в���Ԫ��e��������λ��
int LocateElem(SqList L, ElemType e) {
    int i=1;
    for (i = 0; i < L.length; i++) {
        if (e == L.data[i]) {
            return i + 1; // �ҵ�Ԫ�أ�����λ�ã���1��ʼ��
        }
    }
    return 0; // δ�ҵ�Ԫ�أ�����0
}

// ��ӡ˳���Ԫ��
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList list = { {1, 2, 3, 4, 5}, 5 }; // ��ʼ��˳���
    int i;
    ElemType e;
    printf("���Ա�Ϊ��\n");
    PrintList(list);

    printf("����λ�ã�\n");
    scanf("%d", &i); // �������λ��
    printf("����Ԫ�أ�\n");
    scanf("%d", &e); // �������Ԫ��
    if (ListInsert(list, i, e)) {
        printf("����ɹ�\n");
        PrintList(list);
    } else {
        printf("ʧ��\n");
    }
    
    printf("ɾ��λ�ã�\n");
    scanf("%d", &i); // ����ɾ��λ��
    if (ListDelete(list, i, e)) {
        printf("ɾ���ɹ�\n");
        PrintList(list);
    } else {
        printf("ʧ��\n");
    }
    
    printf("��ѯԪ�أ�\n");
    scanf("%d", &e); // ����Ҫ��ѯ��Ԫ��
    int t = LocateElem(list, e);
    if (t != 0) {
        printf("��ѯ�ɹ�\n");
        printf("%d ��λ���� %d\n", e, t); 
    } else {
        printf("��\n");
    }
    return 0;
}

