#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int length;
    int maxSize;
} SqList;

bool InitList(SqList* L, int maxSize) {
    L->data = (int*)malloc(maxSize * sizeof(int));
    if (L->data == NULL) {
        return false; // �ڴ����ʧ��
    }
    L->length = 0;
    L->maxSize = maxSize;
    return true;
}

bool ListInsert(SqList* L, int pos, int elem) {
    if (pos < 1 || pos > L->length + 1) {
        return false; // ����λ�ò��Ϸ�
    }
    if (L->length >= L->maxSize) {
        return false; // ���Ա�����
    }

    for (int i = L->length - 1; i >= pos - 1; i--) {
        L->data[i + 1] = L->data[i];
    }
    L->data[pos - 1] = elem;
    L->length++;

    return true;
}

bool ListDelete(SqList* L, int pos, int* elem) {
    if (pos < 1 || pos > L->length) {
        return false; // ɾ��λ�ò��Ϸ�
    }

    *elem = L->data[pos - 1];
    for (int i = pos; i < L->length; i++) {
        L->data[i - 1] = L->data[i];
    }
    L->length--;

    return true;
}

int ListSearch(SqList L, int elem) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == elem) {
            return i + 1;
        }
    }
    return -1;
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    int maxSize = 10;
    SqList list;
    
    if (!InitList(&list, maxSize)) {
        printf("�ڴ����ʧ�ܣ�\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        list.data[i] = i + 1;
        list.length++;
    }

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

    free(list.data);

    return 0;
}

