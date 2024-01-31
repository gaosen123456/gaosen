#include <stdio.h>

// 定义快速排序函数
void quicksort(int arr[], int low, int high) {
    // 数组中只有一个元素或者没有元素，不需要排序
    if (low >= high) {
        return;
    }
    // 设置左右指针
    int left = low, right = high;
    // 选择中间元素作为基准值
    int pivot = arr[(low + high) / 2];
    // 开始分区操作
    while (left <= right) {
        // 在左边找到一个比基准值大的元素
        while (arr[left] < pivot) {
            left++;
        }
        // 在右边找到一个比基准值小的元素
        while (arr[right] > pivot) {
            right--;
        }
        // 如果左指针仍在右指针的左边，则交换两个元素
        if (left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    // 递归调用
    quicksort(arr, low, right);
    quicksort(arr, left, high);
}

int main() {
    int n;
    printf("请输入要排序的数字个数：");
    scanf("%d", &n);
    
    int arr[n];
    printf("请输入要排序的数字：");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    quicksort(arr, 0, n - 1);
    printf("排序后的数组：\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

