#include<stdio.h>
//������Ľڵ�     ͨ���ṹ����й���   ���������ݣ�   ָ���򣨵�ַ�� 
 
struct Node{
	int data;
	struct Node   *p;
}; 
struct Node a,b,c,d;
 
int main(){
	//4�������ָ������ 
	a.p=&b;
	b.p=&c;
	c.p=&d;
	d.p=NULL; 
	//4����㸳ֵ 
	a.data=2;	
	b.data=4;
	c.data=7;
	d.data=89;
	//���� 
	struct Node  e;
	e.data=88;
	//����Ĺؼ����� 
	c.p=&e;
	e.p=&d;
	//ɾ��
	c.p=&d;
	e.p=NULL; 
	
	
	return 0;
}
