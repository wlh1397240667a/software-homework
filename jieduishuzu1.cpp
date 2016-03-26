/*2016.3.22 weilihua fengyutong*/
#include<iostream>
#include<iostream>
#include<time.h>
using namespace std;
#define NUM 100000
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
{
	int length=0;
	 while (length==NULL||length == 0)//如果数组长度为空或零则请重新输入
     {
	  cout<<"请输入数组长度：";
      cin>>length;
     }
	int a[NUM];
	cout<<"输入数组元素："<<endl;
	for(int i=0;i<=(length-1);i++)
	{
		cin>>a[i];
	}
	cout<<"最大子段和：";
	cout<<DTGH_Sum(a,length)<<endl;
	return 0;
	
}