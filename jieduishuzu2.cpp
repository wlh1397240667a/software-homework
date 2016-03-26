/*2016.3.24 weilihua fengyutong*/
#include <iostream>  
#include<ctime>
#define Num 10000
using namespace std;   
int DTGH_Sum(int a[],int n) //动态规划法求子段和函数
{
	int sum = 0;
	int *b = (int *) malloc(n * sizeof(int));	//动态为数组分配空间
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
	delete []b;		//释放内存
	return sum;
}
int main()   
{   int temp,b; 
    int sum=0; 
    int i; 
    int a1,a2; 
	int a[Num];
    int length=0;
	while (length==NULL||length == 0)//如果数组长度为空或零则请重新输入
     {
	  cout<<"请输入数组长度：";
      cin>>length;
     }
    cout<<"生成随机序列： "<<endl; 
	srand((unsigned)time(NULL)); 
    for(i=0;i<length;i++)//产生随机序列
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
    cout<<"此首尾相连的数组中最大子数组的和有以下几种可能："<<endl; 
    cout<<"第1种排列方式："<<endl; 
    for( i=0;i<length;i++) 
    {
		cout<<a[i]<<"  ";
	} 
    cout<<"最大子数组和为："<<DTGH_Sum(a,length)<<endl; 
    a1=DTGH_Sum(a,length); 
    for(b=1;b<length;b++) 
    { 
        temp=a[0]; 
    for(i=1;i<=length;i++) 
     {   
        a[i-1]=a[i]; //将第一个数变为最后一个数
              
     } 
       a[length-1]=temp; 
       cout<<"第"<<b+1<<"种排列方式："<<endl; 
       for( i=0;i<length;i++) 
       {
		   cout<<a[i]<<"  ";
	   } 
       cout<<"最大子数组和为："<<DTGH_Sum(a,length)<<endl; 
       if(DTGH_Sum(a,length)>=sum) 
       {
		   sum=DTGH_Sum(a,length);
	   } 
    }  
      a2=sum; 
      cout<<endl; 
      if(a1>=a2) 
      {
		  cout<<"综上，最大的子数组和为："<<a1<<endl;
	  } 
      else
      {
		  cout<<"综上，最大的子数组和为："<<a2<<endl;
	  }   
    return 0;   
} 
