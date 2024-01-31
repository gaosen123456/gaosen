#include<stdio.h>
//单链表的节点     通过结构体进行构造   数据域（数据）   指针域（地址） 
 
struct Node{
	int data;
	struct Node   *p;
}; 
struct Node a,b,c,d;
 
int main(){
	//4个结点用指针连接 
	a.p=&b;
	b.p=&c;
	c.p=&d;
	d.p=NULL; 
	//4个结点赋值 
	a.data=2;	
	b.data=4;
	c.data=7;
	d.data=89;
	//插入 
	struct Node  e;
	e.data=88;
	//插入的关键代码 
	c.p=&e;
	e.p=&d;
	//删除
	c.p=&d;
	e.p=NULL; 
	
	
	return 0;
}
