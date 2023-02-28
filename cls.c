#include<stdio.h>
#include<stdlib.h> 


int main(){
	int m;
	while(1){
		printf("\nGuess: ");
		if(scanf("%d",&m)!=EOF){
			system("cls");
			printf("%d",m);
		}
		else{
			break;
		}
	}
	
}
