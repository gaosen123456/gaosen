#include <stdio.h>
	struct q{
		int num;
		struct q *next;
	}a,b,c,d;
	struct q *p1;
	void bl(struct q *list){
		p1=list;
		while(p1!=NULL){
			printf("%d",p1->num);
			p1=p1->next;
		}
	}
	int main(){
		struct q *p2;
		p2=&d;
		a.num=2; 
		a.next=&c;
		b.num=3;
		b.next=NULL;
		c.num=4;
		c.next=NULL;
		d.num=5;
		d.next=&c;
		struct q *head;
		struct q *tail;
		head=&a;
		tail=&c;
		struct q *p1;
		p1=head;
		p2->next=p1->next;
		p1->next=p2;
		bl(head);
		return 0;
	}
