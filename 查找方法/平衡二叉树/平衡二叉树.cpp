#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;             // �ڵ�����
    struct Node* left;    // ���ӽڵ�ָ��
    struct Node* right;   // ���ӽڵ�ָ��
    int height;           // �ڵ�߶ȣ�����ƽ�⣩
};

int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;    // ���ؽڵ�ĸ߶�
}

int balanceFactor(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);    // ����ƽ������
}

void updateHeight(struct Node* node) {
    int leftHeight = height(node->left);     // �������߶�
    int rightHeight = height(node->right);   // �������߶�
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;   // ���½ڵ�ĸ߶�
}

struct Node* leftRotate(struct Node* node) {
    struct Node* newRoot = node->right;     // �¸��ڵ�Ϊ��ǰ�ڵ�����ӽڵ�
    node->right = newRoot->left;            // ���¸��ڵ�����ӽڵ���Ϊ��ǰ�ڵ�����ӽڵ�
    newRoot->left = node;                    // ����ǰ�ڵ���Ϊ�¸��ڵ�����ӽڵ�

    updateHeight(node);                     // ���µ�ǰ�ڵ�ĸ߶�
    updateHeight(newRoot);                  // �����¸��ڵ�ĸ߶�

    return newRoot;                          // �����µĸ��ڵ�
}

struct Node* rightRotate(struct Node* node) {
    struct Node* newRoot = node->left;     // �¸��ڵ�Ϊ��ǰ�ڵ�����ӽڵ�
    node->left = newRoot->right;           // ���¸��ڵ�����ӽڵ���Ϊ��ǰ�ڵ�����ӽڵ�
    newRoot->right = node;                  // ����ǰ�ڵ���Ϊ�¸��ڵ�����ӽڵ�

    updateHeight(node);                    // ���µ�ǰ�ڵ�ĸ߶�
    updateHeight(newRoot);                 // �����¸��ڵ�ĸ߶�

    return newRoot;                         // �����µĸ��ڵ�
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
        node->left = insert(node->left, data);    // ����������
    } else {
        node->right = insert(node->right, data);  // ����������
    }

    updateHeight(node);                          // ���½ڵ�ĸ߶�

    int bf = balanceFactor(node);                 // ��ȡ�ڵ��ƽ������
    if (bf > 1 && data < node->left->data) {
        return rightRotate(node);                 // ��������ת
    }
    if (bf < -1 && data > node->right->data) {
        return leftRotate(node);                  // ��������ת
    }
    if (bf > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);       // ������ת
        return rightRotate(node);                 // ������ת
    }
    if (bf < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);    // ������ת
        return leftRotate(node);                  // ������ת
    }

    return node;
}


// �ҵ���Сֵ�ڵ�
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// ɾ���ڵ�
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

    // ���½ڵ�ĸ߶�
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = balanceFactor(root);

    // ƽ����
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

// ��ѯ�ڵ�
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
    printInorder(node->left);                  // �������������
    printf("%d ", node->data);                  // ��ӡ�ڵ�����
    printInorder(node->right);                 // �������������
}

int main() {
    struct Node* root = NULL;
    int numNodes, data;

    printf("������������еĽ�������");
    scanf("%d", &numNodes);

    printf("����������������֣�\n");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("����������: \n");
    printInorder(root);                // ��ӡ����������
    printf("\n");
	
	int newData;
    printf("������ֵ: ");
    scanf("%d", &newData);

    root = insert(root, newData);

    printf("����������: ");
    printInorder(root);
    printf("\n");
    
    int deleteData;
    printf("����Ҫɾ����ֵ: ");
    scanf("%d", &deleteData);

    root = deleteNode(root, deleteData);

    printf("����������: ");
    printInorder(root);
    printf("\n");
    
    int searchData;
    printf("����Ҫ���ҵ�ֵ: ");
    scanf("%d", &searchData);

    struct Node* searchResult = search(root, searchData);
    if (searchResult)
        printf("�ҵ� %d ������.\n", searchData);
    else
        printf("%d ��������.\n", searchData);
    return 0;
}

