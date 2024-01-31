#include <stdio.h>
#include <stdlib.h>

// ������������
struct TreeNode {
    int data;               // ��������
    struct TreeNode* left;  // ������ָ��
    struct TreeNode* right; // ������ָ��
};

// ����һ���µĶ��������
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // �����ڴ����������
    newNode->data = data;   // ���ý�������
    newNode->left = NULL;   // ��ʼ��������ָ��ΪNULL
    newNode->right = NULL;  // ��ʼ��������ָ��ΪNULL
    return newNode;         // ���ش����Ľ��
}

// �������
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return; // ��������Ϊ�գ�ֱ�ӷ���
    }

    // ������еĽ��ṹ
    struct QueueNode {
        struct TreeNode* node;  // �����д洢���Ƕ��������ָ��
        struct QueueNode* next;  // ��һ�����н��ָ��
    };

    struct QueueNode* front = NULL; // ���е�ǰ��ָ�룬���ڳ��Ӳ���
    struct QueueNode* rear = NULL;  // ���еĺ��ָ�룬������Ӳ���

    // ����������
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); // �������н��
    newNode->node = root;   // �洢��ǰ��Ľ��
    newNode->next = NULL;
    front = newNode;        // ����ǰ��ָ��ָ���½��
    rear = newNode;         // ���к��ָ��ָ���½��

    while (front != NULL) {
        // ���Ӳ����ʵ�ǰ���
        struct TreeNode* current = front->node; // ��ȡ���еĵ�ǰ���
        printf("%d ", current->data);           // �����ǰ��������

        // �����ӽ�����
        if (current->left != NULL) {
            struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); // �������н��
            newNode->node = current->left;   // �洢���ӽ��
            newNode->next = NULL;
            rear->next = newNode;            // ���к��ָ�����ӵ��½��
            rear = newNode;                  // ���¶��к��ָ��
        }

        // �����ӽ�����
        if (current->right != NULL) {
            struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); // �������н��
            newNode->node = current->right;  // �洢���ӽ��
            newNode->next = NULL;
            rear->next = newNode;            // ���к��ָ�����ӵ��½��
            rear = newNode;                  // ���¶��к��ָ��
        }

        // ���ӵ�ǰ���
        struct QueueNode* temp = front;     // ��ʱ�洢����ǰ��ָ��
        front = front->next;                // ���¶���ǰ��ָ��Ϊ��һ�����
        free(temp);                         // �ͷ���ʱ�����ڴ�
    }
}

int main() {
    // ����һ���򵥵Ķ�����
    struct TreeNode* root = createNode(1);     // ��������㣬����Ϊ1
    root->left = createNode(2);                // ������������Ϊ���2
    root->right = createNode(3);               // ������������Ϊ���3
    root->left->left = createNode(4);          // ���2��������Ϊ���4
    root->left->right = createNode(5);         // ���2��������Ϊ���5

    printf("Level Order traversal: ");
    levelOrderTraversal(root);                 // �������������
    printf("\n");

    return 0;
}

