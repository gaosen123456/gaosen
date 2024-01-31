#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

// 散列表节点
typedef struct Node {
    int key;             // 键
    int value;           // 值
    struct Node* next;   // 指向下一个节点的指针
} Node;

// 创建一个散列表节点
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);  // 内存分配失败，退出程序
    }

    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// 哈希函数，将键映射到散列表索引
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// 向散列表中插入键值对
void insert(Node** hashtable, int key, int value) {
    int index = hashFunction(key);  // 计算散列索引

    Node* newNode = createNode(key, value);

    if (hashtable[index] == NULL) {
        hashtable[index] = newNode;   // 散列表索引为空，直接插入节点
    } else {
        Node* currentNode = hashtable[index];   // 指向散列表索引处的第一个节点
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;    // 找到链表的最后一个节点
        }
        currentNode->next = newNode;   // 插入节点到链表的末尾
    }
}

// 从散列表中搜索给定键的值
int search(Node** hashtable, int key) {
    int index = hashFunction(key);   // 计算散列索引

    Node* currentNode = hashtable[index];   // 指向散列表索引处的第一个节点
    while (currentNode != NULL) {
        if (currentNode->key == key) {
            return currentNode->value;   // 键匹配，返回对应的值
        }
        currentNode = currentNode->next;   // 继续搜索下一个节点
    }
    return -1; // 未找到键，返回-1
}

int main() {
    Node* hashtable[TABLE_SIZE] = { NULL };   // 散列表

    // 向散列表中插入键值对
    insert(hashtable, 5, 100);
    insert(hashtable, 15, 200);
    insert(hashtable, 25, 300);

    // 从散列表中搜索键的值
    int value = search(hashtable, 15);
    if (value != -1) {
        printf("Value at key 15: %d", value);
    } else {
        printf("Key 15 not found!\n");
    }

    return 0;
}
