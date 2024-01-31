#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

// 定义静态串结构
typedef struct {
    char ch[MAXSIZE]; // 字符数组，用于存储串的字符
    int length; // 串的长度
} SString;

// 构建模式串的Next数组
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

// 实现KMP算法的串匹配函数
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
        return i - T.length; // 匹配成功，返回模式串在主串中的起始位置
    } else {
        return 0; // 匹配失败，返回0
    }
}

int main() {
    SString S, T; // 声明主串 S 和模式串 T

    printf("请输入主串 S：");
    scanf("%s", S.ch + 1); // 从标准输入读取主串内容，注意+1是为了跳过数组第一个位置，从下标1开始存储

    printf("请输入模式串 T：");
    scanf("%s", T.ch + 1); // 从标准输入读取模式串内容，同样+1是为了从下标1开始存储

    S.length = strlen(S.ch + 1); // 计算主串的长度，注意同样要+1以忽略数组第一个位置
    T.length = strlen(T.ch + 1); // 计算模式串的长度

    int result = KMPIndex(S, T); // 调用KMP算法匹配函数，查找模式串在主串中的位置

    if (result) {
        printf("模式串 T 在主串 S 中首次出现的位置为：%d\n", result); // 输出匹配位置
    } else {
        printf("模式串 T 在主串 S 中未找到匹配\n"); // 输出未找到匹配
    }

    return 0;
}
