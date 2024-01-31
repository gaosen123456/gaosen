 //�����е������Ա�b���������Ա�a�е�����Ԫ�ز��뵽a��
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
typedef int ElemType;
 
 
/*���Ա�ĵ�����洢�ṹ */ 
typedef struct LNode{
	ElemType       data;	
	struct LNode  *next;
}LNode, *LinkList;
 
/*��ʼ������*/
void InitList_L(LinkList &L)
{
	LinkList p,pre;
	L = (LinkList)malloc(sizeof(LNode));
	pre = L; 		//��ǰָ�� 
	while (true)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		if (p->data == 0)	//����Ԫ��Ϊ0������ѭ�� 
		{
			free(p);	//�ͷ������ɵĽ�� 
			break; 
		}	
		pre->next = p; 
		p->next = NULL;
		pre = pre->next;	//��ǰָ�����	
	}
}
 
/*�鲢*/
void MergeList_L(LinkList &La,LinkList &Lb)
{
	LinkList pa,pb,q;	 
	pa = La;	//��ǰָ��
	pb = Lb;
	while (pa->next != NULL){
		while (pb->next != NULL){
			if (pa->next->data == pb->next->data){	//����Ԫ����ͬ��ɾ�� 
				 q = (LinkList)malloc(sizeof(LNode));
				 q = pb->next;
				 pb->next = q->next;
				 free(q);
			}
			else{
				pb = pb->next;	//��ǰָ�����
			}
		}
		pa = pa->next;
		pb = Lb;				//����ָ��ͷ��� 
	}
	pa->next = Lb->next; 		//��Lb��ϲ���La���� 
	free(Lb);					//�ͷ�Lbͷ��� 
}
 
 
/*�����������*/
void OutputList_L(LinkList &L){
	LinkList pre;
	pre = L;		//��ǰָ�� 
	while (pre->next != NULL)
	{
		pre = pre->next;
		printf("%d ",pre->data);
	}
	printf("\n");
}
 
int main()
{
	LinkList La,Lb;	
	InitList_L(La);   
	InitList_L(Lb);   
	MergeList_L(La,Lb);	//�鲢
 	OutputList_L(La);
	return 0;
}

