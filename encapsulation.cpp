#include<iostream>
using namespace std;

class slut{
	
	string name;
	int sn;
	
	public:
		string get_name(){
			return name;
		}
		int get_sn(){
			return sn;
		}
		void set_name(string name1){
			name=name1;
		}
		void set_sn(int sn1){
			sn=sn1;
		}
};



int main(){
	slut n[2];
	n[0].set_name("NIGHTMARE");
	n[0].set_sn(75844);
	n[1].set_name("POTATO");
	n[1].set_sn(96931);
	for(int i=0;i<2;i++){
		cout<<n[i].get_name()<<" : "<<n[i].get_sn()<<"\n";
	}
	return 0;
}






