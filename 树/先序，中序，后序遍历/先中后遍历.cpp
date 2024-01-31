#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结点
struct TreeNode {
    int data;               // 结点的数据
    struct TreeNode* left;  // 左子树指针
    struct TreeNode* right; // 右子树指针
};

// 创建一个新的二叉树结点
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // 分配内存来创建结点
    newNode->data = data;   // 设置结点的数据
    newNode->left = NULL;   // 初始化左子树指针为NULL
    newNode->right = NULL;  // 初始化右子树指针为NULL
    return newNode;         // 返回创建的结点
}

// 先序遍历
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);         // 先输出当前结点的数据
        preorderTraversal(root->left);     // 递归遍历左子树
        preorderTraversal(root->right);    // 递归遍历右子树
    }
}


// 中序遍历
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);      // 递归遍历左子树
        printf("%d ", root->data);         // 在中间位置输出当前结点的数据
        inorderTraversal(root->right);     // 递归遍历右子树
    }
}

// 后序遍历
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);    // 递归遍历左子树
        postorderTraversal(root->right);   // 递归遍历右子树
        printf("%d ", root->data);         // 最后输出当前结点的数据
    }
}

int main() {
    // 构建一个简单的二叉树
    struct TreeNode* root = createNode(1);     // 创建根结点，数据为1
    root->left = createNode(2);                // 根结点的左子树为结点2
    root->right = createNode(3);               // 根结点的右子树为结点3
    root->left->left = createNode(4);          // 结点2的左子树为结点4
    root->left->right = createNode(5);         // 结点2的右子树为结点5

    printf("Preorder traversal: ");
    preorderTraversal(root);                   // 输出先序遍历结果
    printf("\n");

    printf("Inorder traversal: ");
    inorderTraversal(root);                    // 输出中序遍历结果
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);                  // 输出后序遍历结果
    printf("\n");

    return 0;
}

