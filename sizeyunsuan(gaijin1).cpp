/*2016.3.7.WeiLiHua�������㣬��ӡ30����*/
#include<iostream>
#include<ctime>
using namespace std;
void main()
{
	int sj1,sj2,sf=1,sj3,sj4,r;//��������������
	srand((unsigned)time(NULL)); //srand������������ϵͳʱ����Ϊʱ�����Ӳ��������
	for(int i=0;i<30;i++)
	{
            sj1=rand()%100;
			sj2=rand()%100+1;//�����ĸΪ0
			sj3=rand()%100+1;
			sj4=rand()%100+1;
			sf=rand()%8; 
			switch(sf)
				{
					 case 0:
                       cout<<sj1<<"+"<<sj2<<"="<<endl;
                     break;
                    case 1:
                       if(sj1<sj2){r=sj1;sj1=sj2;sj2=r;};//������һ�±��⸺������Ĳ���
                       cout<<sj1<<"-"<<sj2<<"="<<endl;
                     break;
                   case 2:
                      cout<<sj1<<"*"<<sj2<<"="<<endl;
                    break;
                   case 3:
                      cout<<sj1<<"/"<<sj2<<"="<<endl;
                    break;
				  case 4:
					   if(sj1>sj3){r=sj1;sj1=sj3;sj3=r;}
                       if(sj2>sj4){r=sj2;sj2=sj4;sj4=r;}
                    cout<<sj1<<"/"<<sj3<<"+"<<sj2<<"/"<<sj4<<"="<<endl;
					break;
				  case 5:
					    if(sj1>sj3){r=sj1;sj1=sj3;sj3=r;}
                        if(sj2>sj4){r=sj2;sj2=sj4;sj4=r;}
                    cout<<sj1<<"/"<<sj3<<"-"<<sj2<<"/"<<sj4<<"="<<endl;
					   break;
				   case 6:
					if(sj1>sj3){r=sj1;sj1=sj3;sj3=r;}
                    if(sj2>sj4){r=sj2;sj2=sj4;sj4=r;}
                    cout<<sj1<<"/"<<sj3<<"*"<<sj2<<"/"<<sj4<<"="<<endl;
					   break;
				   case 7:
					   if(sj1>sj3){r=sj1;sj1=sj3;sj3=r;}
                    if(sj2>sj4){r=sj2;sj2=sj4;sj4=r;}
                    cout<<sj1<<"/"<<sj3<<"/"<<sj2<<"/"<<sj4<<"="<<endl;
					   break;
                   default:
                   break;
				}


	}
}