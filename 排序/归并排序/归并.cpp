#include <stdio.h>

// �ϲ�������������
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    
    // �Ƚ��������������Ԫ�أ�����С��Ԫ�ط���ԭ������
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++]; // ���������Ԫ�ط���ԭ�����У����ƶ��������ԭ�����ָ��
        } else {
            arr[k++] = right[j++]; // ���������Ԫ�ط���ԭ�����У����ƶ��������ԭ�����ָ��
        }
    }
    
    // ��ʣ���Ԫ�ط���ԭ������
    while (i < leftSize) {
        arr[k++] = left[i++]; // ��������ʣ���Ԫ�ط���ԭ������
    }
    while (j < rightSize) {
        arr[k++] = right[j++]; // ��������ʣ���Ԫ�ط���ԭ������
    }
}

// �鲢����
void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return; // ������鳤��С�ڵ���1����������
    }
    
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    
    // ��ԭ�����Ϊ����������
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i]; // ��ԭ�����ǰ�벿�ַ���������
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i]; // ��ԭ����ĺ�벿�ַ���������
    }
    
    // �ݹ�ض������������������
    mergeSort(left, mid); // ����������й鲢����
    mergeSort(right, size - mid); // ����������й鲢����
    
    // �ϲ���������������
    merge(arr, left, mid, right, size - mid); // ������������������ϲ���ԭ������
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // �����ȡ�û����������Ԫ��
    }
   
    mergeSort(arr, size); // ��������й鲢����
    
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // ��ӡ����������
    }
    printf("\n");
    
    return 0;
}
