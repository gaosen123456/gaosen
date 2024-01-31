#include <malloc.h>
#include "stdio.h"

typedef struct ll {
    int Data;
    struct ll *next;
} *linklist, lnode;

lnode *p;

void inilist() {
    p = (lnode*) malloc(sizeof(lnode));
    p->next = NULL;
}

void prints() {
    lnode *l = p->next;
    while (l) {
        printf("%d ", l->Data);
        l = l->next;
    }
    printf("\n");
}

void cun() {
    int n;
    lnode *l = p, *r;
    printf("�����ڴ��С:");
    scanf("%d", &n);
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("�����%d��Ҫ������֣�",i+1);
        int x;
        scanf("%d", &x);
        r = (lnode *) malloc(sizeof(lnode));
        r->next = NULL;
        r->Data = x;
        l->next = r;
        l = l->next;
    }
    l->next = NULL;
}

void cha() {
    int n, num;
    printf("��Ҫ�ڵڼ������ֺ������,������λ�ú�����\n");
    scanf("%d %d", &n, &num);
    lnode *l = p;
    while (n--) {
        l = l->next;
    }
    lnode *r = (lnode *) malloc(sizeof(lnode));
    r->Data = num;
    r->next = l->next;
    l->next = r;
}

void del() {
    int n;
    printf("��Ҫɾ���ڼ�������\n");
    scanf("%d", &n);
    lnode *l = p;
    n--;
    while (n--) {
        l = l->next;
    }
    lnode *r = (lnode *) malloc(sizeof(lnode));
    r = l->next;
    l->next = r->next;
    free(r);
}

int main() {
    inilist();
    cun();
    prints();
    cha();
    prints();
    del();
    prints();
}
