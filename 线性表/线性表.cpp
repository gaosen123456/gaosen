#include <stdio.h>
#include <stdbool.h>

#define MaxSize  10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

bool ListInsert(SqList* L, int pos, int elem) {
    if (pos < 1 || pos > L->length + 1) {
        return false; // ����λ�ò��Ϸ�
    }
    if (L->length >= MaxSize) {
        return false; // ���Ա�����
    }

    // ������λ�ü������Ԫ�����κ���
    for (int i = L->length - 1; i >= pos - 1; i--) {
        L->data[i + 1] = L->data[i];
    }
    L->data[pos - 1] = elem; // �ڲ���λ�÷�����Ԫ��
    L->length++; // ���Ա�������

    return true;
}

bool ListDelete(SqList* L, int pos, int* elem) {
    if (pos < 1 || pos > L->length) {
        return false; // ɾ��λ�ò��Ϸ�
    }

    *elem = L->data[pos - 1]; // ���汻ɾ����Ԫ��

    // ��ɾ��λ�ú����Ԫ������ǰ��
    for (int i = pos; i < L->length; i++) {
        L->data[i - 1] = L->data[i];
    }
    L->length--; // ���Ա��ȼ���

    return true;
}

int ListSearch(SqList L, int elem) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == elem) {
            return i + 1; // ����Ԫ�������Ա��е�λ��
        }
    }
    return -1; // Ԫ��δ�ҵ�
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

    printf("ԭʼ���Ա�");
    PrintList(list);

    printf("��ѡ�������\n");
    printf("1. ����Ԫ��\n");
    printf("2. ɾ��Ԫ��\n");
    printf("3. ����Ԫ��\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("������Ҫ�����λ�ã�1-%d����", list.length + 1);
            scanf("%d", &pos);
            printf("������Ҫ�����Ԫ�أ�");
            scanf("%d", &elem);

            if (ListInsert(&list, pos, elem)) {
                printf("����ɹ������������Ա�");
                PrintList(list);
            } else {
                printf("����ʧ�ܣ�\n");
            }
            break;

        case 2:
            printf("������Ҫɾ����λ�ã�1-%d����", list.length);
            scanf("%d", &pos);

            if (ListDelete(&list, pos, &elem)) {
                printf("ɾ���ɹ�����ɾ����Ԫ���ǣ�%d\n", elem);
                printf("ɾ��������Ա�");
                PrintList(list);
            } else {
                printf("ɾ��ʧ�ܣ�\n");
            }
            break;

        case 3:
            printf("������Ҫ���ҵ�Ԫ�أ�");
            scanf("%d", &elem);

            int searchResult = ListSearch(list, elem);
            if (searchResult != -1) {
                printf("Ԫ�� %d �����Ա��е�λ���ǣ�%d\n", elem, searchResult);
            } else {
                printf("Ԫ�� %d δ�ҵ���\n", elem);
            }
            break;

    }

    return 0;
}

