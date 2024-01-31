#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct{
	ElemType * elem;
	int TableLen;
}SSTable;
 
void ST_Init(SSTable &ST,int len){
	ST.TableLen=len+1;
	ST.elem=(ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));
	for(i=1;i<ST.TableLen;i++){
		ST.elem[i]=rand()%100;
	} 
}
void ST_print(SSTable ST)
{
	int i;
	for(i=1;i<ST.TableLen;i++){
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
 } 
int Search_Seq(SSTable ST,ElemType key){
	ST.elem[0]=key;
	int i;
	for(i=ST.TableLen-1;ST.elem[i]!=key;i--);
	return i;
}

int main()
{
	SSTable ST;
	ST_Init(ST,10);
	ST_print(ST) ; 
	ElemType key;
	printf("查询元素：\n");
	scanf("%d",&key);
	int pos;
	pos=Search_Seq(ST,key); 
	if(pos)
	{
		printf("发现元素，位置是%d\n",pos);
	}
	else{
		printf("无\n");
	}
	return 0;
}
