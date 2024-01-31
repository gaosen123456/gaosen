#include <stdio.h>

int sentinelSearch(int arr[], int n, int target) {
    int last = arr[n-1];  // �������һ��Ԫ�ص�ֵ
    arr[n-1] = target;  // �����ڱ�

    int i = 0;
    while (arr[i] != target) {
        i++;
    }

    arr[n-1] = last;  // �ָ����һ��Ԫ�ص�ֵ

    if (i < n-1 || arr[n-1] == target) {
        return i;  // ����Ŀ��Ԫ�ص��±�
    }

    return -1;  // ���δ�ҵ�Ŀ��Ԫ�أ��򷵻�-1
}

int main() {
    int n;
    printf("����������ĳ���: ");
    scanf("%d", &n);

    int arr[n];
    printf("�����������Ԫ��: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("������Ҫ���ҵ�Ŀ������: ");
    scanf("%d", &target);

    int result = sentinelSearch(arr, n, target);

    if (result == -1) {
        printf("δ�ҵ�Ŀ������ %d", target);
    } else {
        printf("Ŀ������ %d �����������λ�� %d", target, result);
    }

    return 0;
}
