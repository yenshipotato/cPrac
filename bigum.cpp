#include<bits/stdc++.h>
using namespace std;

class bignum{
	int positive;
	int length;
	char num[32];
	
	public :
		bignum() : positive(1),length(0){
		}
		
		void input();
		void output();
		int getlen(){
			return length;
		}
		char* getnum(){
			return num;
		}
		
		void setnum(char* sumc){
			strcpy(num,sumc);
		}
		
		bignum operator+(bignum n1);
};

int main(){
	
	bignum n1,n2;
	n1.input();n2.input();
	(n1+n2).output();
	
	return 0;
} 

bignum bignum::operator+(bignum n1){
	bignum sum;int carry=0;char sumc[32];
	
	for(int i=0;i<30;i++){
			carry+=(num[i]-'0')+(*(n1.getnum()+i)-'0');
			sumc[i]=carry%10+'0';
			carry/=10;
	}
	
	sumc[30]=carry+'0';
	sumc[31]='\0';
	
	sum.setnum(sumc);
	
	return sum;
}

void bignum::input(){
	string n1;
	cin>>n1;
	
	for(int i=0;n1.length()>=i+1;i++){
		num[i]=n1[n1.length()-i-1];
		
		
	}
	for(int i=n1.length();i<31;i++){
		num[i]='0';
	}
}

void bignum::output(){
	for(int i=30;i>=0;i--){
		if(num[i]!='\0')cout<<num[i];
	}
	
}
