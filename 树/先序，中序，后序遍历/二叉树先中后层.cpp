#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结点
struct TreeNode {
    int data;                 // 节点值
    struct TreeNode* left;    // 左子结点指针
    struct TreeNode* right;   // 右子结点指针
};

// 创建一个新的二叉树结点
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // 分配新结点内存
    newNode->data = data;                        // 设置结点值
    newNode->left = NULL;                        // 初始化左子结点为空
    newNode->right = NULL;                       // 初始化右子结点为空
    return newNode;                              // 返回新创建的结点
}

// 层序遍历
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;                                  // 如果根结点为空，直接返回
    }

    // 定义队列结点
    struct QueueNode {
        struct TreeNode* node;                   // 队列结点存储的是二叉树结点指针
        struct QueueNode* next;                  // 下一个队列结点指针
    };

    struct QueueNode* front = NULL;              // 队列前端指针
    struct QueueNode* rear = NULL;               // 队列后端指针

    // 将根结点入队
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); // 分配新队列结点内存
    newNode->node = root;                       // 设置新结点的二叉树结点指针
    newNode->next = NULL;
    front = newNode;                            // 初始化队列前端指针为新结点
    rear = newNode;                             // 初始化队列后端指针为新结点

    while (front != NULL) {                     // 当队列不为空时循环
        struct TreeNode* current = front->node;  // 当前处理的结点
        printf("%d ", current->data);            // 打印当前结点的数据

        // 将左子树结点入队
        if (current->left != NULL) {
            struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
            newNode->node = current->left;
            newNode->next = NULL;
            if (rear == NULL) {
                front = newNode;                 // 如果队列为空，更新队列头
            } else {
                rear->next = newNode;            // 将新结点链接到队列尾部
            }
            rear = newNode;                      // 更新队列尾部指针
        }

        // 将右子树结点入队
        if (current->right != NULL) {
            struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
            newNode->node = current->right;
            newNode->next = NULL;
            if (rear == NULL) {
                front = newNode;                 // 如果队列为空，更新队列头
            } else {
                rear->next = newNode;            // 将新结点链接到队列尾部
            }
            rear = newNode;                      // 更新队列尾部指针
        }

        struct QueueNode* temp = front;           // 临时保存队列前端指针
        front = front->next;                      // 出队，更新队列前端指针为下一个结点
        free(temp);                               // 释放当前处理过的结点内存
    }
}

int main() {
    // 构建一个简单的二叉树
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Level Order traversal: ");
    levelOrderTraversal(root);                   // 调用层序遍历函数
    printf("\n");

    return 0;
}

