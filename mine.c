#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Nmax 30 

void init(int N,int *mines,int M,int *usermines);
int minenum(int N,int *mines ,int I,int J);
void prt_mine(int *mines,int N,int *usermines);
int mining(int N,int *mines,int *usermines,int i,int j);
void expand(int N,int *mines,int *usermines,int i,int j);
int flag(int *usermines,int N);


int main(int argc,char* argv[]){

	int N=atoi(argv[1]),M=atoi(argv[2]);
	if(N>30){
		printf("error\n");
		return 0;
	}

	int *mines=malloc(1024*sizeof(int)),*usermines=malloc(N*N*sizeof(int)),guessI,guessJ;
	init(N,mines,M,usermines);


	while(1){
		prt_mine(mines,N,usermines);
		scanf("%d %d",&guessI,&guessJ);
		if(*(usermines+guessI*N+guessJ)==1){
			system("clear");
			printf("You've mined %d %d\n",guessI,guessJ);
			continue;
		}
		if(mining(N,mines,usermines,guessI,guessJ)){
			break;
		}
		if(flag(usermines,N)==M){
			system("clear");
			prt_mine(mines,N,usermines);
			printf("You are win!\n");
			break;
		}
		system("clear");
		
	}


	return 0;
} 

void init(int N,int *mines,int M,int *usermines){
	srand(time(NULL));
	int minecount;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			*(mines+i*32+j)=0;
			*(usermines+(i-1)*N+(j-1))=0;
		
		}
	}
	

	while(M>0){
		for(int i=1;i<=N;i++){
			if(M==0)break;
			for(int j=1;j<=N;j++){
				if(M==0)break;
				if((*(mines+i*32+j))!=-1&&rand()%(2*N)==1){
					*(mines+i*32+j)=-1;
					M--;
				}
			}
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){

			if(*(mines+i*32+j)!=-1){
				*(mines+i*32+j)=minenum(N,mines,i,j);
			}
			else continue;
		
		}
	}


}

int minenum(int N,int *mines ,int I,int J){
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

void prt_mine(int *mines,int N,int *usermines){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(*(usermines+(i-1)*N+(j-1))==0)printf("? ");

			else
				if(*(mines+i*32+j)!=0)printf("%d ",*(mines+i*32+j));
				else printf("_ ");
		}
		printf("\n");
	}
	printf("\n\n");

}

int mining(int N,int *mines,int *usermines,int i,int j){
	if(*(mines+(i+1)*32+j+1)==-1){
		printf("You are dead!\n");
		return 1;
	}
	else{
		
		*(usermines+i*N+j)=1;

		if(*(mines+(i+1)*32+j+1)==0){
			
			expand(N,mines,usermines,i,j);
		}
		return 0;
		
	}

}

void expand(int N,int *mines,int *usermines,int i,int j){
	if(i>=N||j>=N||i<0||j<0){
		return;
	}

	if(*(mines+(i+1)*32+j+1)!=0){
		if(*(mines+(i+1)*32+j+1)==-1)return;
		else{
			*(usermines+i*N+j)=1;
			return;
		}
	}

	else{
		*(usermines+i*N+j)=1;

		for(int k=-1;k<=1;k++){
			for(int l=-1;l<=1;l++){
				if(*(usermines+(i+k)*N+(j+l))==0)
				expand(N,mines,usermines,i+k,j+l);
			}
		}
	}
}

int flag(int *usermines,int N){
	int count=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(*(usermines+i*N+j)==0)count++;
		}
	}
	return count;
}