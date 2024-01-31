#include <stdio.h>
#include <stdlib.h>

// ���嵥����ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ����һ���½ڵ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ������ĩβ�����½ڵ�
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// ����ɾ��������
void deleteLinkedList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL; // ��ͷָ����Ϊ�գ���ʾ�����Ѿ�����ȫɾ��
}

// ��ӡ����
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // ������ĩβ����ڵ�
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("ԭʼ����");
    printLinkedList(head);

    // ɾ����������
    deleteLinkedList(&head);

    printf("������ɾ����");
    printLinkedList(head);

    return 0;
}

