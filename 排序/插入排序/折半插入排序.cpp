#include <stdio.h>

void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // �洢��ǰ�������Ԫ��
        int left = 0; // ���򲿷ֵ���ʼλ��
        int right = i - 1; // ���򲿷ֵĽ���λ��

        // ʹ�ö��ֲ����ҵ�����λ��
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > key) {
                right = mid - 1; // ������Ԫ��Ӧ������벿��
            } else {
                left = mid + 1; // ������Ԫ��Ӧ�����Ұ벿��
            }
        }

        // ������λ��֮���Ԫ������
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }

        // ��Ԫ�ز��뵽��ȷ��λ��
        arr[left] = key;
    }
}

int main() {
    int n;
    printf("������Ҫ��������ָ�����");
    scanf("%d", &n);
    
    int arr[n];
    printf("������%d�����֣�", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    binaryInsertionSort(arr, n);

    printf("���������飺");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
