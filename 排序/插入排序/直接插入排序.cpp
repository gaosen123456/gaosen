#include <stdio.h>

void insertionSort(int a[], int n) {
    int i, j;
/*
    // ʹ�ò��������㷨����������arr�е�n��Ԫ�ؽ�������
    for (i = 2; i <= n; i++) {
        arr[0] = arr[i];  // �����ڱ�
        j = i - 1;

        // ����ǰԪ��(arr[0])�������򲿷ֵ�Ԫ�رȽϲ����뵽��ȷ��λ��
        while (arr[j] > arr[0]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = arr[0]; // ����arr[0]����ȷ��λ��
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
    printf("������Ҫ��������ָ�����");
    scanf("%d", &n);
    
    int a[100];
    printf("������%d�����֣�", n);
    
    // ��ȡ�û������n������������arr��
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // ���ò���������������arr��������
    insertionSort(a, n);

    // ��ӡ����������
    printf("���������飺\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

