#include <stdio.h>

// ��ȡ�����е����ֵ
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// ʹ�ü�����������鰴��ָ��λ����������
void countSort(int arr[], int n, int exp) {
    int output[n]; // ��ʱ���鱣��������
    int count[10] = {0}; // �洢0��9�����ֵļ���
    int i;

    // ͳ�Ƴ��ֵĴ���
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // �����ۼӴ���
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // ������ʱ���飬�����趨λ������
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // ����ʱ���鿽����ԭ����
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// ��������
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // ��ÿ��λ�����м�������
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

// ��ӡ����Ԫ��
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("���������鳤��: ");
    scanf("%d", &n);

    int arr[n];

    printf("����������Ԫ��:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n); // ��������

    printf("���������飺\n");
    printArray(arr, n);

    return 0;
}
