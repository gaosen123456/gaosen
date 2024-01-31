#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(student)
typedef struct student{
    int num;
    float score;
    struct student *next;
}student;
student *create(){
	student *head;
	student *p1,*p2;
	int n=0;
	p1=p2=(student*)malloc(LEN);
	scanf("%ld,%f",&p1->num,&p1->score);
	head=NULL;
	while(p1->num!=0){
		n=n+1;
		if(n==1){
			head=p1;
		}
		else{
			p2->next=p1;
		}
		p2=p1;
		p1=(student*)malloc(LEN);
		scanf("%d,%f",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return head;
}
int main(){
	student *p;
	p=create();
	do{
		printf("Ñ§ºÅ£º%d³É¼¨£º%.1f\n",p->num,p->score);
		p=p->next;
	}
	while(p!=NULL);
}
