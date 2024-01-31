#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // 返回目标元素的下标
        } else if (arr[mid] < target) {
            left = mid + 1;  // 在右半边继续查找
        } else {
            right = mid - 1;  // 在左半边继续查找
        }
    }

    return -1;  // 如果未找到目标元素，则返回-1
}

int main() {
    int n;
    printf("请输入数组的长度: ");
    scanf("%d", &n);

    int arr[n];
    printf("请输入有序数组的元素: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("请输入要查找的目标数字: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result == -1) {
        printf("未找到目标数字 %d。", target);
    } else {
        printf("目标数字 %d 存在于数组的位置 %d。", target, result);
    }

    return 0;
}
