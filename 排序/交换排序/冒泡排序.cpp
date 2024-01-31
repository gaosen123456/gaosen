#include <stdio.h>

// 冒泡排序函数
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int flag; // 用于标志是否有发生交换

    // 外层循环控制比较轮数
    for (i = 0; i < n - 1; i++) {
        flag = 0; // 初始标志位为0

        // 内层循环进行两两比较
        for (j = 0; j < n - i - 1; j++) {
            // 如果前面的元素大于后面的元素，进行交换
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1; // 标志置为1表示发生交换
            }
        }

        // 如果标志位仍然为0，表示已经有序，提前结束排序
        if (flag == 0) {
            break;
        }
    }
}

int main() {
    int n;
    printf("请输入要排序的数字个数：");
    scanf("%d", &n);

    int arr[n];
    printf("请输入%d个数字：", n);

    // 输入要排序的数字
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 调用冒泡排序函数对数组进行排序
    bubbleSort(arr, n);

    printf("排序后的数组：");
    // 输出排序后的数组
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
