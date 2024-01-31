#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct Node {
    int data;             // 节点存储的数据
    struct Node* left;    // 左子节点指针
    struct Node* right;   // 右子节点指针
} Node;

// 创建一个新的节点并返回指针
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // 分配内存以存储新节点
    if (newNode == NULL) {
        printf("内存分配失败！\n");  // 分配失败时输出错误信息
        return NULL;
    }
    newNode->data = data;       // 设置节点数据为传入的数据
    newNode->left = NULL;       // 初始化左子节点指针为空
    newNode->right = NULL;      // 初始化右子节点指针为空
    return newNode;             // 返回新节点的指针
}

// 在二叉搜索树中插入一个新节点
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  // 如果树为空，创建一个新节点并作为根节点
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);  // 如果数据比根节点小，插入左子树
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);  // 如果数据比根节点大，插入右子树
    }
    return root;  // 返回插入后的根节点指针
}

// 在二叉搜索树中搜索特定的节点
Node* searchNode(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;  // 如果根节点为空或者根节点的数据等于要搜索的数据，直接返回根节点
    }
    if (key < root->data) {
        return searchNode(root->left, key);  // 如果要搜索的数据比根节点小，从左子树搜索
    }
    return searchNode(root->right, key);  // 否则从右子树搜索
}

int main() {
    Node* root = NULL;  // 初始化根节点为空

    root = insertNode(root, 50);  // 插入一系列节点构建二叉搜索树
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    int key;
    printf("请输入要在二叉搜索树中搜索的数字：");
    scanf("%d", &key);

    Node* result = searchNode(root, key);  // 在树中搜索特定数据的节点
    if (result == NULL) {
        printf("%d 在二叉搜索树中未找到！\n", key);
    } else {
        printf("%d 在二叉搜索树中找到！\n", result->data);
    }

    return 0;
}

