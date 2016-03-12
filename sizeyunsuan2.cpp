/*2016.3.12.WeiLiHua四则运算*/
#include<iostream>
#include<ctime>
using namespace std;
void main()
{
	int sj1,sj2,sf=1,sj3,sj4,r;//定义随机数及算符
	int Num;//题的数量
	char sfchose;//算符选择
	char yschose;//余数选择
	char jf;//减法结果选择
	int qznum;//取值范围
	srand((unsigned)time(NULL)); //srand函数是以现在系统时间作为时间种子产生随机数
	cout<<"*****欢迎使用自动出题系统*****"<<endl;
	cout<<"请对以下内容进行初始化设置："<<endl;
	cout<<"请输入打印题数："<<endl;
	cin>>Num;
	cout<<"请选择是否有乘除法?（y/n）"<<endl;
	cin>>sfchose;
	cout<<"请输入一个值确定算式中数值取值范围："<<endl;
    cin>>qznum;
	cout<<"减法结果中出现负数吗？（y/n）";
    cin>>jf;

	if(sfchose=='y')
	{
		cout<<"请选择除法有无余数?（y/n）"<<endl;
		cin>>yschose;
	}
		cout<<"********************************"<<endl;

	for(int i=0;i<Num;i++)
	{
            sj1=rand()%qznum;
			sj2=rand()%qznum;
			sj3=rand()%qznum;
			sj4=rand()%qznum;
			if(sfchose=='n')//无乘除法
			{
			     sf=rand()%4; 		
			}
			if(sfchose=='y')//有乘除法
			{
				  sf=rand()%8; 
			}
			switch(sf)
				{		
					 case 0:
                       cout<<sj1<<"+"<<sj2<<"=     "<<endl;
                     break;
                    case 1:
                       if(jf=='n')//无负数
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
						if(jf=='n')//减法结果无负数
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
					   if(sj2==0)//分母为零则不计入总数
					   {
						   i=i-1;
						
					   }
					   else if(yschose=='n')//除法没有余数
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
					   else if(yschose=='y')//除法有余数
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