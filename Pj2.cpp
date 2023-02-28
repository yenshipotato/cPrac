#include<bits/stdc++.h>
#define VELDIVIDE 500.0f
#define PI 3.14159265358979323846
using namespace std;

double base[4][2]={{360,680},{660,658},{330,350},{640,310}};
int entrance[2][36]={0,100,0,200,0,300,0,400,0,500,0,600,0,700,0,800,0,900,
						1000,100,1000,200,1000,300,1000,400,1000,500,1000,600,1000,700,1000,800,1000,900,
						100,1000,200,1000,300,1000,400,1000,500,1000,600,1000,700,1000,800,1000,900,1000,
						100,0,200,0,300,0,400,0,500,0,600,0,700,0,800,0,900,0};
class car{
private:
	int moveFlag=0;
	double Distance[4];
	const double vel=10.0/VELDIVIDE;
	double x,y;
	int direction;//(1 for R,2 for L,3 for U,4 for D)
	
public:
	car(int iniX,int iniY):x(iniX),y(iniY){
		
		if(iniX==0)direction=1;
		else if(iniX==1000)direction=2;
		else if(iniY=0)direction=3;
		else direction=4;
		calPower();

		currentBase=0;
		
		for (int i = 0; i < 4; ++i)if(Pb[i]>Pb[currentBase])currentBase=i;
	}

	void calDistance();
	void calPower();
	void move();
	void turn();
	
	void Handoff1();
    void Handoff2();
    void Handoff3();
    void Handoff4();
	
	void showInf(){
		cout<<x<<" "<<y<<" "<<direction<<" "<<currentBase<<" "<<isOut<<" "<<handoffCount<<"\n";
	}
	
	int currentBase;
	double Pb[4];
	int handoffCount=0;
	bool isOut=false;

};

void initial(vector<double> &arrivalTime);

int main(int argc, char const *argv[]){
    int HND;vector<double> arriv;vector<car> cars;
    long long power=0,carss=0;
    initial(arriv);

    for (int i = 0; i < 86400; i++)
    {
        HND=0;

        for (int j = 0; j < 1000; j++)
        {
            if(arriv[0]<=i+j/1000){
                int pos=rand()%36;
                arriv.erase(arriv.begin());
                car newcar(entrance[pos][0],entrance[pos][1]);
                cars.push_back(newcar);
            }

            if(j%(1000/(int)VELDIVIDE)==0){
                for (int k = 0; k < cars.size(); k++)
                {
                    if(!cars[k].isOut){
                        cars[k].move();
                        // power+=cars[k].Pb[cars[k].currentBase];
                        // carss++;
                    }
                    HND+=cars[k].handoffCount;
                }
                
            }
        }
        if ((i+1)%100==0)printf("%d : %lf\n",i+1,(double)HND/(i+1));
    }
    return 0;
}
void initial(vector<double> &arrivalTime){
	random_device rd; mt19937 generator( rd() );
	double lamb = 0.5;//0.5:28 0.33333 0.2

	exponential_distribution<double> timeGen(lamb);
	double totalTime=0;
	while(1){	
		totalTime+=timeGen(generator);
		if(totalTime>=86400)break;
		arrivalTime.push_back(totalTime);
	}
}

void car::calDistance(){
	for(int i=0;i<4;i++){
		Distance[i]=sqrt((x-base[i][0])*(x-base[i][0])+(y-base[i][1])*(y-base[i][1]));
	}
}

void car::calPower(){
	calDistance();
	for(int i=0;i<4;i++){
		Pb[i]=100.0-22-20*log10(Distance[i]);
	}
}

void car::move(){	
	switch(direction){
		case 1:
			x+=vel;
			break;
		case 2:
			x-=vel;
			break;
		case 3:
			y+=vel;
			break;
		case 4:
			y-=vel;
			break;
	}
	moveFlag+=vel;
	
	calPower();
	Handoff4();
	
	if(moveFlag>=100)turn();	
	
	if(x<=0||y<=0||x>=1000||y>=1000)isOut=true;	
}

void car::turn(){
	srand(time(0));
	
	int seed=rand()%5;
	
	if(direction<=2){
			if(seed<3);
			else if(seed==3)direction=3;
			else direction=4;
    }
    else{
        if(seed<3);
			else if(seed==3)direction=1;
			else direction=2;
    }
	
	moveFlag=0;
	
}

void car::Handoff1(){
	int flag=currentBase;
	
	for (int i = 0; i < 4; ++i)if(Pb[i]>=Pb[currentBase])currentBase=i;
	if(flag!=currentBase)handoffCount++;
}

void car::Handoff2(){
	int flag=currentBase;
	double th=20.8;
	for (int i = 0; i < 4; ++i)if(Pb[i]>=Pb[currentBase]&&Pb[currentBase]<th)currentBase=i;
	if(flag!=currentBase)handoffCount++;
}
void car::Handoff3(){
    int flag=currentBase;
	double en=6.1;
	for (int i = 0; i < 4; ++i)if(Pb[i]>=Pb[currentBase]+en)currentBase=i;
	if(flag!=currentBase)handoffCount++;
}
void car::Handoff4(){
    int flag=currentBase;
    double th=26.8;
	double en=6.1;
	for (int i = 0; i < 4; ++i)if(Pb[i]>=Pb[currentBase]+en&&Pb[currentBase]<th)currentBase=i;
	if(flag!=currentBase)handoffCount++;
}
