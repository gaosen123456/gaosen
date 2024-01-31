#include <stdio.h>

// 合并两个有序数组
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    
    // 比较左右两个数组的元素，将较小的元素放入原数组中
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++]; // 将左数组的元素放入原数组中，并移动左数组和原数组的指针
        } else {
            arr[k++] = right[j++]; // 将右数组的元素放入原数组中，并移动右数组和原数组的指针
        }
    }
    
    // 将剩余的元素放入原数组中
    while (i < leftSize) {
        arr[k++] = left[i++]; // 将左数组剩余的元素放入原数组中
    }
    while (j < rightSize) {
        arr[k++] = right[j++]; // 将右数组剩余的元素放入原数组中
    }
}

// 归并排序
void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return; // 如果数组长度小于等于1，无需排序
    }
    
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    
    // 将原数组分为两个子数组
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i]; // 将原数组的前半部分放入左数组
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i]; // 将原数组的后半部分放入右数组
    }
    
    // 递归地对两个子数组进行排序
    mergeSort(left, mid); // 对左数组进行归并排序
    mergeSort(right, size - mid); // 对右数组进行归并排序
    
    // 合并两个有序子数组
    merge(arr, left, mid, right, size - mid); // 将左右两个有序数组合并到原数组中
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // 逐个读取用户输入的数组元素
    }
   
    mergeSort(arr, size); // 对数组进行归并排序
    
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // 打印排序后的数组
    }
    printf("\n");
    
    return 0;
}
