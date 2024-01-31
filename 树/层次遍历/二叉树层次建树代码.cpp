#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    int val;                    // 节点值
    struct TreeNode* left;      // 左子节点指针
    struct TreeNode* right;     // 右子节点指针
};

// 定义队列节点结构
struct QueueNode {
    struct TreeNode* data;      // 队列节点存储的数据，即二叉树节点指针
    struct QueueNode* next;     // 下一个队列节点的指针
};

// 定义队列结构
struct Queue {
    struct QueueNode* front;    // 队列的前端指针，用于出队操作
    struct QueueNode* rear;     // 队列的后端指针，用于入队操作
};

// 初始化队列
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); // 分配队列内存
    queue->front = queue->rear = NULL; // 初始化前端和后端指针为空
    return queue;
}

// 入队
void enqueue(struct Queue* queue, struct TreeNode* data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); // 分配新的队列节点内存
    newNode->data = data;         // 设置新节点的数据为传入的二叉树节点指针
    newNode->next = NULL;         // 新节点的下一个节点为空

    if (queue->rear == NULL) {    // 如果队列为空
        queue->front = queue->rear = newNode; // 设置前端和后端指针都指向新节点
        return;
    }

    queue->rear->next = newNode;  // 将新节点链接到当前队列尾部
    queue->rear = newNode;        // 更新队列尾部指针为新节点
}

// 出队
struct TreeNode* dequeue(struct Queue* queue) {
    if (queue->front == NULL)     // 如果队列为空，返回空指针
        return NULL;

    struct TreeNode* data = queue->front->data; // 获取队列头部节点的数据
    struct QueueNode* temp = queue->front;      // 临时保存队列头部节点指针
    queue->front = queue->front->next;          // 更新队列头部指针为下一个节点

    if (queue->front == NULL)                   // 如果出队后队列为空
        queue->rear = NULL;                     // 更新队列尾部指针为空

    free(temp);                                 // 释放出队节点的内存
    return data;                                // 返回出队节点的数据（二叉树节点指针）
}

// 层次遍历
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL)                           // 如果根节点为空，直接返回
        return;

    struct Queue* queue = createQueue();        // 创建一个新队列
    enqueue(queue, root);                       // 将根节点入队

    while (queue->front != NULL) {              // 当队列不为空时循环
        struct TreeNode* current = dequeue(queue); // 出队并保存当前节点指针
        printf("%d ", current->val);            // 打印当前节点的值

        if (current->left)                      // 如果有左子节点
            enqueue(queue, current->left);      // 将左子节点入队
        if (current->right)                     // 如果有右子节点
            enqueue(queue, current->right);     // 将右子节点入队
    }

    free(queue);                                // 释放队列内存
}

// 创建新的二叉树节点
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // 分配新的二叉树节点内存
    newNode->val = val;                         // 设置节点值
    newNode->left = newNode->right = NULL;       // 初始化左右子节点为空
    return newNode;                             // 返回新创建的节点
}

int main() {
    // 创建一个简单的二叉树
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("层次遍历结果: ");
    levelOrderTraversal(root);                  // 调用层次遍历函数

    return 0;
}

