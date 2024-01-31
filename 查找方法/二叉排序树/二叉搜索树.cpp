#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct Node {
    int data;             // �ڵ�洢������
    struct Node* left;    // ���ӽڵ�ָ��
    struct Node* right;   // ���ӽڵ�ָ��
} Node;

// ����һ���µĽڵ㲢����ָ��
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // �����ڴ��Դ洢�½ڵ�
    if (newNode == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");  // ����ʧ��ʱ���������Ϣ
        return NULL;
    }
    newNode->data = data;       // ���ýڵ�����Ϊ���������
    newNode->left = NULL;       // ��ʼ�����ӽڵ�ָ��Ϊ��
    newNode->right = NULL;      // ��ʼ�����ӽڵ�ָ��Ϊ��
    return newNode;             // �����½ڵ��ָ��
}

// �ڶ����������в���һ���½ڵ�
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  // �����Ϊ�գ�����һ���½ڵ㲢��Ϊ���ڵ�
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);  // ������ݱȸ��ڵ�С������������
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);  // ������ݱȸ��ڵ�󣬲���������
    }
    return root;  // ���ز����ĸ��ڵ�ָ��
}

// �ڶ����������������ض��Ľڵ�
Node* searchNode(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;  // ������ڵ�Ϊ�ջ��߸��ڵ�����ݵ���Ҫ���������ݣ�ֱ�ӷ��ظ��ڵ�
    }
    if (key < root->data) {
        return searchNode(root->left, key);  // ���Ҫ���������ݱȸ��ڵ�С��������������
    }
    return searchNode(root->right, key);  // ���������������
}

int main() {
    Node* root = NULL;  // ��ʼ�����ڵ�Ϊ��

    root = insertNode(root, 50);  // ����һϵ�нڵ㹹������������
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    int key;
    printf("������Ҫ�ڶ��������������������֣�");
    scanf("%d", &key);

    Node* result = searchNode(root, key);  // �����������ض����ݵĽڵ�
    if (result == NULL) {
        printf("%d �ڶ�����������δ�ҵ���\n", key);
    } else {
        printf("%d �ڶ������������ҵ���\n", result->data);
    }

    return 0;
}

