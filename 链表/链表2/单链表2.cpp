#include<stdio.h>
#include<windows.h>
 
struct Node{
	int data;
	struct Node   *p;
}; 
//struct Node a,b,c,d;
 
int main(){
	struct Node  *p1,*head,*tail; 
	head=p1=(struct Node*)malloc(sizeof(struct Node));//p1ָֻ���һ����� 
	int N,i=1;
	while(i<=N){
		
		tail=(struct Node*)malloc(sizeof(struct Node));
		scanf("%d",&p1->data);
		p1->p=tail;
		p1=tail;
		i++; 
		//p2   ָֻ������ 
	} 
	scanf("%d",&p1->data);
	tail->p=NULL;
	
	//���
	struct Node *ph; 
	ph=head;
	while(ph!=NULL){
		printf("%d",ph->data);
		ph=ph->p;
	}
	
	
	return 0;
}
