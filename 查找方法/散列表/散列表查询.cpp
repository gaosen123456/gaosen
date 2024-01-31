#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

// ����ɢ�б�Ľڵ�ṹ
typedef struct Node {
    int key;                           // ������
    int value;                         // ����ֵ
    struct Node* next;                 // ָ����һ���ڵ��ָ��
} Node;

// ����һ���µĽڵ�
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // �����ڴ�ռ�
    if (newNode == NULL) {
        printf("Memory allocation failed!");       // ����ڴ����ʧ�ܣ������������Ϣ���˳�
        exit(1);
    }

    newNode->key = key;                            // ���ýڵ�ļ�
    newNode->value = value;                        // ���ýڵ��ֵ
    newNode->next = NULL;                          // ��ʼ����һ��ָ��Ϊ��
    return newNode;
}

// ��ϣ����������ӳ�䵽ɢ�б�����
int hashFunction(int key) {
    return key % TABLE_SIZE;                       // �Լ�����ȡģ���㣬�õ�ɢ�б������
}

// ��ɢ�б��в����ֵ��
void insert(Node** hashtable, int key, int value) {
    int index = hashFunction(key);                  // ������Ĺ�ϣֵ�õ�����

    Node* newNode = createNode(key, value);          // �����µĽڵ�

    if (hashtable[index] == NULL) {
        hashtable[index] = newNode;                 // ���������Ϊ�գ�ֱ�ӽ��½ڵ�����λ��
    } else {
        Node* currentNode = hashtable[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;        // ���������ҵ�����ĩβ�Ľڵ�
        }
        currentNode->next = newNode;                // ���½ڵ��������ĩβ
    }
}

// ��ɢ�б���������������ֵ
int search(Node** hashtable, int key) {
    int index = hashFunction(key);                  // ������Ĺ�ϣֵ�õ�����

    Node* currentNode = hashtable[index];
    while (currentNode != NULL) {
        if (currentNode->key == key) {
            return currentNode->value;              // �����ƥ�䣬���ض�Ӧ��ֵ
        }
        currentNode = currentNode->next;            // ������������
    }
    return -1;                                      // ���δ�ҵ���������-1
}

// ��ɢ�б���ɾ���������Ľڵ�
void deleteNode(Node** hashtable, int key) {
    int index = hashFunction(key);                  // ������Ĺ�ϣֵ�õ�����

    if (hashtable[index] == NULL) {
        return;                                     // ���������Ϊ�գ���������ڣ�ֱ�ӷ���
    }

    Node* currentNode = hashtable[index];
    Node* prevNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->key == key) {               // ����ҵ���Ҫɾ���Ľڵ�
            if (prevNode == NULL) {
                hashtable[index] = currentNode->next;   // ���Ҫɾ���Ľڵ�������ĵ�һ���ڵ㣬����ɢ�б�������������
            } else {
                prevNode->next = currentNode->next;     // ���Ҫɾ���Ľڵ�λ��������м�λ�û�����ĩβ������ǰһ���ڵ��nextָ��
            }
            free(currentNode);                          // �ͷű�ɾ���ڵ���ڴ�
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;               // ������������
    }
}

// ��ӡɢ�б������
void printHashTable(Node** hashtable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);                            // ��ӡ��ǰ����
        Node* currentNode = hashtable[i];
        while (currentNode != NULL) {
            printf("(%d, %d) ", currentNode->key, currentNode->value);   // ��ӡ����ֵ
            currentNode = currentNode->next;               // ������������
        }
        printf("\n");                                      // ��ӡ���з�
    }
}

int main() {
    Node* hashtable[TABLE_SIZE] = { NULL };                // ��������ʼ��ɢ�б�

    insert(hashtable, 1, 100);                              // �����ֵ��
    insert(hashtable, 2, 200);
    insert(hashtable, 3, 300);
    insert(hashtable, 4, 400);
    insert(hashtable, 5, 500);
    insert(hashtable, 6, 600);

    printf("Initial Hash Table:\n");
    printHashTable(hashtable);                             // ��ӡ��ʼ��ɢ�б�

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int value = search(hashtable, key);                     // ��������ֵ
    if (value != -1) {
        printf("Value at key %d: %d\n", key, value);
    } else {
        printf("Key %d not found!\n", key);
    }

    int deleteKey;
    printf("Enter the key to delete: \n");
    scanf("%d", &deleteKey);
    deleteNode(hashtable, deleteKey);                        // ɾ������Ӧ�Ľڵ�

    printf("Updated Hash Table:\n");
    printHashTable(hashtable);                              // ��ӡ���º��ɢ�б�

    return 0;
}
