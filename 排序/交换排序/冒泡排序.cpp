#include <stdio.h>

// ð��������
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int flag; // ���ڱ�־�Ƿ��з�������

    // ���ѭ�����ƱȽ�����
    for (i = 0; i < n - 1; i++) {
        flag = 0; // ��ʼ��־λΪ0

        // �ڲ�ѭ�����������Ƚ�
        for (j = 0; j < n - i - 1; j++) {
            // ���ǰ���Ԫ�ش��ں����Ԫ�أ����н���
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1; // ��־��Ϊ1��ʾ��������
            }
        }

        // �����־λ��ȻΪ0����ʾ�Ѿ�������ǰ��������
        if (flag == 0) {
            break;
        }
    }
}

int main() {
    int n;
    printf("������Ҫ��������ָ�����");
    scanf("%d", &n);

    int arr[n];
    printf("������%d�����֣�", n);

    // ����Ҫ���������
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // ����ð���������������������
    bubbleSort(arr, n);

    printf("���������飺");
    // �������������
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
