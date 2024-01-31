#include <stdio.h>

// �鲢��������������
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;  // ��������ĳ���
    int n2 = right - mid;     // ��������ĳ���

    // ������ʱ�������洢�����������ֵ
    int L[n1], R[n2];

    // �����ݿ�������ʱ����
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];  // �����������鵽��ʱ���� L
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];  // �����������鵽��ʱ���� R
    }

    // �鲢������ʱ���鵽ԭ����
    i = 0;  // ��ʼ���������������
    j = 0;  // ��ʼ���������������
    k = left;  // ��ʼ���鲢�����������
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];  // ����С��Ԫ�ط���ԭ����
            i++;
        }
        else {
            arr[k] = R[j];  // ����С��Ԫ�ط���ԭ����
            j++;
        }
        k++;
    }

    // ��ʣ��Ԫ�ؿ�����ԭ����
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// �鲢����
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // �����м�����

        // �ݹ�ض�������������й鲢����
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // �鲢����������
        merge(arr, left, mid, right);
    }
}

// ��ӡ����Ԫ��
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("���������鳤��: ");
    scanf("%d", &n);

    int arr[n];

    printf("����������Ԫ��:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);  // ���ù鲢������

    printf("���������飺\n");
    printArray(arr, n);

    return 0;
}

