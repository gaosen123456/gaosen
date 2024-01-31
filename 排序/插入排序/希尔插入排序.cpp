#include <stdio.h>

void shellSort(int arr[], int n) {
    // 初始步长为数组长度的一半，每次循环步长减半
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 从步长开始，依次将每一个元素与前面同一步长的元素比较
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // 存储当前需要插入的元素
            int j;

            // 向前遍历，与之前的元素依次比较，并将较大的元素往后移动
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; // 向后移动
            }
            arr[j] = temp; // 将当前元素插入到正确的位置
        }
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

    shellSort(arr, n); // 使用希尔排序进行数组排序

    printf("排序后的数组：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // 打印排序后的数组
    }
    printf("\n");

    return 0;
}
