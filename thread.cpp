#include<iostream>
#include<thread>

using namespace std;

int prt1(){
	for(int i=0;i<=100000;i++){
		cout<<i<<"\n";
	}
}
int prt2(){
	for(int j=0;j<=100000;j++){
		cout<<j<<"_\n";
	}
}


int main(){
	//ios_base::sync_with_stdio(false);
	thread t1(prt1),t2(prt2);
	t1.join();t2.join();
	//prt1();prt2();
	
	return 0;
} 
