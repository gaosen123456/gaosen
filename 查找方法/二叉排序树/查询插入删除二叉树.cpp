#include <stdio.h>
#include <stdlib.h>

// ��������㶨��
typedef struct TreeNode {
    int data;               // ����д洢������
    struct TreeNode* left;  // ���ӽ��ָ��
    struct TreeNode* right; // ���ӽ��ָ��
} TreeNode;

// �����½�� 
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); // �����ڴ�ռ�
    if (newNode == NULL) {
        printf("�ڴ����ʧ�ܣ�\n"); // �ڴ����ʧ�ܴ���
        exit(1);
    }
    newNode->data = data;     // ���ý������
    newNode->left = NULL;     // ��ʼ�����ӽ��Ϊ NULL
    newNode->right = NULL;    // ��ʼ�����ӽ��Ϊ NULL
    return newNode;
}

// ������
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data); // �����ǰ���Ϊ�գ������½�㲢����
    } else {
        if (data < root->data) {
            root->left = insertNode(root->left, data); // �ݹ����������
        } else {
            root->right = insertNode(root->right, data); // �ݹ����������
        }
        return root;
    }
}

// ���ҽ��
TreeNode* searchNode(TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root; // �����ǰ���Ϊ�ջ��ҵ���Ŀ�����ݣ����ؽ��
    } else if (data < root->data) {
        return searchNode(root->left, data); // �ݹ����������
    } else {
        return searchNode(root->right, data); // �ݹ����������
    }
}

// ɾ�����
TreeNode* deleteNode(TreeNode* root, int data) {
    if (root == NULL) {
        return root; // ������ֱ�ӷ���
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data); // �ݹ�ɾ�����������
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data); // �ݹ�ɾ�����������
    } else {
        // �ҵ�Ҫɾ���Ľ��
        if (root->left == NULL) {
            TreeNode* temp = root->right; // ����������
            free(root); // �ͷ�Ҫɾ���Ľ��
            return temp; // ������������Ϊ�µĸ�
        } else if (root->right == NULL) {
            TreeNode* temp = root->left; // ����������
            free(root); // �ͷ�Ҫɾ���Ľ��
            return temp; // ������������Ϊ�µĸ�
        }
        // �������ӽ������
        TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left; // �ҵ�����������С�Ľ��
        }
        root->data = temp->data; // ����С����ֵ����Ҫɾ���Ľ��
        root->right = deleteNode(root->right, temp->data); // �ݹ�ɾ���������е���С���
    }
    return root;
}

// �������������
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);       // ����������
        printf("%d ", root->data);          // ��ӡ��ǰ��������
        inorderTraversal(root->right);      // ����������
    }
}

int main() {
    TreeNode* root = NULL; // ������ʼ��Ϊ��

    // ����һЩ����Թ�������������
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("���������������");
    inorderTraversal(root); // �����������ӡ������
    printf("\n");

    int searchData = 40;
    TreeNode* searchResult = searchNode(root, searchData);
    if (searchResult != NULL) {
        printf("%d �����ڶ������С�\n", searchData);
    } else {
        printf("%d �������ڶ������С�\n", searchData);
    }

    int deleteData = 30;
    root = deleteNode(root, deleteData);
    printf("ɾ����� %d ���������������", deleteData);
    inorderTraversal(root); // �����������ӡɾ������Ķ�����
    printf("\n");

    return 0;
}

