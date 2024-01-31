#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // ����Ŀ��Ԫ�ص��±�
        } else if (arr[mid] < target) {
            left = mid + 1;  // ���Ұ�߼�������
        } else {
            right = mid - 1;  // �����߼�������
        }
    }

    return -1;  // ���δ�ҵ�Ŀ��Ԫ�أ��򷵻�-1
}

int main() {
    int n;
    printf("����������ĳ���: ");
    scanf("%d", &n);

    int arr[n];
    printf("���������������Ԫ��: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("������Ҫ���ҵ�Ŀ������: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result == -1) {
        printf("δ�ҵ�Ŀ������ %d��", target);
    } else {
        printf("Ŀ������ %d �����������λ�� %d��", target, result);
    }

    return 0;
}
