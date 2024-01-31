#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

// ���徲̬���ṹ
typedef struct {
    char ch[MAXSIZE]; // �ַ����飬���ڴ洢�����ַ�
    int length; // ���ĳ���
} SString;

// ʵ�ִ�ƥ��ĺ���
int Index(SString S, SString T) {
    int i = 1, j = 1; // i��j �ֱ�ָ��������ģʽ���ĵ�ǰ�ַ�λ��
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) { // �����ǰ�ַ�ƥ��
            ++i; // �����Ƚ���������һ���ַ�
            ++j; // �����Ƚ�ģʽ������һ���ַ�
        }
        else {
            i = i - j + 2; // �������ݵ��ϴ�ƥ��λ�õ���һ���ַ�����2��Ϊ�˱�������ѭ��
            j = 1; // ģʽ�����ݵ���ʼλ��
        }
    }
    if (j > T.length) {
        return i - T.length; // ƥ��ɹ�������ģʽ���������е���ʼλ��
    }
    else {
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

    int result = Index(S, T); // ����ƥ�亯��������ģʽ���������е�λ��

    if (result) {
        printf("ģʽ�� T ������ S ���״γ��ֵ�λ��Ϊ��%d\n", result); // ���ƥ��λ��
    }
    else {
        printf("ģʽ�� T ������ S ��δ�ҵ�ƥ��\n"); // ���δ�ҵ�ƥ��
    }

    return 0;
}

