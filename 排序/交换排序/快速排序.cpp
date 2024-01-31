#include <stdio.h>

// �������������
void quicksort(int arr[], int low, int high) {
    // ������ֻ��һ��Ԫ�ػ���û��Ԫ�أ�����Ҫ����
    if (low >= high) {
        return;
    }
    // ��������ָ��
    int left = low, right = high;
    // ѡ���м�Ԫ����Ϊ��׼ֵ
    int pivot = arr[(low + high) / 2];
    // ��ʼ��������
    while (left <= right) {
        // ������ҵ�һ���Ȼ�׼ֵ���Ԫ��
        while (arr[left] < pivot) {
            left++;
        }
        // ���ұ��ҵ�һ���Ȼ�׼ֵС��Ԫ��
        while (arr[right] > pivot) {
            right--;
        }
        // �����ָ��������ָ�����ߣ��򽻻�����Ԫ��
        if (left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    // �ݹ����
    quicksort(arr, low, right);
    quicksort(arr, left, high);
}

int main() {
    int n;
    printf("������Ҫ��������ָ�����");
    scanf("%d", &n);
    
    int arr[n];
    printf("������Ҫ��������֣�");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    quicksort(arr, 0, n - 1);
    printf("���������飺\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

