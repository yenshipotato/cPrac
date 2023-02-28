#include<iostream>
#include<cstdlib>
using namespace std;

template <class T>
void swap1(T& t1,T& t2){
	T temp;
	temp=t1;
	t1=t2;
	t2=temp;
} 

int main(){
	int n1=12,n2=13;
	char a1='A',a2='B';
	double d1=1.55,d2=2.16;
	
	swap1(n1,n2);
	swap1(a1,a2);
	swap1(d1,d2);
	
	cout<<n1<<" "<<n2<<"\n"<<a1<<" "<<a2<<"\n"<<d1<<" "<<d2<<"\n";
}
