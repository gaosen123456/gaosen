#include <stdio.h>

void insertionSort(int a[], int n) {
    int i, j;
/*
    // 使用插入排序算法对整数数组arr中的n个元素进行排序
    for (i = 2; i <= n; i++) {
        arr[0] = arr[i];  // 设置哨兵
        j = i - 1;

        // 将当前元素(arr[0])与已排序部分的元素比较并插入到正确的位置
        while (arr[j] > arr[0]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = arr[0]; // 插入arr[0]到正确的位置
    }
*/
	for(i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			a[0]=a[i];
			for(j=i-1;a[0]<a[j];--j){
				a[j+1]=a[j];
			}
			a[j+1]=a[0];
		}
	} 
}

int main() {
    int n;
    printf("请输入要排序的数字个数：");
    scanf("%d", &n);
    
    int a[100];
    printf("请输入%d个数字：", n);
    
    // 读取用户输入的n个整数到数组arr中
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // 调用插入排序函数对数组arr进行排序
    insertionSort(a, n);

    // 打印排序后的数组
    printf("排序后的数组：\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

