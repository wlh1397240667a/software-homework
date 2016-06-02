/*2016.6.2 weilihua 买书问题*/
#include<iostream>
using namespace std;
int main()
{
	  int book_num=0;
	  int shangshu;//商数
	  int yushu=0;//余数
	  double ys_money;//余数部分对应钱
	  double money;//总钱数
      while (book_num==NULL||book_num == 0)//如果书数为空或零则请重新输入
      {
        cout<<"请输入买书数量：";
        cin>>book_num;
       }
	  shangshu=book_num/10;
      yushu=book_num%10;
	  switch(yushu)
	  {
	  case 0:
		  ys_money=0;
	  break;
      case 1:
		   ys_money=8;
	  break;
	  case 2:
		   ys_money=15.2;
	  break;
	  case 3:
		   ys_money=21.6;
	  break;
	  case 4:
		   ys_money=25.6;
	  break;
	  case 5:
		   ys_money=30;
	  break;
	  case 6:
		   ys_money=38;
	  break;
	  case 7:
		   ys_money=45.2;
	  break;
	  case 8:
		   ys_money=51.2;
	  break;
	   case 9:
		   ys_money=55.6;
	  break;
	  }
	  money= shangshu*60+ ys_money;
	  cout<<"一共花"<<money<<"元"<<endl;
	  cout<<"购买计划如下："<<endl;
	 
	  if((yushu==8))//购买本数余数为8时特殊处理
	  {
	  cout<<"需购买"<<shangshu*2<<"套和和两套中的不同4本"<<endl;
	  }
	  else if((yushu==5)||(yushu==0))//余数为5或0时为整套
	  {
		   cout<<"需购买"<<book_num/5<<"套"<<endl;
	  }
	  else if(yushu>5)//余数大于5时情况（排除8）
	  {
	  cout<<"需购买"<<book_num/5<<"套和"<<"一套中的不同"<<yushu%5<<"本"<<endl;
	  } 
	  else if(yushu>0)//余数小于5情况（排除0）
	  {
	  cout<<"需购买"<<shangshu*2<<"套和"<<"一套中的不同"<<yushu<<"本"<<endl;
	  }
    
		return 0;
}