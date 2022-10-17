#include <stdio.h>
struct amazon{
	int regno;
	char name[100];
	int m1,m2,m3;
};
int classtopper(struct amazon *l);
int main(){
	struct amazon list[4];
	for(int i=0;i<4;i++){
		scanf("%d %s %d %d %d",&list[i].regno,&list[i].name,&list[i].m1,&list[i].m2,&list[i].m3);
	}
	classtopper(list);
	return 0;
}
int classtopper(struct amazon *l){
	int sum[4];
	for(int i=0;i<4;i++){
		sum[i]=(l+i)->m1+(l+i)->m2+(l+i)->m3;
		
	}
	int max=sum[0],stud;
	for(int j=0;j<4;j++){
		if(sum[j]>max){
			max=sum[j];
			stud=j;
		}
	}
	printf("%s student scored %d marks",(l+stud)->name,max);
	return 0;
}
