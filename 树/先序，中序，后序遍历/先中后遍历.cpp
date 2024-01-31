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
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);         // �������ǰ��������
        preorderTraversal(root->left);     // �ݹ����������
        preorderTraversal(root->right);    // �ݹ����������
    }
}


// �������
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);      // �ݹ����������
        printf("%d ", root->data);         // ���м�λ�������ǰ��������
        inorderTraversal(root->right);     // �ݹ����������
    }
}

// �������
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);    // �ݹ����������
        postorderTraversal(root->right);   // �ݹ����������
        printf("%d ", root->data);         // ��������ǰ��������
    }
}

int main() {
    // ����һ���򵥵Ķ�����
    struct TreeNode* root = createNode(1);     // ��������㣬����Ϊ1
    root->left = createNode(2);                // ������������Ϊ���2
    root->right = createNode(3);               // ������������Ϊ���3
    root->left->left = createNode(4);          // ���2��������Ϊ���4
    root->left->right = createNode(5);         // ���2��������Ϊ���5

    printf("Preorder traversal: ");
    preorderTraversal(root);                   // �������������
    printf("\n");

    printf("Inorder traversal: ");
    inorderTraversal(root);                    // �������������
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);                  // �������������
    printf("\n");

    return 0;
}

