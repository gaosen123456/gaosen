#include <stdio.h>

// 获取数组中的最大值
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 使用计数排序对数组按照指定位数进行排序
void countSort(int arr[], int n, int exp) {
    int output[n]; // 临时数组保存排序结果
    int count[10] = {0}; // 存储0到9个数字的计数
    int i;

    // 统计出现的次数
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // 计算累加次数
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 构建临时数组，按照设定位数排序
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将临时数组拷贝到原数组
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 基数排序
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // 对每个位数进行计数排序
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
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

    radixSort(arr, n); // 基数排序

    printf("排序后的数组：\n");
    printArray(arr, n);

    return 0;
}
