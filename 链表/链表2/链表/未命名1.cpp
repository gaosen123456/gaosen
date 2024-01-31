#include <stdio.h>
#include <string.h>
struct students{
	char name[20];
	int ticket;
	
	}
	peo[3]={"李华",0,"小明",0,"小红",0};

int main(){
	char name_1[20];
	for(int i=0;i<10;i++){
		printf("请投票：");
		scanf("%s",name_1);
		for(int j=0;j<3;j++){
			if(strcmp(name_1,peo[j].name)==0){
				peo[j].ticket++;
			}
		} 
	}
	printf("最终投票结果为：\n");
	for(int j=0;j<3;j++){
		printf("姓名：%s,票数：%d\n",peo[j].name,peo[j].ticket);
	}
	return 0;
}

