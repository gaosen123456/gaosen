#include <stdio.h>

void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // 存储当前待插入的元素
        int left = 0; // 有序部分的起始位置
        int right = i - 1; // 有序部分的结束位置

        // 使用二分查找找到插入位置
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > key) {
                right = mid - 1; // 待插入元素应该在左半部分
            } else {
                left = mid + 1; // 待插入元素应该在右半部分
            }
        }

        // 将插入位置之后的元素右移
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }

        // 将元素插入到正确的位置
        arr[left] = key;
    }
}

int main() {
    int n;
    printf("请输入要排序的数字个数：");
    scanf("%d", &n);
    
    int arr[n];
    printf("请输入%d个数字：", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    binaryInsertionSort(arr, n);

    printf("排序后的数组：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
