#include <stdio.h>

int sentinelSearch(int arr[], int n, int target) {
    int last = arr[n-1];  // 保存最后一个元素的值
    arr[n-1] = target;  // 设置哨兵

    int i = 0;
    while (arr[i] != target) {
        i++;
    }

    arr[n-1] = last;  // 恢复最后一个元素的值

    if (i < n-1 || arr[n-1] == target) {
        return i;  // 返回目标元素的下标
    }

    return -1;  // 如果未找到目标元素，则返回-1
}

int main() {
    int n;
    printf("请输入数组的长度: ");
    scanf("%d", &n);

    int arr[n];
    printf("请输入数组的元素: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("请输入要查找的目标数字: ");
    scanf("%d", &target);

    int result = sentinelSearch(arr, n, target);

    if (result == -1) {
        printf("未找到目标数字 %d", target);
    } else {
        printf("目标数字 %d 存在于数组的位置 %d", target, result);
    }

    return 0;
}
