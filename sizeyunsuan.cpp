/*2016.3.6.WeiLiHua*/
#include<iostream>
#include<ctime>
using namespace std;
void main()
{
	int sj1,sj2,sf=1,sj3,sj4,r;
	srand((unsigned)time(NULL));
	for(int i=0;i<15;i++)
	{
            sj1=rand()%100;
			sj2=rand()%100+1;
			sj3=rand()%100+1;
			sj4=rand()%100+1;
			sf=i%4; 
			switch(sf)
				{
					case 0:
                    cout<<sj1<<"+"<<sj2<<"="<<endl;
					if(sj1>sj3){r=sj1;sj1=sj3;sj3=r;}
					if(sj2>sj4){r=sj2;sj2=sj4;sj4=r;}
					cout<<sj1<<"/"<<sj3<<"+"<<sj2<<"/"<<sj4<<"="<<endl;
                    break;
                    case 1:
                    if(sj1<sj2){r=sj1;sj1=sj2;sj2=r;};
                    cout<<sj1<<"-"<<sj2<<"="<<endl;
					if(sj1>sj3){r=sj1;sj1=sj3;sj3=r;}
					if(sj2>sj4){r=sj2;sj2=sj4;sj4=r;}
					cout<<sj1<<"/"<<sj3<<"-"<<sj2<<"/"<<sj4<<"="<<endl;
                    break;
                   case 2:
                   cout<<sj1<<"*"<<sj2<<"="<<endl;
				   if(sj1>sj3){r=sj1;sj1=sj3;sj3=r;}
					if(sj2>sj4){r=sj2;sj2=sj4;sj4=r;}
					cout<<sj1<<"/"<<sj3<<"*"<<sj2<<"/"<<sj4<<"="<<endl;
                   break;
                   case 3:
                   cout<<sj1<<"/"<<sj2<<"="<<endl;
				   if(sj1>sj3){r=sj1;sj1=sj3;sj3=r;}
					if(sj2>sj4){r=sj2;sj2=sj4;sj4=r;}
					cout<<sj1<<"/"<<sj3<<"/"<<sj2<<"/"<<sj4<<"="<<endl;
				   break;
                   default:
                   break;
				}


	}
}