#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	int time_now=time(NULL),t1=time(NULL),timeD;
	cout<<"*****";
	while(1){
		
		if(time(NULL)!=t1){
			system("cls");
			t1=time(NULL);
			timeD=time(NULL)-time_now;
			if(timeD>20)time_now=time(NULL);
			for(register int i=0;i<timeD;i++){
				cout<<" ";
			}
			///ios_base::sync_with_stdio(false);
			cout<<"*****";
			
		}
		
	}
	return 0;
}
