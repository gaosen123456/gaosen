#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key; // ��
    int value; // ֵ
    struct Node* next; // ָ����һ���ڵ��ָ��
} Node; 

Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // �����ڴ��Դ洢�½ڵ�
    if (newNode == NULL) {
        printf("�ڴ����ʧ�ܣ�");
        exit(1);
    }

    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int key) {
    return key % TABLE_SIZE; // ��ϣ��������ӳ�䵽��ϣ�������
}

void insert(Node** hashtable, int key, int value) {
    int index = hashFunction(key); // ʹ�ù�ϣ������������

    Node* newNode = createNode(key, value); // �����½ڵ�

    if (hashtable[index] == NULL) { // �������λ��Ϊ�գ�ֱ�Ӳ����½ڵ�
        hashtable[index] = newNode;
    } else { // ����������������½ڵ�
        Node* currentNode = hashtable[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

int search(Node** hashtable, int key) {
    int index = hashFunction(key); // ʹ�ù�ϣ������������

    Node* currentNode = hashtable[index]; // ��ȡ����λ�õ�����ͷ�ڵ�
    while (currentNode != NULL) {
        if (currentNode->key == key) { // �����������ƥ��ļ�
            return currentNode->value; // �ҵ��򷵻���Ӧ��ֵ
        }
        currentNode = currentNode->next; // ����������һ���ڵ�
    }
    return -1; // δ�ҵ���������-1
}

void deleteNode(Node** hashtable, int key) {
    int index = hashFunction(key); // ʹ�ù�ϣ������������

    Node* currentNode = hashtable[index]; // ��ȡ����λ�õ�����ͷ�ڵ�
    Node* prevNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->key == key) { // �����������ƥ��ļ�
            if (prevNode == NULL) { // �����ͷ�ڵ㣬���¹�ϣ���е�����
                hashtable[index] = currentNode->next;
            } else { // �������ǰһ���ڵ��ָ��
                prevNode->next = currentNode->next;
            }
            free(currentNode); // �ͷ�ɾ���Ľڵ���ڴ�
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next; // ����������һ���ڵ�
    }
}

void printHashTable(Node** hashtable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("���� %d: ", i); // ��ӡ����λ��
        Node* currentNode = hashtable[i];
        while (currentNode != NULL) {
            printf("(%d, %d) ", currentNode->key, currentNode->value); // ��ӡ��ֵ��
            currentNode = currentNode->next; // ����������һ���ڵ�
        }
        printf("\n");
    }
}

int main() {
    Node* hashtable[TABLE_SIZE] = { NULL }; // ��ϣ����ʼ��Ϊ��

    insert(hashtable, 5, 100); // ����һЩ��ʼ��ֵ��
    insert(hashtable, 15, 200);
    insert(hashtable, 25, 300);
    insert(hashtable, 35, 400);
    insert(hashtable, 45, 500);
    insert(hashtable, 55, 600);

    printf("��ʼ��ϣ��\n");
    printHashTable(hashtable); // ��ӡ��ʼ��ϣ��

    int key;
    printf("������Ҫ���ҵļ���");
    scanf("%d", &key);

    int value = search(hashtable, key); // ���Ҽ���Ӧ��ֵ
    if (value != -1) {
        printf("�� %d ��ֵ��%d\n", key, value);
    } else {
        printf("δ�ҵ��� %d��\n", key);
    }

    int deleteKey;
    printf("������Ҫɾ���ļ���");
    scanf("%d", &deleteKey);
    deleteNode(hashtable, deleteKey); // ɾ��ָ�����Ľڵ�

    printf("���º�Ĺ�ϣ��\n");
    printHashTable(hashtable); // ��ӡ���º�Ĺ�ϣ��

    return 0;
}

