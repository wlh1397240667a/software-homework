/*2016.3.24 weilihua fengyutong*/
#include <iostream>  
#include<ctime>
#define Num 10000
using namespace std;   
int DTGH_Sum(int a[],int n) //��̬�滮�����Ӷκͺ���
{
	int sum = 0;
	int *b = (int *) malloc(n * sizeof(int));	//��̬Ϊ�������ռ�
	b[0] = a[0];
	for(int i = 1; i < n; i++)
	{
		if(b[i-1] > 0)
			b[i] = b[i - 1] + a[i];
		else
			b[i] = a[i];
	}
	for(int j = 0; j < n; j++)
	{
		if(b[j] > sum)
			sum = b[j];
	}
	delete []b;		//�ͷ��ڴ�
	return sum;
}
int main()   
{   int temp,b; 
    int sum=0; 
    int i; 
    int a1,a2; 
	int a[Num];
    int length=0;
	while (length==NULL||length == 0)//������鳤��Ϊ�ջ���������������
     {
	  cout<<"���������鳤�ȣ�";
      cin>>length;
     }
    cout<<"����������У� "<<endl; 
	srand((unsigned)time(NULL)); 
    for(i=0;i<length;i++)//�����������
	{
		if(rand()%2==0)
		{
			a[i]=rand()%100;
		}
		else
		{
			a[i]=(-1)*rand()%100;
		}	
			cout<<a[i]<<" ";	
	}
	cout<<endl;    
    cout<<"����β���������������������ĺ������¼��ֿ��ܣ�"<<endl; 
    cout<<"��1�����з�ʽ��"<<endl; 
    for( i=0;i<length;i++) 
    {
		cout<<a[i]<<"  ";
	} 
    cout<<"����������Ϊ��"<<DTGH_Sum(a,length)<<endl; 
    a1=DTGH_Sum(a,length); 
    for(b=1;b<length;b++) 
    { 
        temp=a[0]; 
    for(i=1;i<=length;i++) 
     {   
        a[i-1]=a[i]; //����һ������Ϊ���һ����
              
     } 
       a[length-1]=temp; 
       cout<<"��"<<b+1<<"�����з�ʽ��"<<endl; 
       for( i=0;i<length;i++) 
       {
		   cout<<a[i]<<"  ";
	   } 
       cout<<"����������Ϊ��"<<DTGH_Sum(a,length)<<endl; 
       if(DTGH_Sum(a,length)>=sum) 
       {
		   sum=DTGH_Sum(a,length);
	   } 
    }  
      a2=sum; 
      cout<<endl; 
      if(a1>=a2) 
      {
		  cout<<"���ϣ������������Ϊ��"<<a1<<endl;
	  } 
      else
      {
		  cout<<"���ϣ������������Ϊ��"<<a2<<endl;
	  }   
    return 0;   
} 
