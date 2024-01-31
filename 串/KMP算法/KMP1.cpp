#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

typedef struct {
    char ch[MAXSIZE];
    int length;
} SString;

// 计算模式串的 Next 数组
void getNext(SString T, int *next) {
    int i = 0, j = -1;
    
    // 初始条件
    next[0] = -1;

    while (i < T.length) {
        // 如果 j = -1 或当前字符匹配成功（即 T.ch[i] == T.ch[j]）
        if (j == -1 || T.ch[i] == T.ch[j]) {
            // 继续比较下一个字符
            ++i;
            ++j;

            // 修改 Next 数组的值
            // 如果当前字符和下一个字符相等，说明匹配失败，需要特殊处理
            if (T.ch[i] == T.ch[j]) {
                next[i] = next[j];
            } else {
                next[i] = j;
            }
        } else {
            // 当前字符和下一个字符匹配失败，回溯 j 的位置
            j = next[j];
        }
    }
}

// 使用 KMP 算法在主串中查找模式串的索引
int KMPIndex(SString S, SString T) {
    int i = 0, j = 0;
    int next[MAXSIZE];

    // 构建模式串 T 的 Next 数组
    getNext(T, next);

    while (i < S.length && j < T.length) {
        // 如果 j = -1 或当前字符匹配成功（即 S.ch[i] == T.ch[j]）
        if (j == -1 || S.ch[i] == T.ch[j]) {
            // 继续比较下一个字符
            ++i;
            ++j;
        } else {
            // 当前字符和下一个字符匹配失败，回溯 j 的位置
            j = next[j];
        }
    }

    // 如果 j 等于模式串 T 的长度，说明匹配成功，返回匹配的起始位置
    if (j == T.length) {
        return i - j;
    } else {
        // 匹配失败，返回 -1
        return -1;
    }
}

int main() {
    SString S, T;

    printf("请输入主串 S：");
    scanf("%s", S.ch);

    printf("请输入模式串 T：");
    scanf("%s", T.ch);

    // 获取主串和模式串的长度
    S.length = strlen(S.ch);
    T.length = strlen(T.ch);

    // 使用 KMP 算法查找模式串在主串中的索引
    int result = KMPIndex(S, T);

    if (result != -1) {
        printf("模式串 T 在主串 S 中首次出现的位置为：%d\n", result);
    } else {
        printf("模式串 T 在主串 S 中未找到匹配\n");
    }

    return 0;
}
