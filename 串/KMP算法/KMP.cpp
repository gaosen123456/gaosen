#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

// ���徲̬���ṹ
typedef struct {
    char ch[MAXSIZE]; // �ַ����飬���ڴ洢�����ַ�
    int length; // ���ĳ���
} SString;

// ����ģʽ����Next����
void getNext(SString T, int *next) {
    int i = 1, j = 0;
    next[1] = 0;

    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

// ʵ��KMP�㷨�Ĵ�ƥ�亯��
int KMPIndex(SString S, SString T) {
    int i = 1, j = 1;
    int next[MAXSIZE];

    getNext(T, next);

    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > T.length) {
        return i - T.length; // ƥ��ɹ�������ģʽ���������е���ʼλ��
    } else {
        return 0; // ƥ��ʧ�ܣ�����0
    }
}

int main() {
    SString S, T; // �������� S ��ģʽ�� T

    printf("���������� S��");
    scanf("%s", S.ch + 1); // �ӱ�׼�����ȡ�������ݣ�ע��+1��Ϊ�����������һ��λ�ã����±�1��ʼ�洢

    printf("������ģʽ�� T��");
    scanf("%s", T.ch + 1); // �ӱ�׼�����ȡģʽ�����ݣ�ͬ��+1��Ϊ�˴��±�1��ʼ�洢

    S.length = strlen(S.ch + 1); // ���������ĳ��ȣ�ע��ͬ��Ҫ+1�Ժ��������һ��λ��
    T.length = strlen(T.ch + 1); // ����ģʽ���ĳ���

    int result = KMPIndex(S, T); // ����KMP�㷨ƥ�亯��������ģʽ���������е�λ��

    if (result) {
        printf("ģʽ�� T ������ S ���״γ��ֵ�λ��Ϊ��%d\n", result); // ���ƥ��λ��
    } else {
        printf("ģʽ�� T ������ S ��δ�ҵ�ƥ��\n"); // ���δ�ҵ�ƥ��
    }

    return 0;
}
