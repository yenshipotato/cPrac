#include<iostream>
#include<cmath>
#define STU_NUM 40722083
using namespace std;

bool is_prime(int n){
	int l=sqrt(n),count=0;
	for(int i=2;i<=l;i++){
		if(n%i==0)count++;
	}
	if(count==0)return true;
	else return false;
}

int main(){
	int num=STU_NUM;
	while(1){
		if(is_prime(num))break;
		else num++;
	}
	cout<<num<<"\n";
	return 0;
} 
