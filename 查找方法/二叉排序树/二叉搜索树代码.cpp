#include <stdio.h>
#include <stdlib.h>

// ����������ṹ
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// �ݹ���Һ���
struct TreeNode* search(struct TreeNode* root, int key) {
    // �����Ϊ�ջ����ҵ���Ŀ��ڵ㣬���ظ��ڵ����Ŀ��ڵ�
    if (root == NULL || root->data == key) {
        return root;
    }

    // ���Ŀ��ֵС�ڵ�ǰ�ڵ��ֵ���ݹ����������в���
    if (key < root->data) {
        return search(root->left, key);
    }
    
    // ���Ŀ��ֵ���ڵ�ǰ�ڵ��ֵ���ݹ����������в���
    return search(root->right, key);
}

// �����½ڵ�
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// �ڶ������в���ڵ�
struct TreeNode* insert(struct TreeNode* root, int data) {
    // �����Ϊ�գ�ֱ�Ӵ����½ڵ㲢����
    if (root == NULL) {
        return createNode(data);
    }
    
    // ���򣬵ݹ����ڵ㵽��������������
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int key = 40;
    struct TreeNode* result = search(root, key);
    if (result != NULL) {
        printf("Found %d in the tree.\n", key);
    } else {
        printf("%d not found in the tree.\n", key);
    }

    return 0;
}
 
