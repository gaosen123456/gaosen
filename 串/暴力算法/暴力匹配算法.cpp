

#include <stdio.h>
#include <string.h>

int search(char *text, char *pattern) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);

    for (int i = 0; i <= text_len - pattern_len; i++) {
        int j;
        for (j = 0; j < pattern_len; j++) {
            if (text[i+j] != pattern[j]) {
                break;
            }
        }
        if (j == pattern_len) {
            return i;
        }
    }
    return -1;
}

int main() {
    char text[] = "Hello,world!";
    char pattern[] = "world";
    int pos = search(text, pattern);
    if (pos == -1) {
        printf("Pattern not found.\n");
    } else {
        printf("Pattern found at position %d.\n", pos);
    }
    return 0;
}





