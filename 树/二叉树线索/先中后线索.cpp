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

// 中序遍历线索二叉树
void inOrderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;

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

// 先序遍历线索二叉树
void preOrderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;

    while (current != NULL) {
        printf("%d ", current->data); // 输出当前节点数据

        // 如果左线索标记为1，沿着左线索移动到下一个节点
        if (current->leftTag == 1)
            current = current->left;
        // 否则，沿着右子节点移动到下一个节点
        else
            current = current->right;
    }
}

// 后序遍历线索二叉树
void postOrderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;
    struct TreeNode* prev = NULL;

    while (current != NULL) {
        // 如果左线索标记为1，沿着左线索移动到下一个节点
        if (current->leftTag == 1)
            current = current->left;
        // 否则，如果右线索标记为1，沿着右线索移动到下一个节点
        else if (current->rightTag == 1)
            current = current->right;
        // 否则，输出当前节点数据，并将当前节点移动到其父节点
        else {
            printf("%d ", current->data);
            prev = current;
            current = current->right;

            // 如果当前节点是其父节点的左子节点，继续沿着右线索移动到下一个节点
            while (prev != NULL && prev->rightTag == 0) {
                prev = prev->right;
                printf("%d ", prev->data);
            }

            // 如果当前节点是根节点，结束遍历
            if (prev == root)
                break;

            // 否则，将当前节点移动到其父节点的右子节点
            current = prev->right;
        }
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

    // 手动设置线索化信息
    root->left->right = root;
    root->leftTag = 1;
    root->right->left = root;
    root->rightTag = 1;

    printf("中序线索化结果: ");
    inOrderTraversal(root);
    printf("\n");

    printf("先序线索化结果: ");
    preOrderTraversal(root);
    printf("\n");

    printf("后序线索化结果: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}

