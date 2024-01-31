#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;  // ��������Ԫ�ص�����

typedef struct Node {
    ElemType data;  // �����򣬴洢Ԫ�ص�ֵ
    struct Node* next;  // ָ����ָ����һ���ڵ�
} Node, *LinkedList;  // ����ڵ�����������

// ��ʾ�˵�ѡ��
void menu() {
    printf("*****1.������Ĳ���*****\n");  // ������Ĳ���
    printf("*****2.�������ɾ��*****\n");  // �������ɾ��
    printf("*****3.������Ĳ���*****\n");  // ������Ĳ���
    printf("*****0.     �˳�   *****\n");  // �˳�
}

// ��ʼ����������ͷ�ڵ�
LinkedList LinkListInit() {
    LinkedList L;
    L = (LinkedList)malloc(sizeof(Node));  // Ϊͷ�ڵ�����ڴ�ռ�
    if (L == NULL) {
        printf("�����ڴ�ռ�ʧ��\n");
        exit(1);
    }
    L->next = NULL;  // ͷ�ڵ��ָ����ָ��NULL
    return L;
}

// ͷ�巨��������
LinkedList ListCreatH() {
    LinkedList L;
    L = (LinkedList)malloc(sizeof(Node));  // ����ͷ�ڵ�
    L->next = NULL;  // ͷ�ڵ��ָ����ָ��NULL����ʼ�� 
    int i = 0;
    ElemType x;
    while (i < 10) {
        Node* p = (Node*)malloc(sizeof(Node));  // �����½ڵ�
        scanf("%d", &x);  // ����ڵ��ֵ
        p->data = x;  // ���ڵ��ֵ����������
        p->next = L->next;  // ���½ڵ��ָ����ָ��ԭ�ȵĵ�һ���ڵ�
        L->next = p;  // ͷ�ڵ��ָ����ָ���½ڵ㣬��ɲ������
        i++;
    }
    return L;
}

// β�巨��������
LinkedList ListCreatT() {
    LinkedList L;
    L = (LinkedList)malloc(sizeof(Node));  // ����ͷ�ڵ�
    L->next = NULL;  // ͷ�ڵ��ָ����ָ��NULL
    Node* r = L;  // rָ�������β�ڵ�
    int i = 0;
    for (i = 0; i < 10; i++) {
        Node* p = (Node*)malloc(sizeof(Node));  // �����½ڵ�
        scanf("%d", &p->data);  // ����ڵ��ֵ
        r->next = p;  // ���½ڵ���뵽����β��
        r = p;  // �ƶ�βָ�뵽�½ڵ�
    }
    r->next = NULL;  // β�ڵ��ָ����ָ��NULL
    return L;
}

// ��ָ��λ�ò���Ԫ��
LinkedList ListInsert(LinkedList L, int i, ElemType x) {
    LinkedList pre = L;  // preָ��Ҫ����λ�õ�ǰһ���ڵ�
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++) {
        pre = pre->next;  // �ҵ�����λ�õ�ǰһ���ڵ�
    }
    Node* p = (Node*)malloc(sizeof(Node));  // �����½ڵ�
    p->data = x;  // ���ڵ��ֵ����������
    p->next = pre->next;  // ���½ڵ��ָ����ָ��ԭ�ȵĵ�i���ڵ�
    pre->next = p;  // ��ǰһ���ڵ��ָ����ָ���½ڵ㣬��ɲ������
    return L;
}

// ɾ��ָ��λ�õ�Ԫ��
LinkedList ListDelete(LinkedList L, int i) {
    LinkedList p = L;  // pָ��Ҫɾ���ڵ��ǰһ���ڵ�
    int j = 1;
    while (p->next && j < i) {
        p = p->next;  // �ҵ�Ҫɾ���ڵ��ǰһ���ڵ�
        ++j;
    }
    if (!(p->next) || j > i) {
        printf("��i��Ԫ�ز�����\n");
        return L;
    }
    LinkedList q = p->next;  // qָ��Ҫɾ���Ľڵ�
    p->next = q->next;  // ��ǰһ���ڵ��ָ����ָ��Ҫɾ���ڵ����һ���ڵ㣬���ɾ������
    free(q);  // �ͷ�Ҫɾ���Ľڵ���ڴ�ռ�
    return L;
}

// ����ָ��Ԫ�ص�λ��
void FindElem(LinkedList L, ElemType x) {
    int index = 1;
    LinkedList p = L->next;  // pָ������ĵ�һ���ڵ�
    while (p != NULL) {
        if (p->data == x) {
            printf("Ԫ�� %d ��λ��Ϊ %d\n", x, index);
        }
        p = p->next;  // �ƶ�����һ���ڵ�
        index++;
    }
}

int main() {
    LinkedList list, start;
    printf("�����뵥��������ݣ�\n");
    list = ListCreatT();  // ��������
    printf("�ɹ���������\n");
    for (start = list->next; start != NULL; start = start->next) {
        printf("%d ", start->data);  // ����������ӡ�ڵ��ֵ
    }
    printf("\n");
    menu();
    int option;
    ElemType x;
    do {
        printf("������ѡ�");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int i;
                printf("������������ݵ�λ�ã�");
                scanf("%d", &i);
                printf("������������ݵ�ֵ��");
                scanf("%d", &x);
                list = ListInsert(list, i, x);  // ��ָ��λ�ò���Ԫ��
                printf("����������Ϊ��");
                for (start = list->next; start != NULL; start = start->next) {
                    printf("%d ", start->data);  // ����������ӡ�ڵ��ֵ
                }
                printf("\n");
                break;
            }
            case 2: {
                int i;
                printf("������ɾ����λ�ã�");
                scanf("%d", &i);
                if (i == 1) {
                    list = ListDelete(list, i);  // ɾ����һ���ڵ�
                } else {
                    list = ListDelete(list, i + 1);  // ɾ��ָ��λ�õĽڵ�
                }
                printf("ɾ���������Ϊ��");
                for (start = list->next; start != NULL; start = start->next) {
                    printf("%d ", start->data);  // ����������ӡ�ڵ��ֵ
                }
                printf("\n");
                break;
            }
            case 3:
                printf("������Ҫ���ҵ�Ԫ�أ�");
                scanf("%d", &x);
                FindElem(list, x);  // ����ָ��Ԫ�ص�λ��
                break;
            case 0:
                printf("�˳�����\n");
                break;
            default:
                printf("��������Чѡ��\n");
                break;
        }
    } while (option != 0);

    Node* p = list;
    Node* q;
    while (p != NULL) {
        q = p->next;
        free(p);  // �ͷ�����Ľڵ��ڴ�ռ�
        p = q;
    }

    return 0;
}

