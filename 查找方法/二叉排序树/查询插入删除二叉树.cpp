#include <stdio.h>
#include <stdlib.h>

// 二叉树结点定义
typedef struct TreeNode {
    int data;               // 结点中存储的数据
    struct TreeNode* left;  // 左子结点指针
    struct TreeNode* right; // 右子结点指针
} TreeNode;

// 创建新结点 
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); // 分配内存空间
    if (newNode == NULL) {
        printf("内存分配失败！\n"); // 内存分配失败处理
        exit(1);
    }
    newNode->data = data;     // 设置结点数据
    newNode->left = NULL;     // 初始化左子结点为 NULL
    newNode->right = NULL;    // 初始化右子结点为 NULL
    return newNode;
}

// 插入结点
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data); // 如果当前结点为空，创建新结点并返回
    } else {
        if (data < root->data) {
            root->left = insertNode(root->left, data); // 递归插入左子树
        } else {
            root->right = insertNode(root->right, data); // 递归插入右子树
        }
        return root;
    }
}

// 查找结点
TreeNode* searchNode(TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root; // 如果当前结点为空或找到了目标数据，返回结点
    } else if (data < root->data) {
        return searchNode(root->left, data); // 递归查找左子树
    } else {
        return searchNode(root->right, data); // 递归查找右子树
    }
}

// 删除结点
TreeNode* deleteNode(TreeNode* root, int data) {
    if (root == NULL) {
        return root; // 空树，直接返回
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data); // 递归删除左子树结点
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data); // 递归删除右子树结点
    } else {
        // 找到要删除的结点
        if (root->left == NULL) {
            TreeNode* temp = root->right; // 保存右子树
            free(root); // 释放要删除的结点
            return temp; // 返回右子树作为新的根
        } else if (root->right == NULL) {
            TreeNode* temp = root->left; // 保存左子树
            free(root); // 释放要删除的结点
            return temp; // 返回左子树作为新的根
        }
        // 有两个子结点的情况
        TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left; // 找到右子树中最小的结点
        }
        root->data = temp->data; // 将最小结点的值赋给要删除的结点
        root->right = deleteNode(root->right, temp->data); // 递归删除右子树中的最小结点
    }
    return root;
}

// 中序遍历二叉树
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);       // 遍历左子树
        printf("%d ", root->data);          // 打印当前结点的数据
        inorderTraversal(root->right);      // 遍历右子树
    }
}

int main() {
    TreeNode* root = NULL; // 根结点初始化为空

    // 插入一些结点以构建二叉搜索树
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("中序遍历二叉树：");
    inorderTraversal(root); // 中序遍历并打印二叉树
    printf("\n");

    int searchData = 40;
    TreeNode* searchResult = searchNode(root, searchData);
    if (searchResult != NULL) {
        printf("%d 存在于二叉树中。\n", searchData);
    } else {
        printf("%d 不存在于二叉树中。\n", searchData);
    }

    int deleteData = 30;
    root = deleteNode(root, deleteData);
    printf("删除结点 %d 后的中序遍历结果：", deleteData);
    inorderTraversal(root); // 中序遍历并打印删除结点后的二叉树
    printf("\n");

    return 0;
}

