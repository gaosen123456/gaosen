#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

typedef struct {
    char ch[MAXSIZE];
    int length;
} SString;

// ����ģʽ���� Next ����
void getNext(SString T, int *next) {
    int i = 0, j = -1;
    
    // ��ʼ����
    next[0] = -1;

    while (i < T.length) {
        // ��� j = -1 ��ǰ�ַ�ƥ��ɹ����� T.ch[i] == T.ch[j]��
        if (j == -1 || T.ch[i] == T.ch[j]) {
            // �����Ƚ���һ���ַ�
            ++i;
            ++j;

            // �޸� Next �����ֵ
            // �����ǰ�ַ�����һ���ַ���ȣ�˵��ƥ��ʧ�ܣ���Ҫ���⴦��
            if (T.ch[i] == T.ch[j]) {
                next[i] = next[j];
            } else {
                next[i] = j;
            }
        } else {
            // ��ǰ�ַ�����һ���ַ�ƥ��ʧ�ܣ����� j ��λ��
            j = next[j];
        }
    }
}

// ʹ�� KMP �㷨�������в���ģʽ��������
int KMPIndex(SString S, SString T) {
    int i = 0, j = 0;
    int next[MAXSIZE];

    // ����ģʽ�� T �� Next ����
    getNext(T, next);

    while (i < S.length && j < T.length) {
        // ��� j = -1 ��ǰ�ַ�ƥ��ɹ����� S.ch[i] == T.ch[j]��
        if (j == -1 || S.ch[i] == T.ch[j]) {
            // �����Ƚ���һ���ַ�
            ++i;
            ++j;
        } else {
            // ��ǰ�ַ�����һ���ַ�ƥ��ʧ�ܣ����� j ��λ��
            j = next[j];
        }
    }

    // ��� j ����ģʽ�� T �ĳ��ȣ�˵��ƥ��ɹ�������ƥ�����ʼλ��
    if (j == T.length) {
        return i - j;
    } else {
        // ƥ��ʧ�ܣ����� -1
        return -1;
    }
}

int main() {
    SString S, T;

    printf("���������� S��");
    scanf("%s", S.ch);

    printf("������ģʽ�� T��");
    scanf("%s", T.ch);

    // ��ȡ������ģʽ���ĳ���
    S.length = strlen(S.ch);
    T.length = strlen(T.ch);

    // ʹ�� KMP �㷨����ģʽ���������е�����
    int result = KMPIndex(S, T);

    if (result != -1) {
        printf("ģʽ�� T ������ S ���״γ��ֵ�λ��Ϊ��%d\n", result);
    } else {
        printf("ģʽ�� T ������ S ��δ�ҵ�ƥ��\n");
    }

    return 0;
}
