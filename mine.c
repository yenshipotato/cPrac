#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Nmax 30 

void init(int gridSize,int *mines,int mineNum,int *usermines);
int minenum(int gridSize,int *mines ,int I,int J);
void prt_mine(int *mines,int gridSize,int *usermines);
int mining(int gridSize,int *mines,int *usermines,int i,int j);
void expand(int gridSize,int *mines,int *usermines,int i,int j);
int flag(int *usermines,int gridSize);


int main(int argc,char* argv[]){

	int gridSize=atoi(argv[1]),mineNum=atoi(argv[2]);
	if(gridSize>30){
		printf("error\n");
		return 0;
	}

	int *mines=malloc(1024*sizeof(int)),*usermines=malloc(gridSize*gridSize*sizeof(int)),guessI,guessJ;
	init(gridSize,mines,mineNum,usermines);


	while(1){
		prt_mine(mines,gridSize,usermines);
		scanf("%d %d",&guessI,&guessJ);
		if(*(usermines+guessI*gridSize+guessJ)==1){
			system("clear");
			printf("You've mined %d %d\n",guessI,guessJ);
			continue;
		}
		if(mining(gridSize,mines,usermines,guessI,guessJ)){
			break;
		}
		if(flag(usermines,gridSize)==mineNum){
			system("clear");
			prt_mine(mines,gridSize,usermines);
			printf("You are win!\n");
			break;
		}
		system("clear");
		
	}


	return 0;
} 

void init(int gridSize,int *mines,int mineNum,int *usermines){
	srand(time(NULL));
	int minecount;

	for(int i=1;i<=gridSize;i++){
		for(int j=1;j<=gridSize;j++){
			*(mines+i*32+j)=0;
			*(usermines+(i-1)*gridSize+(j-1))=0;
		
		}
	}
	

	while(mineNum>0){
		for(int i=1;i<=gridSize;i++){
			if(mineNum==0)break;
			for(int j=1;j<=gridSize;j++){
				if(mineNum==0)break;
				if((*(mines+i*32+j))!=-1&&rand()%(2*gridSize)==1){
					*(mines+i*32+j)=-1;
					mineNum--;
				}
			}
		}
	}

	for(int i=1;i<=gridSize;i++){
		for(int j=1;j<=gridSize;j++){

			if(*(mines+i*32+j)!=-1){
				*(mines+i*32+j)=minenum(gridSize,mines,i,j);
			}
			else continue;
		
		}
	}


}

int minenum(int gridSize,int *mines ,int I,int J){
	int count=0;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(*(mines+(I+i)*32+j+J)==-1){
				count++;
			}
		}
	}

	return count;
}

void prt_mine(int *mines,int gridSize,int *usermines){
	for(int i=1;i<=gridSize;i++){
		for(int j=1;j<=gridSize;j++){
			if(*(usermines+(i-1)*gridSize+(j-1))==0)printf("? ");

			else
				if(*(mines+i*32+j)!=0)printf("%d ",*(mines+i*32+j));
				else printf("_ ");
		}
		printf("\n");
	}
	printf("\n\n");

}

int mining(int gridSize,int *mines,int *usermines,int i,int j){
	if(*(mines+(i+1)*32+j+1)==-1){
		printf("You are dead!\n");
		return 1;
	}
	else{
		
		*(usermines+i*gridSize+j)=1;

		if(*(mines+(i+1)*32+j+1)==0){
			
			expand(gridSize,mines,usermines,i,j);
		}
		return 0;
		
	}

}

void expand(int gridSize,int *mines,int *usermines,int i,int j){
	if(i>=gridSize||j>=gridSize||i<0||j<0){
		return;
	}

	if(*(mines+(i+1)*32+j+1)!=0){
		if(*(mines+(i+1)*32+j+1)==-1)return;
		else{
			*(usermines+i*gridSize+j)=1;
			return;
		}
	}

	else{
		*(usermines+i*gridSize+j)=1;

		for(int k=-1;k<=1;k++){
			for(int l=-1;l<=1;l++){
				if(*(usermines+(i+k)*gridSize+(j+l))==0)
				expand(gridSize,mines,usermines,i+k,j+l);
			}
		}
	}
}

int flag(int *usermines,int gridSize){
	int count=0;
	for(int i=0;i<gridSize;i++){
		for(int j=0;j<gridSize;j++){
			if(*(usermines+i*gridSize+j)==0)count++;
		}
	}
	return count;
}
