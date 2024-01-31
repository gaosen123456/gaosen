#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结构
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 递归查找函数
struct TreeNode* search(struct TreeNode* root, int key) {
    // 如果树为空或者找到了目标节点，返回根节点或者目标节点
    if (root == NULL || root->data == key) {
        return root;
    }

    // 如果目标值小于当前节点的值，递归在左子树中查找
    if (key < root->data) {
        return search(root->left, key);
    }
    
    // 如果目标值大于当前节点的值，递归在右子树中查找
    return search(root->right, key);
}

// 创建新节点
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 在二叉树中插入节点
struct TreeNode* insert(struct TreeNode* root, int data) {
    // 如果树为空，直接创建新节点并返回
    if (root == NULL) {
        return createNode(data);
    }
    
    // 否则，递归插入节点到左子树或右子树
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
 
