#include <stdio.h>

void shellSort(int arr[], int n) {
    // ��ʼ����Ϊ���鳤�ȵ�һ�룬ÿ��ѭ����������
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // �Ӳ�����ʼ�����ν�ÿһ��Ԫ����ǰ��ͬһ������Ԫ�رȽ�
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // �洢��ǰ��Ҫ�����Ԫ��
            int j;

            // ��ǰ��������֮ǰ��Ԫ�����αȽϣ������ϴ��Ԫ�������ƶ�
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; // ����ƶ�
            }
            arr[j] = temp; // ����ǰԪ�ز��뵽��ȷ��λ��
        }
    }
}

int main() {
    int n;
    printf("������Ҫ��������ָ�����");
    scanf("%d", &n);
    
    int arr[n];
    printf("������%d�����֣�", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    shellSort(arr, n); // ʹ��ϣ�����������������

    printf("���������飺");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // ��ӡ����������
    }
    printf("\n");

    return 0;
}
