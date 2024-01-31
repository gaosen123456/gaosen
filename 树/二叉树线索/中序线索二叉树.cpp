#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
struct TreeNode {
    int data;               // 节点数据
    struct TreeNode *left;  // 左子节点指针
    struct TreeNode *right; // 右子节点指针
    int leftTag;            // 左线索标记
    int rightTag;           // 右线索标记
};

// 创建新节点
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftTag = 0;   // 初始化为非线索
    newNode->rightTag = 0;  // 初始化为非线索
    return newNode;
}

// 中序遍历二叉树线索化
struct TreeNode* inOrderThread(struct TreeNode* root, struct TreeNode* prev) {
    if (root != NULL) {
        // 递归处理左子树，传入前一个线索化的节点 prev
        prev = inOrderThread(root->left, prev);

        // 如果左子节点为空，设置左线索
        if (root->left == NULL) {
            root->left = prev;  // 将左子节点指向前一个节点
            root->leftTag = 1;  // 标记为左线索
        }

        // 如果前一个节点存在且前一个节点的右子节点为空，设置右线索
        if (prev != NULL && prev->right == NULL) {
            prev->right = root; // 将前一个节点的右子节点指向当前节点
            prev->rightTag = 1; // 标记为右线索
        }

        prev = root; // 更新前一个线索化的节点为当前节点

        // 递归处理右子树，传入更新后的 prev
        prev = inOrderThread(root->right, prev);
    }

    return prev;
}

// 中序遍历线索二叉树
void inOrderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;

    // 从根节点开始，沿着左线索找到最左边的节点
    while (current != NULL) {
        while (current->leftTag == 0)
            current = current->left;

        printf("%d ", current->data); // 输出当前节点数据

        // 遍历右线索节点
        while (current->rightTag == 1) {
            current = current->right;
            printf("%d ", current->data);
        }

        // 移动到下一个节点（即右子节点）
        current = current->right;
    }
}

int main() {
    // 创建二叉树节点并构建二叉树结构
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    struct TreeNode* prev = NULL;
    prev = inOrderThread(root, prev); // 执行线索化

    printf("线索化中序遍历结果: ");
    inOrderTraversal(root); // 执行线索化中序遍历
    printf("\n");

    return 0;
}

