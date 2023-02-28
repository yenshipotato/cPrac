#include<iostream>
#include<cstdlib>
#include<conio.h> 
using namespace std;

int main(){
	while(int ch=getch()){
		switch(ch){
      		case 0xE0:
         		switch(ch=getch()){
            		case 72:  system("cls");printf("UP\n"); break;
            		case 80:  system("cls");printf("DOWN\n"); break;
            		case 75:  system("cls");printf("LEFT\n"); break;
            		case 77:  system("cls");printf("RIGHT\n"); break;
            			default:break;
         		}
         	break;
      	
		  		default:system("cls");printf("%c\n",ch); break;
      }
      
    
	}
	
	return 0;
	
}
