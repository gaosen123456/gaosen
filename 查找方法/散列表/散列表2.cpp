#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key; // 键
    int value; // 值
    struct Node* next; // 指向下一个节点的指针
} Node; 

Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // 分配内存以存储新节点
    if (newNode == NULL) {
        printf("内存分配失败！");
        exit(1);
    }

    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int key) {
    return key % TABLE_SIZE; // 哈希函数将键映射到哈希表的索引
}

void insert(Node** hashtable, int key, int value) {
    int index = hashFunction(key); // 使用哈希函数计算索引

    Node* newNode = createNode(key, value); // 创建新节点

    if (hashtable[index] == NULL) { // 如果索引位置为空，直接插入新节点
        hashtable[index] = newNode;
    } else { // 否则遍历链表并插入新节点
        Node* currentNode = hashtable[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

int search(Node** hashtable, int key) {
    int index = hashFunction(key); // 使用哈希函数计算索引

    Node* currentNode = hashtable[index]; // 获取索引位置的链表头节点
    while (currentNode != NULL) {
        if (currentNode->key == key) { // 遍历链表查找匹配的键
            return currentNode->value; // 找到则返回相应的值
        }
        currentNode = currentNode->next; // 继续遍历下一个节点
    }
    return -1; // 未找到键，返回-1
}

void deleteNode(Node** hashtable, int key) {
    int index = hashFunction(key); // 使用哈希函数计算索引

    Node* currentNode = hashtable[index]; // 获取索引位置的链表头节点
    Node* prevNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->key == key) { // 遍历链表查找匹配的键
            if (prevNode == NULL) { // 如果是头节点，更新哈希表中的索引
                hashtable[index] = currentNode->next;
            } else { // 否则更新前一个节点的指针
                prevNode->next = currentNode->next;
            }
            free(currentNode); // 释放删除的节点的内存
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next; // 继续遍历下一个节点
    }
}

void printHashTable(Node** hashtable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("索引 %d: ", i); // 打印索引位置
        Node* currentNode = hashtable[i];
        while (currentNode != NULL) {
            printf("(%d, %d) ", currentNode->key, currentNode->value); // 打印键值对
            currentNode = currentNode->next; // 继续遍历下一个节点
        }
        printf("\n");
    }
}

int main() {
    Node* hashtable[TABLE_SIZE] = { NULL }; // 哈希表，初始化为空

    insert(hashtable, 5, 100); // 插入一些初始键值对
    insert(hashtable, 15, 200);
    insert(hashtable, 25, 300);
    insert(hashtable, 35, 400);
    insert(hashtable, 45, 500);
    insert(hashtable, 55, 600);

    printf("初始哈希表：\n");
    printHashTable(hashtable); // 打印初始哈希表

    int key;
    printf("请输入要查找的键：");
    scanf("%d", &key);

    int value = search(hashtable, key); // 查找键对应的值
    if (value != -1) {
        printf("键 %d 的值：%d\n", key, value);
    } else {
        printf("未找到键 %d！\n", key);
    }

    int deleteKey;
    printf("请输入要删除的键：");
    scanf("%d", &deleteKey);
    deleteNode(hashtable, deleteKey); // 删除指定键的节点

    printf("更新后的哈希表：\n");
    printHashTable(hashtable); // 打印更新后的哈希表

    return 0;
}

