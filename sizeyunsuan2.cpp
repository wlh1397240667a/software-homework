/*2016.3.12.WeiLiHua��������*/
#include<iostream>
#include<ctime>
using namespace std;
void main()
{
	int sj1,sj2,sf=1,sj3,sj4,r;//��������������
	int Num;//�������
	char sfchose;//���ѡ��
	char yschose;//����ѡ��
	char jf;//�������ѡ��
	int qznum;//ȡֵ��Χ
	srand((unsigned)time(NULL)); //srand������������ϵͳʱ����Ϊʱ�����Ӳ��������
	cout<<"*****��ӭʹ���Զ�����ϵͳ*****"<<endl;
	cout<<"����������ݽ��г�ʼ�����ã�"<<endl;
	cout<<"�������ӡ������"<<endl;
	cin>>Num;
	cout<<"��ѡ���Ƿ��г˳���?��y/n��"<<endl;
	cin>>sfchose;
	cout<<"������һ��ֵȷ����ʽ����ֵȡֵ��Χ��"<<endl;
    cin>>qznum;
	cout<<"��������г��ָ����𣿣�y/n��";
    cin>>jf;

	if(sfchose=='y')
	{
		cout<<"��ѡ�������������?��y/n��"<<endl;
		cin>>yschose;
	}
		cout<<"********************************"<<endl;

	for(int i=0;i<Num;i++)
	{
            sj1=rand()%qznum;
			sj2=rand()%qznum;
			sj3=rand()%qznum;
			sj4=rand()%qznum;
			if(sfchose=='n')//�޳˳���
			{
			     sf=rand()%4; 		
			}
			if(sfchose=='y')//�г˳���
			{
				  sf=rand()%8; 
			}
			switch(sf)
				{		
					 case 0:
                       cout<<sj1<<"+"<<sj2<<"=     "<<endl;
                     break;
                    case 1:
                       if(jf=='n')//�޸���
					   {
						   if(sj1<sj2)
						   {
							  cout<<sj2<<"-"<<sj1<<"=    "<<endl;
						
						   }
						   else
						   {
							   cout<<sj1<<"-"<<sj2<<"=    "<<endl;
						   }
					    }
					   else
					   {
						    cout<<sj1<<"-"<<sj2<<"=    "<<endl;
						
					   } 
					   break;
				  case 2:
					   if(sj1>sj3)
					   {
						   r=sj1;
						   sj1=sj3;
						   sj3=r;
					   }
                       if(sj2>sj4)
					   {
						   r=sj2;
						   sj2=sj4;
						   sj4=r;
					   }
                     cout<<"("<<sj1<<"/"<<sj3<<")"<<"+"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
					break;
				  case 3:
					    if(sj1>sj3)
						{
							r=sj1;
							sj1=sj3;
							sj3=r;
						}
                        if(sj2>sj4)
						{
							r=sj2;
							sj2=sj4;
							sj4=r;
						}
						if(jf=='n')//��������޸���
						{
							if((sj1/sj3)<(sj2/sj4))
							{
								cout<<"("<<sj2<<"/"<<sj4<<")"<<"-"<<"("<<sj1<<"/"<<sj3<<")=     "<<endl;
							}
							else
							{
								cout<<"("<<sj1<<"/"<<sj3<<")"<<"-"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
							}
						}
						 else
						 {
							 cout<<"("<<sj1<<"/"<<sj3<<")"<<"-"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
						 }
					   break;
                   case 4:
                      cout<<sj1<<"*"<<sj2<<"="<<endl;
                    break;
                   case 5:
					   if(sj2==0)//��ĸΪ���򲻼�������
					   {
						   i=i-1;
						
					   }
					   else if(yschose=='n')//����û������
					   {
						   if(sj1%sj2==0)
						   {
							   cout<<sj1<<"/"<<sj2<<"="<<endl;
						
						   }
						   else 
						   {
							   i=i-1;
							 
						   }
					   }
					   else if(yschose=='y')//����������
					   {
						     if(sj1%sj2!=0)
						   {
							   cout<<sj1<<"/"<<sj2<<"="<<endl;
					
						   }
						   else 
						   {
							   i=i-1;
						
						   }

					   }
					   break;
				   case 6:
					if(sj1>sj3)
					{
						r=sj1;
						sj1=sj3;
						sj3=r;
					}
                    if(sj2>sj4)
					{
						r=sj2;
						sj2=sj4;
						sj4=r;
					}
                     cout<<"("<<sj1<<"/"<<sj3<<")"<<"*"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
					   break;
				   case 7:
					   if(sj1>sj3)
					   {
						   r=sj1;
						   sj1=sj3;
						   sj3=r;
					   }
                     if(sj2>sj4)
					 {
						r=sj2;
						sj2=sj4;
						sj4=r;
					 }
					   cout<<"("<<sj1<<"/"<<sj3<<")"<<"/"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
					   break;
                   default:
                   break;
				}
	}
}