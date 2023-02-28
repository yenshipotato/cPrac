#include<iostream>
using namespace std;

class Father{
public:	
	Father(){
		cout<<"a";
	}
	~Father(){
		cout<<"b";
	}
};

class Son : public Father{
public:
	Son(){
		cout<<"c";
	}
	~Son(){
		cout<<"d";
	}
};

int main(){
	Son son;
	system("pause");
	return 0;
	
}
