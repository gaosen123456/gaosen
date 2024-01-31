 //将所有的在线性表b但不在线性表a中的数据元素插入到a中
#include<stdio.h>
#include<stdlib.h>
typedef int Status;
typedef int ElemType;
 
 
/*线性表的单链表存储结构 */ 
typedef struct LNode{
	ElemType       data;	
	struct LNode  *next;
}LNode, *LinkList;
 
/*初始化链表*/
void InitList_L(LinkList &L)
{
	LinkList p,pre;
	L = (LinkList)malloc(sizeof(LNode));
	pre = L; 		//当前指针 
	while (true)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		if (p->data == 0)	//数据元素为0，结束循环 
		{
			free(p);	//释放已生成的结点 
			break; 
		}	
		pre->next = p; 
		p->next = NULL;
		pre = pre->next;	//当前指针后移	
	}
}
 
/*归并*/
void MergeList_L(LinkList &La,LinkList &Lb)
{
	LinkList pa,pb,q;	 
	pa = La;	//当前指针
	pb = Lb;
	while (pa->next != NULL){
		while (pb->next != NULL){
			if (pa->next->data == pb->next->data){	//数据元素相同，删除 
				 q = (LinkList)malloc(sizeof(LNode));
				 q = pb->next;
				 pb->next = q->next;
				 free(q);
			}
			else{
				pb = pb->next;	//当前指针后移
			}
		}
		pa = pa->next;
		pb = Lb;				//重新指向头结点 
	}
	pa->next = Lb->next; 		//将Lb表合并到La表中 
	free(Lb);					//释放Lb头结点 
}
 
 
/*输出链表数据*/
void OutputList_L(LinkList &L){
	LinkList pre;
	pre = L;		//当前指针 
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
	MergeList_L(La,Lb);	//归并
 	OutputList_L(La);
	return 0;
}

