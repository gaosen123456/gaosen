#include <stdio.h>
#include <stdlib.h>

// ����ѭ������ڵ�ṹ
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
    newNode->next = newNode; // ע��ѭ����������ԣ��ڵ�� next ָ������
    return newNode;
}

// ��ѭ������ĩβ�����½ڵ�
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

// ɾ��ѭ�������е�ָ��ֵ�ڵ�
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        return; // ����������ɾ��
    }

    Node* current = *head;
    Node* prev = NULL;

    do {
        if (current->data == data) {
            if (current == *head) {
                if (current->next == current) {
                    // �������ֻ��һ���ڵ㣬��ֱ��ɾ��
                    free(current);
                    *head = NULL;
                    return;
                } else {
                    Node* last = *head;
                    while (last->next != *head) {
                        last = last->next;
                    }
                    *head = current->next;
                    last->next = *head;
                }
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *head);

    printf("δ�ҵ�Ҫɾ���Ľڵ㣺%d\n", data);
}

// ��ӡѭ������
void printCircularLinkedList(Node* head) {
    if (head == NULL) {
        printf("������\n");
        return;
    }

    Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    Node* head = NULL;

    // ��ѭ������ĩβ����ڵ�
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("ԭʼѭ������");
    printCircularLinkedList(head);

    // ɾ���ڵ�
    deleteNode(&head, 3);
    deleteNode(&head, 1);

    printf("ɾ���ڵ���ѭ������");
    printCircularLinkedList(head);

    return 0;
}

