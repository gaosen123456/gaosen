#include <stdio.h>

void binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int found = 0;  // 标记是否找到目标元素

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            found = 1;  // 标记找到目标元素

            // 向左遍历，输出左边相同元素的下标
            for (int i = mid; i >= 0 && arr[i] == target; i--) {
                printf("目标数字 %d 存在于数组的位置 %d。", target, i);
            }

            // 向右遍历，输出右边相同元素的下标
            for (int i = mid + 1; i < n && arr[i] == target; i++) {
                printf("目标数字 %d 存在于数组的位置 %d。", target, i);
            }

            break;  // 结束循环
        } else if (arr[mid] < target) {
            left = mid + 1;  // 在右半边继续查找
        } else {
            right = mid - 1;  // 在左半边继续查找
        }
    }

    if (found == 0) {
        printf("未找到目标数字 %d。", target);
    }
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

    binarySearch(arr, n, target);

    return 0;
}
