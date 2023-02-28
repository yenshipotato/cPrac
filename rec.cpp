#include<bits/stdc++.h>
using namespace std;

int fn(int x);

int main(){
	
	fn(10);
	
	return 0;
}
int fn(int x){
	if(x==1)return x;
	else{
		cout<<fn(x-1)<<" ";
		return x;
	}
	
}
