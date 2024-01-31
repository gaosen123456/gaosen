#include <stdio.h>
#include <stdlib.h>

// 定义循环链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建一个新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode; // 注意循环链表的特性，节点的 next 指向自身
    return newNode;
}

// 在循环链表末尾插入新节点
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

// 删除循环链表中的指定值节点
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        return; // 空链表无需删除
    }

    Node* current = *head;
    Node* prev = NULL;

    do {
        if (current->data == data) {
            if (current == *head) {
                if (current->next == current) {
                    // 如果链表只有一个节点，则直接删除
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

    printf("未找到要删除的节点：%d\n", data);
}

// 打印循环链表
void printCircularLinkedList(Node* head) {
    if (head == NULL) {
        printf("空链表\n");
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

    // 在循环链表末尾插入节点
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("原始循环链表：");
    printCircularLinkedList(head);

    // 删除节点
    deleteNode(&head, 3);
    deleteNode(&head, 1);

    printf("删除节点后的循环链表：");
    printCircularLinkedList(head);

    return 0;
}

