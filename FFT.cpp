#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define Pi 3.14159265359
using namespace std;

class Complex{

public:
	Complex(){}
	Complex(double nR,double nI):x(nR),y(nI){
	}
	void output(){
		cout<<x;
		if(y<0){
			cout<<" - "<<abs(y)<<"i\n";
		}
		else{
			cout<<" + "<<y<<"i\n";
		}
	}
	double x;
	double y;
	Complex operator *(Complex CPX1);
	Complex operator +(Complex CPX1);
	Complex operator -(Complex CPX1);
}; 
void FFT(Complex a[],int len);
void IFFT(Complex a[],int len);
int bin(int num);
int posPosi(int num,int len);

int main(){
	int L;
	cin>>L;
	double *real=new double[L];Complex a[L];
	//-----------------------------------------------------------------------------------------------
	for(int i=0;i<L;i++){
		cin>>real[i];
	}
	//-----------------------------------------------------------------------------------------------
	for(int i=0;i<L;i++){
		a[i]=Complex(real[i],0);
	}
	//-----------------------------------------------------------------------------------------------
	FFT(a,L);
	cout<<"\nAfter FFT\n\n";
	for(int i=0;i<L;i++){
		a[i].output();
	}
	//-----------------------------------------------------------------------------------------------
	IFFT(a,L);
	cout<<endl;
	for(int i=0;i<L;i++){
		cout<<a[i].x<<endl;
	}
	//-----------------------------------------------------------------------------------------------
	
	return 0;
}


int bin(int num){
	int a[32],bi=0;
	for(int i=0;i<31;i++){
		a[i]=num%2;
		num/=2;
	}
	for(int i=31;i>=0;i--){
		bi+=a[i]*pow(10,i);
	}
	return bi;
}
int posPosi(int num,int len){
	len=log(len)/log(2);
	int a[len],bi=0;
	for(int i=len-1;i>=0;i--){
		a[i]=num%10;
		num/=10;
	}
	for(int i=len-1;i>=0;i--){
		bi+=a[i]*pow(2,i);
	}
	return bi;
}


void FFT(Complex* a,int len){
    if(len==1) return;
    Complex* a0=new Complex[len/2];
    Complex* a1=new Complex[len/2];
    
    for(int i=0;i<len;i+=2){
        a0[i/2]=a[i];
        a1[i/2]=a[i+1];
    }
    
    FFT(a0,len/2);FFT(a1,len/2);
    
    Complex wn(cos(2*Pi/len),sin(-2*Pi/len));
    Complex w(1,0);
    
    for(int i=0;i<(len/2);i++){
        a[i]=a0[i]+w*a1[i];
        a[i+len/2]=a0[i]-w*a1[i];
        w=w*wn;
    }
    
    return;
}
void IFFT(Complex* a,int len){
	
    int *pos=new int [len];
    
    for(int i=0;i<len;i++){
    	pos[i]=bin(i);
    	pos[i]=posPosi(pos[i],len);
	}
	cout<<endl;
	for(int i=0;i<len;i++)
        if(i<pos[i])
            swap(a[i],a[pos[i]]);
    for(int i=2,mid=1;i<=len;i<<=1,mid<<=1){
        Complex wm(cos(2.0*Pi/i),sin(2.0*Pi/i));
        for(int j=0;j<len;j+=i){
            Complex w(1,0);
            for(int k=j;k<j+mid;k++,w=w*wm){
                Complex l=a[k],r=w*a[k+mid];
                a[k]=l+r;a[k+mid]=l-r;
            }
        }
    }
    for(int i=0;i<len;i++){
	
            a[i].x/=len;
	}
	delete []pos;
    return;
}


Complex Complex::operator *(Complex CPX1){
	return Complex(x*CPX1.x-y*CPX1.y,x*CPX1.y+y*CPX1.x);
}
Complex Complex::operator +(Complex CPX1){
	return Complex(x+CPX1.x,y+CPX1.y);
}
Complex Complex::operator -(Complex CPX1){
	return Complex(x-CPX1.x,y-CPX1.y);
}
