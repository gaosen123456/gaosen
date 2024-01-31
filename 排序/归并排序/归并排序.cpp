#include <stdio.h>

// 归并两个有序子数组
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;  // 左子数组的长度
    int n2 = right - mid;     // 右子数组的长度

    // 创建临时数组来存储左右子数组的值
    int L[n1], R[n2];

    // 将数据拷贝到临时数组
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];  // 拷贝左子数组到临时数组 L
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];  // 拷贝右子数组到临时数组 R
    }

    // 归并两个临时数组到原数组
    i = 0;  // 初始化左子数组的索引
    j = 0;  // 初始化右子数组的索引
    k = left;  // 初始化归并后数组的索引
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];  // 将较小的元素放入原数组
            i++;
        }
        else {
            arr[k] = R[j];  // 将较小的元素放入原数组
            j++;
        }
        k++;
    }

    // 将剩余元素拷贝到原数组
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // 计算中间索引

        // 递归地对左右子数组进行归并排序
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 归并两个子数组
        merge(arr, left, mid, right);
    }
}

// 打印数组元素
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("请输入数组长度: ");
    scanf("%d", &n);

    int arr[n];

    printf("请输入数组元素:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);  // 调用归并排序函数

    printf("排序后的数组：\n");
    printArray(arr, n);

    return 0;
}

