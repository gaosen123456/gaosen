#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;             // 节点数据
    struct Node* left;    // 左子节点指针
    struct Node* right;   // 右子节点指针
    int height;           // 节点高度（用于平衡）
};

int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;    // 返回节点的高度
}

int balanceFactor(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);    // 计算平衡因子
}

void updateHeight(struct Node* node) {
    int leftHeight = height(node->left);     // 左子树高度
    int rightHeight = height(node->right);   // 右子树高度
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;   // 更新节点的高度
}

struct Node* leftRotate(struct Node* node) {
    struct Node* newRoot = node->right;     // 新根节点为当前节点的右子节点
    node->right = newRoot->left;            // 将新根节点的左子节点作为当前节点的右子节点
    newRoot->left = node;                    // 将当前节点作为新根节点的左子节点

    updateHeight(node);                     // 更新当前节点的高度
    updateHeight(newRoot);                  // 更新新根节点的高度

    return newRoot;                          // 返回新的根节点
}

struct Node* rightRotate(struct Node* node) {
    struct Node* newRoot = node->left;     // 新根节点为当前节点的左子节点
    node->left = newRoot->right;           // 将新根节点的右子节点作为当前节点的左子节点
    newRoot->right = node;                  // 将当前节点作为新根节点的右子节点

    updateHeight(node);                    // 更新当前节点的高度
    updateHeight(newRoot);                 // 更新新根节点的高度

    return newRoot;                         // 返回新的根节点
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (data < node->data) {
        node->left = insert(node->left, data);    // 插入左子树
    } else {
        node->right = insert(node->right, data);  // 插入右子树
    }

    updateHeight(node);                          // 更新节点的高度

    int bf = balanceFactor(node);                 // 获取节点的平衡因子
    if (bf > 1 && data < node->left->data) {
        return rightRotate(node);                 // 进行右旋转
    }
    if (bf < -1 && data > node->right->data) {
        return leftRotate(node);                  // 进行左旋转
    }
    if (bf > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);       // 先左旋转
        return rightRotate(node);                 // 再右旋转
    }
    if (bf < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);    // 先右旋转
        return leftRotate(node);                  // 再左旋转
    }

    return node;
}


// 找到最小值节点
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// 删除节点
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    // 更新节点的高度
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = balanceFactor(root);

    // 平衡树
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// 查询节点
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}
void printInorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);                  // 中序遍历左子树
    printf("%d ", node->data);                  // 打印节点数据
    printInorder(node->right);                 // 中序遍历右子树
}

int main() {
    struct Node* root = NULL;
    int numNodes, data;

    printf("请输入二叉树中的结点个数：");
    scanf("%d", &numNodes);

    printf("请输入二叉树的数字：\n");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("中序遍历结果: \n");
    printInorder(root);                // 打印中序遍历结果
    printf("\n");
	
	int newData;
    printf("输入新值: ");
    scanf("%d", &newData);

    root = insert(root, newData);

    printf("中序遍历结果: ");
    printInorder(root);
    printf("\n");
    
    int deleteData;
    printf("输入要删除的值: ");
    scanf("%d", &deleteData);

    root = deleteNode(root, deleteData);

    printf("中序遍历结果: ");
    printInorder(root);
    printf("\n");
    
    int searchData;
    printf("输入要查找的值: ");
    scanf("%d", &searchData);

    struct Node* searchResult = search(root, searchData);
    if (searchResult)
        printf("找到 %d 在树中.\n", searchData);
    else
        printf("%d 不在树中.\n", searchData);
    return 0;
}

