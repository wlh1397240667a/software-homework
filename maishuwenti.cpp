/*2016.6.2 weilihua ��������*/
#include<iostream>
using namespace std;
int main()
{
	  int book_num=0;
	  int shangshu;//����
	  int yushu=0;//����
	  double ys_money;//�������ֶ�ӦǮ
	  double money;//��Ǯ��
      while (book_num==NULL||book_num == 0)//�������Ϊ�ջ���������������
      {
        cout<<"����������������";
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
	  cout<<"һ����"<<money<<"Ԫ"<<endl;
	  cout<<"����ƻ����£�"<<endl;
	 
	  if((yushu==8))//����������Ϊ8ʱ���⴦��
	  {
	  cout<<"�蹺��"<<shangshu*2<<"�׺ͺ������еĲ�ͬ4��"<<endl;
	  }
	  else if((yushu==5)||(yushu==0))//����Ϊ5��0ʱΪ����
	  {
		   cout<<"�蹺��"<<book_num/5<<"��"<<endl;
	  }
	  else if(yushu>5)//��������5ʱ������ų�8��
	  {
	  cout<<"�蹺��"<<book_num/5<<"�׺�"<<"һ���еĲ�ͬ"<<yushu%5<<"��"<<endl;
	  } 
	  else if(yushu>0)//����С��5������ų�0��
	  {
	  cout<<"�蹺��"<<shangshu*2<<"�׺�"<<"һ���еĲ�ͬ"<<yushu<<"��"<<endl;
	  }
    
		return 0;
}