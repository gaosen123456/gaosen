#include <stdio.h>

void binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int found = 0;  // ����Ƿ��ҵ�Ŀ��Ԫ��

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            found = 1;  // ����ҵ�Ŀ��Ԫ��

            // �����������������ͬԪ�ص��±�
            for (int i = mid; i >= 0 && arr[i] == target; i--) {
                printf("Ŀ������ %d �����������λ�� %d��", target, i);
            }

            // ���ұ���������ұ���ͬԪ�ص��±�
            for (int i = mid + 1; i < n && arr[i] == target; i++) {
                printf("Ŀ������ %d �����������λ�� %d��", target, i);
            }

            break;  // ����ѭ��
        } else if (arr[mid] < target) {
            left = mid + 1;  // ���Ұ�߼�������
        } else {
            right = mid - 1;  // �����߼�������
        }
    }

    if (found == 0) {
        printf("δ�ҵ�Ŀ������ %d��", target);
    }
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

    binarySearch(arr, n, target);

    return 0;
}
