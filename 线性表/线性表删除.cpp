#include <stdio.h>
#include <stdbool.h>

#define MaxSize  10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

bool ListDelete(SqList* L, int pos, int* elem) {
    if (pos < 1 || pos > L->length) {
        return false; // ɾ��λ�ò��Ϸ�
    }

    *elem = L->data[pos - 1]; // ���汻ɾ��Ԫ�ص�ֵ

    // ��ɾ��λ�ú����Ԫ������ǰ��
    for (int i = pos; i < L->length; i++) {
        L->data[i - 1] = L->data[i];
    }
    L->length--; // ���Ա��ȼ���

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

    printf("ԭʼ���Ա�");
    PrintList(list);

    printf("������Ҫɾ����λ�ã�1-%d����", list.length);
    scanf("%d", &pos);

    if (ListDelete(&list, pos, &elem)) {
        printf("ɾ���ɹ�����ɾ����Ԫ��Ϊ%d\n", elem);
        printf("ɾ��������Ա�");
        PrintList(list);
    } else {
        printf("ɾ��ʧ�ܣ�\n");
    }

    return 0;
}
