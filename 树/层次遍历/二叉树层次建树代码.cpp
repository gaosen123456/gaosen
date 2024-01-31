#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
struct TreeNode {
    int val;                    // �ڵ�ֵ
    struct TreeNode* left;      // ���ӽڵ�ָ��
    struct TreeNode* right;     // ���ӽڵ�ָ��
};

// ������нڵ�ṹ
struct QueueNode {
    struct TreeNode* data;      // ���нڵ�洢�����ݣ����������ڵ�ָ��
    struct QueueNode* next;     // ��һ�����нڵ��ָ��
};

// ������нṹ
struct Queue {
    struct QueueNode* front;    // ���е�ǰ��ָ�룬���ڳ��Ӳ���
    struct QueueNode* rear;     // ���еĺ��ָ�룬������Ӳ���
};

// ��ʼ������
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); // ��������ڴ�
    queue->front = queue->rear = NULL; // ��ʼ��ǰ�˺ͺ��ָ��Ϊ��
    return queue;
}

// ���
void enqueue(struct Queue* queue, struct TreeNode* data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); // �����µĶ��нڵ��ڴ�
    newNode->data = data;         // �����½ڵ������Ϊ����Ķ������ڵ�ָ��
    newNode->next = NULL;         // �½ڵ����һ���ڵ�Ϊ��

    if (queue->rear == NULL) {    // �������Ϊ��
        queue->front = queue->rear = newNode; // ����ǰ�˺ͺ��ָ�붼ָ���½ڵ�
        return;
    }

    queue->rear->next = newNode;  // ���½ڵ����ӵ���ǰ����β��
    queue->rear = newNode;        // ���¶���β��ָ��Ϊ�½ڵ�
}

// ����
struct TreeNode* dequeue(struct Queue* queue) {
    if (queue->front == NULL)     // �������Ϊ�գ����ؿ�ָ��
        return NULL;

    struct TreeNode* data = queue->front->data; // ��ȡ����ͷ���ڵ������
    struct QueueNode* temp = queue->front;      // ��ʱ�������ͷ���ڵ�ָ��
    queue->front = queue->front->next;          // ���¶���ͷ��ָ��Ϊ��һ���ڵ�

    if (queue->front == NULL)                   // ������Ӻ����Ϊ��
        queue->rear = NULL;                     // ���¶���β��ָ��Ϊ��

    free(temp);                                 // �ͷų��ӽڵ���ڴ�
    return data;                                // ���س��ӽڵ�����ݣ��������ڵ�ָ�룩
}

// ��α���
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL)                           // ������ڵ�Ϊ�գ�ֱ�ӷ���
        return;

    struct Queue* queue = createQueue();        // ����һ���¶���
    enqueue(queue, root);                       // �����ڵ����

    while (queue->front != NULL) {              // �����в�Ϊ��ʱѭ��
        struct TreeNode* current = dequeue(queue); // ���Ӳ����浱ǰ�ڵ�ָ��
        printf("%d ", current->val);            // ��ӡ��ǰ�ڵ��ֵ

        if (current->left)                      // ��������ӽڵ�
            enqueue(queue, current->left);      // �����ӽڵ����
        if (current->right)                     // ��������ӽڵ�
            enqueue(queue, current->right);     // �����ӽڵ����
    }

    free(queue);                                // �ͷŶ����ڴ�
}

// �����µĶ������ڵ�
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // �����µĶ������ڵ��ڴ�
    newNode->val = val;                         // ���ýڵ�ֵ
    newNode->left = newNode->right = NULL;       // ��ʼ�������ӽڵ�Ϊ��
    return newNode;                             // �����´����Ľڵ�
}

int main() {
    // ����һ���򵥵Ķ�����
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("��α������: ");
    levelOrderTraversal(root);                  // ���ò�α�������

    return 0;
}

