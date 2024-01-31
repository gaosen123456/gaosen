#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

// ɢ�б�ڵ�
typedef struct Node {
    int key;             // ��
    int value;           // ֵ
    struct Node* next;   // ָ����һ���ڵ��ָ��
} Node;

// ����һ��ɢ�б�ڵ�
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);  // �ڴ����ʧ�ܣ��˳�����
    }

    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// ��ϣ����������ӳ�䵽ɢ�б�����
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// ��ɢ�б��в����ֵ��
void insert(Node** hashtable, int key, int value) {
    int index = hashFunction(key);  // ����ɢ������

    Node* newNode = createNode(key, value);

    if (hashtable[index] == NULL) {
        hashtable[index] = newNode;   // ɢ�б�����Ϊ�գ�ֱ�Ӳ���ڵ�
    } else {
        Node* currentNode = hashtable[index];   // ָ��ɢ�б��������ĵ�һ���ڵ�
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;    // �ҵ���������һ���ڵ�
        }
        currentNode->next = newNode;   // ����ڵ㵽�����ĩβ
    }
}

// ��ɢ�б���������������ֵ
int search(Node** hashtable, int key) {
    int index = hashFunction(key);   // ����ɢ������

    Node* currentNode = hashtable[index];   // ָ��ɢ�б��������ĵ�һ���ڵ�
    while (currentNode != NULL) {
        if (currentNode->key == key) {
            return currentNode->value;   // ��ƥ�䣬���ض�Ӧ��ֵ
        }
        currentNode = currentNode->next;   // ����������һ���ڵ�
    }
    return -1; // δ�ҵ���������-1
}

int main() {
    Node* hashtable[TABLE_SIZE] = { NULL };   // ɢ�б�

    // ��ɢ�б��в����ֵ��
    insert(hashtable, 5, 100);
    insert(hashtable, 15, 200);
    insert(hashtable, 25, 300);

    // ��ɢ�б�����������ֵ
    int value = search(hashtable, 15);
    if (value != -1) {
        printf("Value at key 15: %d", value);
    } else {
        printf("Key 15 not found!\n");
    }

    return 0;
}
