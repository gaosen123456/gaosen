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

// 层序遍历
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return; // 如果根结点为空，直接返回
    }

    // 定义队列的结点结构
    struct QueueNode {
        struct TreeNode* node;  // 队列中存储的是二叉树结点指针
        struct QueueNode* next;  // 下一个队列结点指针
    };

    struct QueueNode* front = NULL; // 队列的前端指针，用于出队操作
    struct QueueNode* rear = NULL;  // 队列的后端指针，用于入队操作

    // 将根结点入队
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); // 创建队列结点
    newNode->node = root;   // 存储当前层的结点
    newNode->next = NULL;
    front = newNode;        // 队列前端指针指向新结点
    rear = newNode;         // 队列后端指针指向新结点

    while (front != NULL) {
        // 出队并访问当前结点
        struct TreeNode* current = front->node; // 获取队列的当前结点
        printf("%d ", current->data);           // 输出当前结点的数据

        // 将左子结点入队
        if (current->left != NULL) {
            struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); // 创建队列结点
            newNode->node = current->left;   // 存储左子结点
            newNode->next = NULL;
            rear->next = newNode;            // 队列后端指针连接到新结点
            rear = newNode;                  // 更新队列后端指针
        }

        // 将右子结点入队
        if (current->right != NULL) {
            struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); // 创建队列结点
            newNode->node = current->right;  // 存储右子结点
            newNode->next = NULL;
            rear->next = newNode;            // 队列后端指针连接到新结点
            rear = newNode;                  // 更新队列后端指针
        }

        // 出队当前结点
        struct QueueNode* temp = front;     // 临时存储队列前端指针
        front = front->next;                // 更新队列前端指针为下一个结点
        free(temp);                         // 释放临时结点的内存
    }
}

int main() {
    // 构建一个简单的二叉树
    struct TreeNode* root = createNode(1);     // 创建根结点，数据为1
    root->left = createNode(2);                // 根结点的左子树为结点2
    root->right = createNode(3);               // 根结点的右子树为结点3
    root->left->left = createNode(4);          // 结点2的左子树为结点4
    root->left->right = createNode(5);         // 结点2的右子树为结点5

    printf("Level Order traversal: ");
    levelOrderTraversal(root);                 // 输出层序遍历结果
    printf("\n");

    return 0;
}

