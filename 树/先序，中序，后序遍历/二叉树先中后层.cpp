#include <stdio.h>
#include <stdlib.h>

// ������������
struct TreeNode {
    int data;                 // �ڵ�ֵ
    struct TreeNode* left;    // ���ӽ��ָ��
    struct TreeNode* right;   // ���ӽ��ָ��
};

// ����һ���µĶ��������
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // �����½���ڴ�
    newNode->data = data;                        // ���ý��ֵ
    newNode->left = NULL;                        // ��ʼ�����ӽ��Ϊ��
    newNode->right = NULL;                       // ��ʼ�����ӽ��Ϊ��
    return newNode;                              // �����´����Ľ��
}

// �������
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;                                  // ��������Ϊ�գ�ֱ�ӷ���
    }

    // ������н��
    struct QueueNode {
        struct TreeNode* node;                   // ���н��洢���Ƕ��������ָ��
        struct QueueNode* next;                  // ��һ�����н��ָ��
    };

    struct QueueNode* front = NULL;              // ����ǰ��ָ��
    struct QueueNode* rear = NULL;               // ���к��ָ��

    // ����������
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); // �����¶��н���ڴ�
    newNode->node = root;                       // �����½��Ķ��������ָ��
    newNode->next = NULL;
    front = newNode;                            // ��ʼ������ǰ��ָ��Ϊ�½��
    rear = newNode;                             // ��ʼ�����к��ָ��Ϊ�½��

    while (front != NULL) {                     // �����в�Ϊ��ʱѭ��
        struct TreeNode* current = front->node;  // ��ǰ����Ľ��
        printf("%d ", current->data);            // ��ӡ��ǰ��������

        // ��������������
        if (current->left != NULL) {
            struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
            newNode->node = current->left;
            newNode->next = NULL;
            if (rear == NULL) {
                front = newNode;                 // �������Ϊ�գ����¶���ͷ
            } else {
                rear->next = newNode;            // ���½�����ӵ�����β��
            }
            rear = newNode;                      // ���¶���β��ָ��
        }

        // ��������������
        if (current->right != NULL) {
            struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
            newNode->node = current->right;
            newNode->next = NULL;
            if (rear == NULL) {
                front = newNode;                 // �������Ϊ�գ����¶���ͷ
            } else {
                rear->next = newNode;            // ���½�����ӵ�����β��
            }
            rear = newNode;                      // ���¶���β��ָ��
        }

        struct QueueNode* temp = front;           // ��ʱ�������ǰ��ָ��
        front = front->next;                      // ���ӣ����¶���ǰ��ָ��Ϊ��һ�����
        free(temp);                               // �ͷŵ�ǰ������Ľ���ڴ�
    }
}

int main() {
    // ����һ���򵥵Ķ�����
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Level Order traversal: ");
    levelOrderTraversal(root);                   // ���ò����������
    printf("\n");

    return 0;
}

