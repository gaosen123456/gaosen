#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
struct TreeNode {
    int data;               // �ڵ�����
    struct TreeNode *left;  // ���ӽڵ�ָ��
    struct TreeNode *right; // ���ӽڵ�ָ��
    int leftTag;            // ���������
    int rightTag;           // ���������
};

// �����½ڵ�
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftTag = 0;   // ��ʼ��Ϊ������
    newNode->rightTag = 0;  // ��ʼ��Ϊ������
    return newNode;
}

// �������������������
struct TreeNode* inOrderThread(struct TreeNode* root, struct TreeNode* prev) {
    if (root != NULL) {
        // �ݹ鴦��������������ǰһ���������Ľڵ� prev
        prev = inOrderThread(root->left, prev);

        // ������ӽڵ�Ϊ�գ�����������
        if (root->left == NULL) {
            root->left = prev;  // �����ӽڵ�ָ��ǰһ���ڵ�
            root->leftTag = 1;  // ���Ϊ������
        }

        // ���ǰһ���ڵ������ǰһ���ڵ�����ӽڵ�Ϊ�գ�����������
        if (prev != NULL && prev->right == NULL) {
            prev->right = root; // ��ǰһ���ڵ�����ӽڵ�ָ��ǰ�ڵ�
            prev->rightTag = 1; // ���Ϊ������
        }

        prev = root; // ����ǰһ���������Ľڵ�Ϊ��ǰ�ڵ�

        // �ݹ鴦����������������º�� prev
        prev = inOrderThread(root->right, prev);
    }

    return prev;
}

// �����������������
void inOrderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;

    // �Ӹ��ڵ㿪ʼ�������������ҵ�����ߵĽڵ�
    while (current != NULL) {
        while (current->leftTag == 0)
            current = current->left;

        printf("%d ", current->data); // �����ǰ�ڵ�����

        // �����������ڵ�
        while (current->rightTag == 1) {
            current = current->right;
            printf("%d ", current->data);
        }

        // �ƶ�����һ���ڵ㣨�����ӽڵ㣩
        current = current->right;
    }
}

int main() {
    // �����������ڵ㲢�����������ṹ
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    struct TreeNode* prev = NULL;
    prev = inOrderThread(root, prev); // ִ��������

    printf("����������������: ");
    inOrderTraversal(root); // ִ���������������
    printf("\n");

    return 0;
}

