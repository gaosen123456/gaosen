#include <stdio.h>
#include <string.h>
struct students{
	char name[20];
	int ticket;
	
	}
	peo[3]={"�",0,"С��",0,"С��",0};

int main(){
	char name_1[20];
	for(int i=0;i<10;i++){
		printf("��ͶƱ��");
		scanf("%s",name_1);
		for(int j=0;j<3;j++){
			if(strcmp(name_1,peo[j].name)==0){
				peo[j].ticket++;
			}
		} 
	}
	printf("����ͶƱ���Ϊ��\n");
	for(int j=0;j<3;j++){
		printf("������%s,Ʊ����%d\n",peo[j].name,peo[j].ticket);
	}
	return 0;
}

