#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

// 定义散列表的节点结构
typedef struct Node {
    int key;                           // 整数键
    int value;                         // 整数值
    struct Node* next;                 // 指向下一个节点的指针
} Node;

// 创建一个新的节点
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // 分配内存空间
    if (newNode == NULL) {
        printf("Memory allocation failed!");       // 如果内存分配失败，则输出错误信息并退出
        exit(1);
    }

    newNode->key = key;                            // 设置节点的键
    newNode->value = value;                        // 设置节点的值
    newNode->next = NULL;                          // 初始化下一个指针为空
    return newNode;
}

// 哈希函数，将键映射到散列表索引
int hashFunction(int key) {
    return key % TABLE_SIZE;                       // 对键进行取模运算，得到散列表的索引
}

// 向散列表中插入键值对
void insert(Node** hashtable, int key, int value) {
    int index = hashFunction(key);                  // 计算键的哈希值得到索引

    Node* newNode = createNode(key, value);          // 创建新的节点

    if (hashtable[index] == NULL) {
        hashtable[index] = newNode;                 // 如果索引处为空，直接将新节点插入该位置
    } else {
        Node* currentNode = hashtable[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;        // 遍历链表，找到链表末尾的节点
        }
        currentNode->next = newNode;                // 将新节点插入链表末尾
    }
}

// 从散列表中搜索给定键的值
int search(Node** hashtable, int key) {
    int index = hashFunction(key);                  // 计算键的哈希值得到索引

    Node* currentNode = hashtable[index];
    while (currentNode != NULL) {
        if (currentNode->key == key) {
            return currentNode->value;              // 如果键匹配，返回对应的值
        }
        currentNode = currentNode->next;            // 继续遍历链表
    }
    return -1;                                      // 如果未找到键，返回-1
}

// 从散列表中删除给定键的节点
void deleteNode(Node** hashtable, int key) {
    int index = hashFunction(key);                  // 计算键的哈希值得到索引

    if (hashtable[index] == NULL) {
        return;                                     // 如果索引处为空，则键不存在，直接返回
    }

    Node* currentNode = hashtable[index];
    Node* prevNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->key == key) {               // 如果找到了要删除的节点
            if (prevNode == NULL) {
                hashtable[index] = currentNode->next;   // 如果要删除的节点是链表的第一个节点，更新散列表索引处的引用
            } else {
                prevNode->next = currentNode->next;     // 如果要删除的节点位于链表的中间位置或链表末尾，更新前一个节点的next指针
            }
            free(currentNode);                          // 释放被删除节点的内存
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;               // 继续遍历链表
    }
}

// 打印散列表的内容
void printHashTable(Node** hashtable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);                            // 打印当前索引
        Node* currentNode = hashtable[i];
        while (currentNode != NULL) {
            printf("(%d, %d) ", currentNode->key, currentNode->value);   // 打印键和值
            currentNode = currentNode->next;               // 继续遍历链表
        }
        printf("\n");                                      // 打印换行符
    }
}

int main() {
    Node* hashtable[TABLE_SIZE] = { NULL };                // 声明并初始化散列表

    insert(hashtable, 1, 100);                              // 插入键值对
    insert(hashtable, 2, 200);
    insert(hashtable, 3, 300);
    insert(hashtable, 4, 400);
    insert(hashtable, 5, 500);
    insert(hashtable, 6, 600);

    printf("Initial Hash Table:\n");
    printHashTable(hashtable);                             // 打印初始的散列表

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int value = search(hashtable, key);                     // 搜索键的值
    if (value != -1) {
        printf("Value at key %d: %d\n", key, value);
    } else {
        printf("Key %d not found!\n", key);
    }

    int deleteKey;
    printf("Enter the key to delete: \n");
    scanf("%d", &deleteKey);
    deleteNode(hashtable, deleteKey);                        // 删除键对应的节点

    printf("Updated Hash Table:\n");
    printHashTable(hashtable);                              // 打印更新后的散列表

    return 0;
}
