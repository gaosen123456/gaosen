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

// �����������������
void inOrderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;

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

// �����������������
void preOrderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;

    while (current != NULL) {
        printf("%d ", current->data); // �����ǰ�ڵ�����

        // ������������Ϊ1�������������ƶ�����һ���ڵ�
        if (current->leftTag == 1)
            current = current->left;
        // �����������ӽڵ��ƶ�����һ���ڵ�
        else
            current = current->right;
    }
}

// �����������������
void postOrderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;
    struct TreeNode* prev = NULL;

    while (current != NULL) {
        // ������������Ϊ1�������������ƶ�����һ���ڵ�
        if (current->leftTag == 1)
            current = current->left;
        // ����������������Ϊ1�������������ƶ�����һ���ڵ�
        else if (current->rightTag == 1)
            current = current->right;
        // ���������ǰ�ڵ����ݣ�������ǰ�ڵ��ƶ����丸�ڵ�
        else {
            printf("%d ", current->data);
            prev = current;
            current = current->right;

            // �����ǰ�ڵ����丸�ڵ�����ӽڵ㣬���������������ƶ�����һ���ڵ�
            while (prev != NULL && prev->rightTag == 0) {
                prev = prev->right;
                printf("%d ", prev->data);
            }

            // �����ǰ�ڵ��Ǹ��ڵ㣬��������
            if (prev == root)
                break;

            // ���򣬽���ǰ�ڵ��ƶ����丸�ڵ�����ӽڵ�
            current = prev->right;
        }
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

    // �ֶ�������������Ϣ
    root->left->right = root;
    root->leftTag = 1;
    root->right->left = root;
    root->rightTag = 1;

    printf("�������������: ");
    inOrderTraversal(root);
    printf("\n");

    printf("�������������: ");
    preOrderTraversal(root);
    printf("\n");

    printf("�������������: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}

